$(document).ready(function(){
//==============================================================================

/*==============================================================================
	jQuery events
==============================================================================*/

	// Event to go in a directory
	jQuery("body").on("click", ".dir", function(key) {
		var data = "/" + jQuery(this).html();
		sendAjax("ajaxPage.php", {data: data});
	});	
	// Event to send 
	jQuery("body").on("click", ".submit", function(key) {
		var data = jQuery(this).prev().val();
		sendAjax("ajaxPageModify.php", {newDirectory: true, name: data});
	});
	// Event to go back
	jQuery("body").on("click", ".goBack", function(key) {
		sendAjax("ajaxPage.php", {goBack: true});
	});
	// Event to delete
	jQuery("body").on("click", ".trash", function(key) {
		var data = jQuery(this).parent().prev().children("a").html();
		sendAjax("ajaxPageModify.php", {dropDirectory: true, name: data});
	});

/*==============================================================================
	AJAX functions
==============================================================================*/

	// General function sending JSON data to server
	function sendAjax(serverUrl, jsonData) {
		serializedData = JSON.stringify(jsonData);
		jQuery.ajax({type: 'POST', url: serverUrl, dataType: 'json', data: "data=" + serializedData,success: function(data) {
				displayAjax(data);
			}
		});
	}

	// --- General function displaying JSON data from server
	// Syntax from server : [{target:".htmlClass", html:"html"}, {target:"htmlElement", html:"html", insert:"append"}, {action:"reloadPage"}]
	function displayAjax(data) {
		for (var val of data) {
			// Insert data into HTML (insert or replace)
			if (defined(val.target) && defined(val.html)) {
			if (val.insert == "prepend") {
					jQuery(val.target).prepend(val.html);
				}else if (val.insert == "append") {
					jQuery(val.target).append(val.html);
				}else if(val.insert == "after"){
					jQuery(val.target).after(val.html);
				}else if(val.insert == "before"){
					jQuery(val.target).before(val.html);
				}else {
					jQuery(val.target).html(val.html);
				}
			}
			// Reload page
			else if (val.action == "reloadPage") {
				location.reload();
			}
		}
	}

	// --- Test whether a variable is defined or not
	function defined(myVar) {
		if (typeof myVar != 'undefined') return true;
		return false;
	}
	
//==============================================================================
});
