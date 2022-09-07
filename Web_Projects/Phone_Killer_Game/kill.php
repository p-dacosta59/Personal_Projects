<?php
	// Data of session
	session_start();
	$login = NULL;
	if (isset($_SESSION['login'])) {
		$login = $_SESSION['login'];
	}
	// Protect Page
	if ($login == NULL) {
		header("Location: logout.php");
	}

	// Ouverture DB
	include_once("dbConfig.php");
	$mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
	$mysqli->set_charset("utf8");

	$query = "SELECT * FROM joueur WHERE login='$login';";
	$result = $mysqli->query($query);
	// Query result
	while ($row = $result->fetch_assoc()){
		$cible = $row['cible'];
		$idJoueur = $row['id'];
	}
	// Get new target
	$query = "SELECT * FROM joueur WHERE id=$cible;";
	$result = $mysqli->query($query);
	// Query result
	while ($row = $result->fetch_assoc()){
		$newCible = $row['cible'];
	}
	//Query : update
	$query = "UPDATE `joueur` SET `nbKill` = nbKill + 1 WHERE `joueur`.`login` = '$login';";
	$success2 = $mysqli->query($query);
	$query = "UPDATE `joueur` SET `statut` = 'killed' WHERE `joueur`.`id` = '$cible';";
	$success3 = $mysqli->query($query);

	// Check if it isn't me
	if($newCible != $idJoueur){
		//Query : update
		$query = "UPDATE `joueur` SET `cible` = '$newCible' WHERE `joueur`.`login` = '$login';";
		$success = $mysqli->query($query);
	}else{
		//Query : update
		$query = "UPDATE `joueur` SET `statut` = 'sansJoueur' WHERE `joueur`.`login` = '$login';";
		$success = $mysqli->query($query);
	}
	// Close BD
	$mysqli->close();
	// Send Data
	$jsonArray = array("action"=> "reloadPage");
	$json = array();
	$json[] = $jsonArray;
	echo json_encode($json);
?>
