$(document).ready(function(){
//==============================================================================

/*==============================================================================
	jQuery events
==============================================================================*/

	// Ajax polling every 1s
	window.setInterval(getLocation, 1000);
    window.setInterval(sendAjax, 60000, "updateStatut.php");

/*==============================================================================
    Location functions
==============================================================================*/
    // Get location if possible
    function getLocation() {
        // Check navigator supports geolocation
      if (navigator.geolocation) {
          navigator.geolocation.getCurrentPosition(processLocation);
      } else {
        alert("Geolocation not supported!");
      }
    }
    // Get localisation
    function processLocation(location){
        var posX= location.coords.latitude;
        var posY= location.coords.longitude;
        window.ondevicemotion = function(event) {
            accelerationX=event.accelerationIncludingGravity.x;
            accelerationY=event.accelerationIncludingGravity.y;
            accelerationZ=event.accelerationIncludingGravity.z;
        }
        sendAjax("dataAjax.php", {posX: posX, posY: posY, accelerationX: accelerationX, accelerationY: accelerationY, accelerationZ: accelerationZ});
    }

/*==============================================================================
	AJAX functions
==============================================================================*/

	// General function sending JSON data to server
	function sendAjax(serverUrl, jsonData) {
		serializedData = JSON.stringify(jsonData);
		jQuery.ajax({type: 'POST', url: serverUrl, dataType: 'json', data: "data=" + serializedData,
			success: function(data) {
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
				} else if (val.insert == "append") {
					jQuery(val.target).append(val.html);
				} else {
					jQuery(val.target).html(val.html);
				}
			}
			// Reload page
			else if (val.action == "reloadPage") {
				location.reload();
			}
            //Rotate direction image 
            else if (defined(val.css)){
                    $('img').each(function() {
                        var deg = val.css;
                        var rotate = 'rotate(' + deg + 'deg)';
                        $(this).css({
                            '-webkit-transform': rotate,
                            '-moz-transform': rotate,
                            '-o-transform': rotate,
                            '-ms-transform': rotate,
                            'transform': rotate
                        });
                    });
            }
		}
	}

	// --- Test whether a variable is defined or not
	function defined(myVar) {
		return (typeof myVar != 'undefined');
	}

//==============================================================================
});
