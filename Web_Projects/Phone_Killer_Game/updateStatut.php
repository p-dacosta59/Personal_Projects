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
    }else if($idGame !=NULL){
        // Open DB
        include_once("dbConfig.php");
        $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
        $mysqli->set_charset("utf8");
        //Escape DATA
        $login = $mysqli->real_escape_string($login);
        $idGame = $mysqli->real_escape_string($idGame);
        //Query Select game information
        $query = "SELECT * FROM game WHERE idGame='$idGame';";
        $result = $mysqli->query($query);
        // Query result
        while ($row = $result->fetch_assoc()){
            $createur = $row['createurGame'];
        }
        // Query : update
        $query = "UPDATE `joueur` SET `lastPollingDate` = NOW() WHERE `login` = '$login';";
        $success = $mysqli->query($query);
        if ($login == $createur){
            // Query Select informations of player disconnected
            $query = "SELECT * FROM joueur WHERE partieEnCour ='$idGame' AND TIMESTAMPDIFF(MINUTE, lastPollingDate, NOW()) > 5 AND statut != 'killed';";
            $result = $mysqli->query($query);
            //     Query result
            while ($row = $result->fetch_assoc()){
                $loginInnactif = $row['login'];
                //Query : update disconected player
                $query = "UPDATE `joueur` SET `statut` = 'innactif' WHERE `joueur`.`login` = '$loginInnactif';";
                $success = $mysqli->query($query);
            }
            header("Location: updateGame.php");
        }
        $mysqli->close();
    }
?>
