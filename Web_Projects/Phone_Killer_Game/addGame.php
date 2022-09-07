<?php
    // Data of session
    session_start();
    $login = NULL;
    if (isset($_SESSION['login'])) {
        $login = $_SESSION['login'];
    }
    // Protect Page
    if ($login == NULL) {
        // Redirect
        header("Location: logout.php");
    }
    // Data of user
    $nameGame = NULL;
    if (preg_match("/^[a-zA-Z0-9 ]{3,20}$/", $_POST['nameGame'])) {
        $nameGame = $_POST['nameGame'];
    }

    $pwdGame = NULL;
    if (preg_match("/^[a-zA-Z0-9]{6,20}$/", $_POST['pwdGame'])) {
        $pwdGame = $_POST['pwdGame'];
    }

    $nbJoueur = NULL;
    if ($_POST['nbJoueur']<100 && $_POST['nbJoueur']>3) {
        $nbJoueur = $_POST['nbJoueur'];
    }

    if ($nameGame == NULL || $nbJoueur == NULL){
        // Redirect
        header("Location: accueil.php");
    }else{
        // Open DB
        include_once("dbConfig.php");
        $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
        $mysqli->set_charset("utf8");

        //Escape Data
        $login = $mysqli->real_escape_string($login);
        $nameGame = $mysqli->real_escape_string($nameGame);
        $nbJoueur = $mysqli->real_escape_string($nbJoueur);

        // If the game is private
        if($pwdGame != NULL && $nameGame != NULL){
            // Hash pwd (64 char hash)
            $salt = "dK2mqlOs4dUibu8qHsmiOm6AqZs5DdkGN4KvghM3dqkfN5Dhqdm7hSFG8Kgv9qmOOH5fsuG4Nvf98wGfD7YTdi03mLvXxzT29t7u";
            // Define salt (length=100 for 64 chars hash)
            $pwdGame = hash("sha256", $pwdGame . $salt);
            //Query : insert
            $query = "INSERT INTO `game` (`nomGame`, `idGame`, `nbJoueur`, `createurGame`, `statut`, `pwdGame`, `nbJoueurMax`) VALUES ('$nameGame', NULL, 1, '$login', 'privée', '$pwdGame', $nbJoueur);";
        }
        // If the games is public
        else{
            //Query : insert
            $query = "INSERT INTO `game` (`nomGame`, `idGame`, `nbJoueur`, `createurGame`, `statut`, `pwdGame`, `nbJoueurMax`) VALUES ('$nameGame', NULL, 1, '$login', 'publique', '', $nbJoueur);";
        }
        $success = $mysqli->query($query);
        // Query success
        // If don't have problem
        if ($success){
            // Redirect
            $lastInsertedId = $mysqli->insert_id;
            header("Location: inscriptionGame.php?idGame=$lastInsertedId");
        }else{
            echo "Une erreur est survenue. Veillez recomencer";
        }
        // Close DB
        $mysqli->close();
    }
?>