$(document).ready(function(){

//==============================================================================

/*==============================================================================
	jQuery events
==============================================================================*/

    // Option for ptivate game
    jQuery("body").on("change", "input[name='statut']", function() {
        jQuery("input[name='pwdGame']").toggle();
    });
    
    // Allinea
    jQuery("body").on("click", "h2", function() {
        jQuery("article").slideUp();
        jQuery(this).next().slideDown();
    });
    
//==============================================================================
});
