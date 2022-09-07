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
    $idGame = NULL;
    if (preg_match("/^[0-9]{0,20}$/", $_GET['idGame'])) {
        $idGame = $_GET['idGame'];
    }
    if ($idGame == NULL) {
        // Redirection
        header("Location: accueil.php");
    }
    // Open DB
    include_once("dbConfig.php");
    $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
    $mysqli->set_charset("utf8");

    //Escape DATA
    $login = $mysqli->real_escape_string($login);
    $idGame = $mysqli->real_escape_string($idGame);

    // Query Select : Player avaible
    $query = "SELECT * FROM joueur WHERE partieEnCour=$idGame AND login != '$login' AND `joueur`.`statut` != 'killed';";
    $result = $mysqli->query($query);
    $numRows = $result->num_rows;
    $max=$numRows;
    $min=1;
    $cible = 0;
    $aleatoire = 0;
    $i=1;
    if($numRows%2 == 0 || $numRows==0){
        // If doesn't have player avaible
        $result->close();
        //Query : update
        $query = "UPDATE `joueur` SET `partieEnCour` = $idGame WHERE `joueur`.`login` = '$login';";
        $success = $mysqli->query($query);
        //Query : update
        $query = "UPDATE `joueur` SET `statut` = 'connecte' WHERE `joueur`.`login` = '$login';";
        $success2 = $mysqli->query($query);
        if ($success && $success2){
            // Redirect
            header("Location: attente.php?idGame=$idGame");
        }
    }else{
        // Select random target
        do{
            $aleatoire=rand($min,$max);
            // Query result
            while ($row = $result->fetch_assoc()){
                if($max == 1){
                    $cible = $row['id'];
                }else if($i == $aleatoire){
                    $cible = $row['id'];
                }
                $i++;
            }
            // Query Select : If player was avaible
            $query2 = "SELECT * FROM joueur WHERE cible = $cible AND login != '$login' AND `partieEnCour` = $idGame;";
            $result2 = $mysqli->query($query2);
            $numRows2 = $result2->num_rows;
            while ($row = $result2->fetch_assoc()){
            }
            $result2->close();
        }while($numRows2!=0 || $cible==0);
        $result->close();
        //Query : update
        $query = "UPDATE `joueur` SET `partieEnCour` = $idGame WHERE `joueur`.`login` = '$login';";
        $success2 = $mysqli->query($query);
        //Query : update
        $query = "UPDATE `joueur` SET `cible` = $cible WHERE `joueur`.`login` = '$login';";
        $success3 = $mysqli->query($query);
        //Query : update
        $query = "UPDATE `joueur` SET `statut` = 'connecte' WHERE `joueur`.`login` = '$login';";
        $success4 = $mysqli->query($query);
        // Close DB
        $mysqli->close();
        // Query success
        if ($success2 && $success3 && $success4){
            // If alrigth
            // Data for session
            session_start();
            $_SESSION['idGame'] = $idGame;
            // Redirection
            header("Location: game.php");
        }else {
            header("Location: accueil.php");
        }
    }
    ?>
