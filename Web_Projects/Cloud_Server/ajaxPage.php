<?php
	// Test if user is connected
	include_once("checkPage.php");
	// Data from client (filtered ajax)
	if (isset($_POST['data'])) $data = json_decode($_POST['data'], true);
	$directory = NULL;
	if (preg_match("/^.{0,100}$/", $data['data'])) {
		$directory = $data['data'];
		$directory = $curentDirectory . $directory;
	}
	$goBack = NULL;
	if (preg_match("/^.{0,100}$/", $data['goBack'])) 
		$goBack = $data['goBack'];
	if($goBack && $curentDirectory != $login) 
		$directory = strstr($curentDirectory, "/", true);
	
	// Get file of a directory 
	$_SESSION['curentDirectory'] = $directory;
	include_once("listFiles.php");
	$dataToSend = NULL;
	$dataToSend = getFiles();

	// Data to client (build JSON)
	$jsonArrayDirectory = array("target"=>"article p spam", "html" => $directory);
	$jsonArrayFiles = array("target"=>"table", "html" => $dataToSend);

	// Data to client (merge and send)
	$json = array();
	$json[] = $jsonArrayDirectory;
	$json[] = $jsonArrayFiles;
	echo json_encode($json);
?>
