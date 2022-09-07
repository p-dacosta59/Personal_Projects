<?php
    
	// Reception session
	session_start();
    $login = NULL;
    if (isset($_SESSION['login'])) {
        $login = $_SESSION['login'];
    }
    $idGame = NULL;
    if (isset($_SESSION['idGame'])) {
        $idGame = $_SESSION['idGame'];
    }
    // Protect Page
    if ($login == NULL || $idGame == NULL) {
      header("Location: logout.php");
    }
    // Open DB
    include_once("dbConfig.php");
    $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
    $mysqli->set_charset("utf8");
    //Escape DATA
    $login = $mysqli->real_escape_string($login);
    $idGame = $mysqli->real_escape_string($idGame);
    // Select the game
    $query = "SELECT * FROM joueur WHERE partieEnCour='$idGame';";
    $result = $mysqli->query($query);
    // Query result
    while ($row = $result->fetch_assoc()){
        // Query : update
        $query = "UPDATE `joueur` SET `cible` = 0 WHERE `joueur`.`login` = '" . $row['login'] . "';";
        $success1 = $mysqli->query($query);
        $query = "UPDATE `joueur` SET `statut` = 'deconnecte' WHERE `joueur`.`login` = '" . $row['login'] . "';";
        $success2 = $mysqli->query($query);
        $query = "UPDATE `joueur` SET `partieEnCour` = 0 WHERE `joueur`.`login` = '" . $row['login'] . "';";
        $success3 = $mysqli->query($query);
        $query = "UPDATE `joueur` SET `nbKill` = 0 WHERE `joueur`.`login` = '" . $row['login'] . "';";
        $success4 = $mysqli->query($query);
    }
    $result->close();

    // Query : delete la partie
    $query = "DELETE FROM game WHERE idGame = $idGame;";
    $success = $mysqli->query($query);
    // Query success
    if ($success) {
        header("Location: logout.php");
    }
?>
