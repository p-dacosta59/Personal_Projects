$(document).ready(function(){
//==============================================================================

	/*==============================================================================
		jQuery events
	==============================================================================*/
	// Event to add a directorty
	jQuery("body").on("click", ".addDirectory a", function(){
		jQuery(".submit").css("visibility", "visible");
		jQuery(".nameDirec").css("visibility", "visible").focus();

	});

//==============================================================================
});