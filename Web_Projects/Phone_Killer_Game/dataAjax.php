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
    // Protect Page
    if ($login == NULL) {
      header("Location: logout.php");
    }else if($idGame != NULL){
        // Data of user
        if (isset($_POST['data'])) {
            $data = json_decode($_POST['data'], true);
        }
        $posX = NULL;
        if (preg_match("/^.{0,100}$/", $data['posX'])) {
            $posX = $data['posX'];
        }
        $posY = NULL;
        if (preg_match("/^.{0,100}$/", $data['posY'])) {
            $posY = $data['posY'];
        }
        $accelerationX = NULL;
        if (preg_match("/^.{0,100}$/", $data['accelerationX'])) {
            $accelerationX = $data['accelerationX'];
        }
        $accelerationY = NULL;
        if (preg_match("/^.{0,100}$/", $data['accelerationY'])) {
            $accelerationY = $data['accelerationY'];
        }
        $accelerationZ = NULL;
        if (preg_match("/^.{0,100}$/", $data['accelerationZ'])) {
            $accelerationZ = $data['accelerationZ'];
        }
        // Open DB
        include_once("dbConfig.php");
        $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
        $mysqli->set_charset("utf8");
        //Escape DATA
        $login = $mysqli->real_escape_string($login);
        //Query select
        $query = "SELECT * FROM joueur WHERE login='$login';";
        $result = $mysqli->query($query);
        // Query result get gamer information
        while ($row = $result->fetch_assoc()){
            $cible = $row['cible'];
            $statue = $row['statut'];
        }
        //Query select get information of target
        $query = "SELECT * FROM joueur WHERE id=$cible;";
        $result = $mysqli->query($query);
        // Query result
        while ($row = $result->fetch_assoc()){
            $statueCible = $row['statut'];
        }
        $result->close();

        // If gamer is connected
        if($statue == "connecte" && $statueCible != "deconnecte" && $statueCible != "expulse"){
            if (posX != NULL && posY != NULL){
                //Escape DATA
                $posX = $mysqli->real_escape_string($posX);
                $posY = $mysqli->real_escape_string($posY);
                //Query : update position
                $query = "UPDATE `joueur` SET `posX` = $posX WHERE `joueur`.`login` = '$login';";
                $success = $mysqli->query($query);
                $query = "UPDATE `joueur` SET `posY` = $posY WHERE `joueur`.`login` = '$login';";
                $success2 = $mysqli->query($query);
                
                //Query select get information of target
                $query = "SELECT * FROM joueur WHERE id=$cible;";
                $result = $mysqli->query($query);
                // Query result
                while ($row = $result->fetch_assoc()){
                    $posCibleX = $row['posX'];
                    $posCibleY = $row['posY'];
                }
                $result->close();
                // Calculation distance between two player
                $distance = (sqrt(pow(($posX-($posCibleX)), 2) + pow(($posY-($posCibleY)), 2)) * 157249)/sqrt(2);
                // Calculation arrow tilt
                $inclinaison = atan(($posX-($posCibleX)) / ($posY-($posCibleY)));
                $inclinaison = $inclinaison*(180/pi());
                // If player is killing target
                if ($distance <= 20.0 && (abs($accelerationX) > 50 || abs($accelerationY) > 50 || abs($accelerationZ) > 50)){
                    header("Location: kill.php");
                }else if ($distance <= 20.0){
                    // If the player is at the right distance to kill him
                    // Data to client (merge and send)
                    $jsonArray = array("target"=>".distance", "html"=> "C'EST BOM SECOUER");
                    $jsonArray2 = array("target"=>".direction" "css"=>"$inclinaison");
                }else{
                    // Data to client (merge and send)
                    $jsonArray = array("target"=>".distance", "html"=> "Vous etes a $distance mètres de votre cible COURREZ!!!!");
                     $jsonArray2 = array("target"=>".direction", "css"=>"$inclinaison");
                }
                $json = array();
                $json[] = $jsonArray;
                $json[] = $jsonArray2;
                echo json_encode($json);
            }
        }else if (statut != "connecte") // If the player was dead or disconnected
        {
            $jsonArray = array("action"=>"reloadPage");
            $json = array();
            $json[] = $jsonArray;
            echo json_encode($json);
        }
    }
?>
