<?php
	// Test if user is connected
	include_once("checkPage.php");
	// Data from client (filtered ajax)
	if (isset($_POST['data'])) {
		$data = json_decode($_POST['data'], true);
	}
	$addDirectory = NULL;
	if (preg_match("/^.{0,100}$/", $data['newDirectory'])) {
		$addDirectory = $data['newDirectory'];
	}
	$dropDirectory = NULL;
	if (preg_match("/^.{0,100}$/", $data['dropDirectory'])) {
		$dropDirectory = $data['dropDirectory'];
	}
	$return = NULL;
	// Create a directory
	if($addDirectory){
		$nameDirectory = NULL;
		if (preg_match("/^.{0,100}$/", $data['name'])) {
			$nameDirectory = $data['name'];
		}
		// Directory path
		$directory = $baseDirectory . $curentDirectory . "/" . $nameDirectory;
		// If directory don't exits create it
		if(!is_dir($directory)){
			mkdir($directory);
		}
		else{ 
			$return = "<p class = 'red'>Ne peut pas être crée car " . $nameDirectory . " existe déja</p>";
		}
	}
	// Drop directory
	else if($dropDirectory){
		$nameDirectory = NULL;
		if (preg_match("/^.{0,100}$/", $data['name'])) {
			$nameDirectory = $data['name'];
		}
		// Directory path
		$directory = $baseDirectory . $curentDirectory . "/" . $nameDirectory;
		// Check if directory exist
		if(is_dir($directory)){
			if(!rmdir($directory)){
				$return = "<p class='red'>Ne réusi pas à le suprimer" . $nameDirectory . "</p>";
			}
		}else{
			if(!unlink($directory)){
				$return = "<p class = 'red'>Ne réusi pas à le suprimer " . $nameDirectory . "</p>";
			}
		}
	}
	// If error
	if($return) 
		$jsonArray = array("target"=>"section article .submit", "html" => $return, "insert" => "after");
	else 
		$jsonArray = array("action" => "reloadPage");

	// Data to client (merge and send)
	$json = array();
	$json[] = $jsonArray;
	echo json_encode($json);
?>