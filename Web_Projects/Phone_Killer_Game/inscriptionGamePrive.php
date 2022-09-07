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
        header("Location: logout.php");
    }
?>
<!DOCTYPE html>

<html>
    <!-- Head -->
    <head>
        <!-- CSS files -->
        <link rel='stylesheet' type='text/css' href='./css/web.css' media='screen' />
        <link rel='stylesheet' type='text/css' href='./css/01_mobile.css' media='screen' />
        <link rel='stylesheet' type='text/css' href='./css/02_fonts.css' media='screen' />

        <!-- JS files -->
        <script type='text/javascript' src='./js/jquery-3.5.1.min.js'></script>
        <script type='text/javascript' src='./js/ajax.js'></script>
        <script type='text/javascript' src='./js/web.js'></script>

        <!-- UTF8 encoding -->
        <meta charset='UTF-8'>

        <!-- Prevent from zooming -->
        <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1, user-scalable=0,  shrink-to-fit=no">

        <!-- Icon -->
        <link rel='icon' type='image/png' href='./images/favicon.png' />

        <!-- Title -->
        <title>Phone Killer</title>
    </head>

    <!-- Body -->
    <body>
        <!-- Wrapper -->
        <div class='wrapper'>
            <header>
                <h1>Phone killer</h1>
            </header>
            <section>
                <h2>Creer votre propre partie</h2>
                    <?php
                        // Open DB
                        $mesage = "";
                        include_once("dbConfig.php");
                        $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
                        $mysqli->set_charset("utf8");
                        // Query : select game information
                        $query = "SELECT * FROM game WHERE idGame=$idGame;";
                        $result = $mysqli->query($query);
                        // Query result
                        while ($row = $result->fetch_assoc()) {
                            echo "<p> La partie '" . $row['nomGame'] . "' : " . $row['idGame'] . " cette game a été crée par " . $row['createurGame'] . " avec " . $row['nbJoueur'] . " joeur en ligne. Cette partie est " . $row['statut'] . "</p>";
                        }
                    ?>
                <form action='checkGame.php' method='post'>
                    <?php
                        echo"<p><input type='hidden' name='idGame' placeholder='ID de votre partie' pattern='[0-9]{1,3}' title='1 a 3 caractére alphanumérique' value ='$idGame'/></p>";
                    ?>
                    <p><input type='password' name='pwdGame' placeholder='Mot de passe de cette partie' pattern='[a-zA-Z0-9]{3,20}' title='3 à 20 caractères alphanumérique' maxlength='20' autofocus/></p>
                    <input type='submit' value='OK' />
                </form>
            </section>
            <footer>
                <p>Cliquer la pour vous <a href='logout.php'>déconecter</a></p>
            </footer>
        </div>
    </body>
</html>
