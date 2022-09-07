<?php
	// Get session
	session_start();
	// Unset session vars
	session_unset();
	// Close session, go to index page
	if (session_destroy()) {
		header("Location: index.php");
	}
?>
