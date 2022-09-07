<?php
	// Data of session
	session_start();
	$login = NULL;
	if (isset($_SESSION['login'])) {
		$login = $_SESSION['login']; 
	}
	$curentDirectory = NULL;
	if (isset($_SESSION['curentDirectory'])) {
		$curentDirectory = $_SESSION['curentDirectory'];
	}
	$baseDirectory = NULL;
	if (isset($_SESSION['baseDirectory'])) {
		$baseDirectory = $_SESSION['baseDirectory'];
	}
	// Protect page
	if ($login == NULL){
		header("Location: logout.php");
	}
?>