<?php
    // Data of session
    session_start();

    $login = NULL;
    if (isset($_SESSION['login'])) {
        $login = $_SESSION['login'];
    }
    $idGame = NULL;
    if (isset($_SESSION['idGame'])) {
        $idGame = $_SESSION['idGame'];
    }
    // Protect page access
    if ($login == NULL) {
        header("Location: logout.php");
    }
    // Open DB
    include_once("dbConfig.php");
    $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
    $mysqli->set_charset("utf8");
    // Escape DATA
    $login = $mysqli->real_escape_string($login);
    $idGame = $mysqli->real_escape_string($idGame);
    // Query Select info joueur
    $query = "SELECT * FROM joueur WHERE login='$login';";
    $result = $mysqli->query($query);
    // Query result
    while ($row = $result->fetch_assoc()){
        $cible = $row['cible'];
    }
    // Query Select game information
    $query = "SELECT * FROM game WHERE idGame=$idGame;";
    $result = $mysqli->query($query);
    $numRows = $result->num_rows;
    // Query : update
    $query = "UPDATE `game` SET `nbJoueur` = '$numRows' WHERE `game`.`idGame` = '$idGame';";
    $success = $mysqli->query($query);
    // Send Data
    $jsonArray = array("action"=>"reloadPage");
    $json = array();
    $json[] = $jsonArray;
    echo json_encode($json);
?>
