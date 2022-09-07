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
    // Data of user
    $idGame = NULL;
    if (preg_match("/^[0-9]{1,3}$/", $_POST['idGame'])) {
        $idGame = $_POST['idGame'];
    }

    $pwdGame = NULL;
    if (preg_match("/^[a-zA-Z0-9]{3,20}$/", $_POST['pwdGame'])) {
        $pwdGame = $_POST['pwdGame'];
    }

    // Protect Page
    if($idGame == NULL || $pwdGame ==NULL){
        header("Location: accueil.php");
    }else{
        // Hash pwd (64 char hash)
        $salt = "dK2mqlOs4dUibu8qHsmiOm6AqZs5DdkGN4KvghM3dqkfN5Dhqdm7hSFG8Kgv9qmOOH5fsuG4Nvf98wGfD7YTdi03mLvXxzT29t7u";
        // Define salt (length=100 for 64 chars hash)
        $pwdGame = hash("sha256", $pwdGame . $salt);

        // Open DB
        include_once("dbConfig.php");
        $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
        $mysqli->set_charset("utf8");

        // Escape chars
        $login = $mysqli->real_escape_string($login);
        // Query : select
        $query = "SELECT * FROM game WHERE idGame = $idGame AND pwdGame = '$pwdGame';";
        $result = $mysqli->query($query);
        $numRows = $result->num_rows;
        $result->close();

        // Close DB
        $mysqli->close();
        //Check if login exists
        if( $numRows == 1)
            // Redirect
            header("Location: inscriptionGame.php?idGame=$idGame");
        }else{
            // Redirect
            header("Location: accueil.php");
        }
    }
?>
