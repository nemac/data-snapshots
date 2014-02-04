function data_snapshots ($) {

    function make_img_url(dsmn,ptk,stk) {
        if (dsmn === "ghcntempm") {
            return "http://datasnapshots-images.nemac.com:8080/ghcntemp/monthly/620/" + ptk + "/ghcntempm--620--" + ptk + "-" + stk + ".png";
        }
        return "http://datasnapshots-images.nemac.com:8080/usdm/620/" + ptk + "/usdm--620--" + ptk + "-" + stk + ".png";
    }

    function set_url(dsmn, ptk, stk, theme) {
	if (window.history && window.history.replaceState) {
	    window.history.replaceState({}, "", dsmn + "-" + ptk + "-" + stk + "?theme=" + theme);
	}
    }

    function set_img(dsmn,ptk,stk) {
        $('.field-name-field-ds-disimg img').attr('src', make_img_url(dsmn,ptk,stk));
        $('div.dss-title').text(ptk + ' / ' + stk);

	set_url(dsmn, ptk, stk, $("#dss-theme-dropdown").val());
    }

    function set_annotation(html) {
	$(".group-footer").html(html);
    }

    function set_downloads(html) {
	var new_links = $(html).find("ul");
	$(".field-name-field-ds-dloads ul").replaceWith(new_links);
    }

    function set_permalink(html) {
	$(".field-name-data-snapshot-permalink .field-items .field-item").text(html);
    }

    function set_date_generated(html) {
	$(".field-name-field-ds-dtgen").replaceWith(html);
    }

    function set_primary_tabs(nid) {
	var re = /(\/node\/)(\d+)(\/\w+)/,
	    pattern = "$1" + nid + "$3",
	    $links = $(".tabs .primary a"),
	    $link,
	    href,
	    i;

	for (i = 0; i < $links.length; i++) {
	    $link = $($links[i]);
	    href = $link.attr("href").replace(re, pattern);
	    $link.attr("href", href);
	}
    }

    function init_dropdowns() {
	var data_snapshots = Drupal.settings.data_snapshots,
	    dsmn = data_snapshots.snapshots.dsmn,
	    themes = data_snapshots.themes,
	    data_sources = data_snapshots.datasources,
	    $theme_dropdown = $("#dss-theme-dropdown"),
	    $data_source_dropdown = $("#dss-data-source-dropdown"),
	    init_theme = data_snapshots.init_theme,
	    foundTheme = false,
	    theme, i;

	if (init_theme && themes.indexOf(init_theme) !== -1 && data_sources[init_theme].length > 0) {
	    for (i = 0; i < data_sources[init_theme].length; i++) {
		if (data_sources[init_theme][i].mname === dsmn) {
		    foundTheme = true;
		}
	    }
	}

	for (i = 0; i < themes.length; i++) {
	    theme = themes[i];
	    if (data_sources[theme].length === 0) {
		continue;
	    }
	    $theme_dropdown.append($("<option>", { value: theme })
				   .text(theme));

	    // TODO: Add parsing of URL to determine proper default theme
	    // TODO: Add polyfill of indexOf
	    if (!foundTheme) {
		var j;

		for (j = 0; j < data_sources[theme].length; j++) {
		    if (data_sources[theme][j].mname === dsmn) {
			init_theme = theme;
			foundTheme = true;
		    }
		}
	    }
	}


	for (i = 0; i < data_sources[init_theme].length; i++) {
	    $data_source_dropdown.append($("<option>", { value: data_sources[init_theme][i].mname })
					 .text(data_sources[init_theme][i].oname));
	}

	$theme_dropdown.val(init_theme);
	$data_source_dropdown.val(dsmn);
    }

    function switch_data_source_content(node) {
	var $evergreen_question = $(".field-name-field-ds-dsds-evergreen .field-label"),
	    $evergreen_answer = $(".field-name-field-ds-dsds-evergreen .field-item"),
	    $read_more_link = $(".field-name-field-ds-dsds-evergreen .dss-question-read-more a");

	$evergreen_question.text(node.field_dssds_framing_question.und[0].value);
	$evergreen_answer.html(node.field_dssds_english_descript.und[0].safe_value);
	$read_more_link.attr("href", "/node/" + node.nid);
    };

    function switchDataSnapshotContent(dsmn, ptk, stk) {
	$.ajax({
	    type : "POST",
	    url  : "/data-snapshots/snapshots/ajax",
	    data : {
		 "type" : "snapshot",
		 "dsmn" : dsmn,
		 "ptk"  : ptk,
		 "stk"  : stk
	       }
	})
	.done(function (result) {
	    set_annotation(result.body_html);
	    set_downloads(result.download_html);
	    set_permalink(result.permalink_html);
	    set_date_generated(result.date_html);
	    set_primary_tabs(result.nid);
	});
    }

    $('document').ready(function() {
	var snapshots = Drupal.settings.data_snapshots.snapshots,
            dsmn = snapshots.dsmn,
	    ptks = snapshots.p,
            current_ptk_index = ptks.indexOf(snapshots.init_ptk),
	    stks = snapshots.s[ptks[current_ptk_index]],
            current_stk_index = snapshots.s[snapshots.init_ptk].indexOf(snapshots.init_stk);

        function hideStuff() {
            $('.group-footer').animate({'opacity' : 0.0}, 200);
        }

        function showStuff() {
            $('.group-footer').animate({'opacity' : 1.0}, 200);
        }

	function config_ptk_slider() {
            $('#dss-yearslider').slider({
                'min' : 0,
                'max' : ptks.length-1,
                'value' : current_ptk_index,
                'change' : function(event, ui) {
                    current_ptk_index = ui.value;
                    stks = Drupal.settings.data_snapshots.snapshots.s[ptks[current_ptk_index]];
                    set_img(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
                    config_stk_slider();
                },
                'slide' : function(event, ui) {
                    current_ptk_index = ui.value;
                    stks = Drupal.settings.data_snapshots.snapshots.s[ptks[current_ptk_index]];
                    set_img(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
                },
                'start' : function(event, ui) {
                    hideStuff();
                },
                'stop' : function(event, ui) {
                    showStuff();
		    switchDataSnapshotContent(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
                }
            });
	};

        function config_stk_slider() {
            $('#dss-timeslider').slider({
                'min' : 0,
                'max' : stks.length-1,
                'value' : current_stk_index,
                'change' : function(event, ui) {
                    current_stk_index = ui.value;
                    set_img(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
                },
                'slide' : function(event, ui) {
                    current_stk_index = ui.value;
                    set_img(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
                },
                'start' : function(event, ui) {
                    hideStuff();
                },
                'stop' : function(event, ui) {
                    showStuff();
		    switchDataSnapshotContent(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
                }           
            });

        }

        config_ptk_slider();
        config_stk_slider();

	init_dropdowns();
	$('#dss-data-source-dropdown').on("change", data_source_dropdown_change);
	$('#dss-theme-dropdown').on("change", theme_dropdown_change);

	function theme_dropdown_change() {
	    var new_theme = $(this).val(),
		data_sources = Drupal.settings.data_snapshots.datasources[new_theme],
		$data_source_dropdown = $('#dss-data-source-dropdown'),
		i;

	    $data_source_dropdown.empty();

	    for (i = 0; i < data_sources.length; i++) {
		$data_source_dropdown.append($("<option>", { value: data_sources[i].mname })
					     .text(data_sources[i].oname));
	    }

	    set_url(dsmn, ptks[current_ptk_index], stks[current_stk_index], new_theme);
	}

	function data_source_dropdown_change() {
	    var new_dsmn = $(this).val();
	    $.ajax({
		type : "POST",
	        url  : "/data-snapshots/ajax",
		data : {
			 "current" : dsmn,
			 "new"     : new_dsmn,
			 "ptk"     : ptks[current_ptk_index],
			 "stk"     : stks[current_stk_index]
		       }
	    })
	    .done(function (msg) {
		var result = msg.callback,
		    dates = result.dates;
		dates.dsmn = new_dsmn;
		Drupal.settings.data_snapshots.snapshots = dates;

		current_ptk_index = dates.p.indexOf(result.ptk);
		current_stk_index = dates.s[result.ptk].indexOf(result.stk);
		ptks = dates.p;
		stks = dates.s[ptks[current_ptk_index]];

		dsmn = new_dsmn;

		set_img(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
		config_ptk_slider();
		config_stk_slider();

		switch_data_source_content(msg.node);
		switchDataSnapshotContent(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
	    });
	}
    });

}
