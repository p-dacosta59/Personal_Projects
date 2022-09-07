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

    // Data of user
    $loginD = NULL;
    if (preg_match("/^[a-z]{3,20}$/", $_GET['loginDeco'])) {
        $loginD = $_GET['loginDeco'];
    }
    // Open DB
    include_once("dbConfig.php");
    $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
    $mysqli->set_charset("utf8");
    // Escape data
    $loginD = $mysqli->real_escape_string($loginD);

    if($loginD == NULL){
        // If it not a player disconnected
        // Query : update
        $query = "UPDATE `joueur` SET `cible` = 0 WHERE `joueur`.`login` = '$login';";
        $success = $mysqli->query($query);
        $query = "UPDATE `joueur` SET `statut` = 'deconnecte' WHERE `joueur`.`login` = '$login';";
        $success2 = $mysqli->query($query);
        $query = "UPDATE `joueur` SET `partieEnCour` = 0 WHERE `joueur`.`login` = '$login';";
        $success3 = $mysqli->query($query);
        $query = "UPDATE `joueur` SET `nbKill` = 0 WHERE `joueur`.`login` = '$login';";
        $success4 = $mysqli->query($query);
        // Close DB
        $mysqli->close();
        // Unset session vars
        session_unset();

        // Close session, go to index page
        if (session_destroy()) {
            header("Location: index.php");
        }
    }
    // Delete other player of the game
    else{
        // Query : update
        $query = "UPDATE `joueur` SET `cible` = 0 WHERE `joueur`.`login` = '$loginD';";
        $success = $mysqli->query($query);
        $query = "UPDATE `joueur` SET `statut` = 'expulse' WHERE `joueur`.`login` = '$loginD';";
        $success2 = $mysqli->query($query);
        $query = "UPDATE `joueur` SET `partieEnCour` = 0 WHERE `joueur`.`login` = '$loginD';";
        $success3 = $mysqli->query($query);
        $query = "UPDATE `joueur` SET `nbKill` = 0 WHERE `joueur`.`login` = '$login';";
        $success4 = $mysqli->query($query);
        // Close DB
        $mysqli->close();
        header("Location: game.php");
    }
?>
