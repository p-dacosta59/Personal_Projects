<?php

    // Data of user
    $pwd = NULL;
    if (preg_match("/^[a-zA-Z0-9]{6,20}$/", $_POST['pwd'])) {
        $pwd = $_POST['pwd'];
    }
    $login = NULL;
   if (preg_match("/^[a-z]{3,20}$/", $_POST['login'])) {
       $login = $_POST['login'];
   }
    if ($login == NULL || $pwd == NULL){
        // Redirection
        header("Location: index.php");
    }
    // Hash pwd (64 char hash)
    $salt = "dK2mqlOs4dUibu8qHsmiOm6AqZs5DdkGN4KvghM3dqkfN5Dhqdm7hSFG8Kgv9qmOOH5fsuG4Nvf98wGfD7YTdi03mLvXxzT29t7u";
    // Define salt (length=100 for 64 chars hash)
    $pwd = hash("sha256", $pwd . $salt);
    // Open DB
    include_once("dbConfig.php");
    $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
    $mysqli->set_charset("utf8");

    // Escape chars
    $login = $mysqli->real_escape_string($login);

    // Query : select
    $query = "SELECT * FROM joueur WHERE login = '$login' AND pwd = '$pwd';";
    $result = $mysqli->query($query);
    $numRows = $result->num_rows;
    $result->close();

    // Close DB
    $mysqli->close();
    //Check if login is correct
    if( $numRows == 1){
        // Data to session
        session_start();
        $_SESSION['login'] = $login;
        // Redirect
        header("Location: accueil.php");
    }else{
        // Redirect
        header("Location: index.php");
    }
?>
