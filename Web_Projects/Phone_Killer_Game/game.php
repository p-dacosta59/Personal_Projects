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
    if ($login == NULL && $idGame == NULL) {
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
                <h2>Bienvenue dans votre propre partie</h2>
                <article>
                    <?php
                        // Open DB
                        include_once("dbConfig.php");
                        $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
                        $mysqli->set_charset("utf8");
                        //Escape DATA
                        $login = $mysqli->real_escape_string($login);
                        $idGame = $mysqli->real_escape_string($idGame);
                        //Query Select player data
                        $query = "SELECT * FROM joueur WHERE login='$login';";
                        $result = $mysqli->query($query);
                        // Query result
                        while ($row = $result->fetch_assoc()){
                            $cible = $row['cible'];
                            $statue = $row['statut'];
                        }
                        $result->close();
                        // Query select target information
                        $query = "SELECT * FROM joueur WHERE id=$cible;";
                        $result = $mysqli->query($query);
                        // Query result
                        while ($row = $result->fetch_assoc()){
                            $statueCible = $row['statut'];
                        }
                        $result->close();
                        // If player and target was alive
                        if($statue == "connecte" && $statueCible != "deconnecte" && $statueCible != "expulse"){
                            $query = "SELECT * FROM joueur WHERE id=$cible;";
                            $result = $mysqli->query($query);
                            // Query result
                            while ($row = $result->fetch_assoc()){
                                echo "<p>Votre cible est '" . $row['nomGameur'] . "'</p>";
                            }
                            $result->close();
                            echo "<p class ='distance'></p>
                            <img class='rotate90' src='./images/fleche.png'/>";
                        }else if($statue == "killed"){
                            // If player is dead
                            echo "<p>Il s'agit de la fin pour vous car vous etes mort</p>";
                        }else if($statue == "sansJoueur"){
                            // If player don't have target
                            header("Location: inscriptionGame.php?idGame=$idGame");
                        }else if ($statueCible == "deconnecte"){
                            //  If target disconnected
                            echo "<p>Votre cible c'est déconnecter</p>
                            <p>Cliquer la pour obtenir une nouvelle <a href='inscriptionGame.php?idGame=$idGame'>cible</a></p>";
                        }else if($statueCible == "expulse"){
                            // Else if I don't have target
                            echo "<p>Votre cible a été expulser</p>
                            <p>Cliquer la pour obtenir une nouvelle <a href='inscriptionGame.php?idGame=$idGame'>cible</a></p>";
                        }
                        // Query select info sur la partie
                        $query = "SELECT * FROM game WHERE idGame='$idGame';";
                        $result = $mysqli->query($query);
                        //     Query result
                        while ($row = $result->fetch_assoc()){
                            $createur = $row['createurGame'];
                        }
                        $result->close();
                        if ($login == $createur){
                            // If I created this game
                            echo "</article><h2>Les joueur connectés a votre partie</h2><article>";
                            // Query select info sur les joueur de la partie
                            $query = "SELECT * FROM joueur WHERE partieEnCour='$idGame';";
                            $result = $mysqli->query($query);
                            //     Query result
                            while ($row = $result->fetch_assoc()){
                                echo "<p>Le joueur n°" . $row['id'] . " qui est '" . $row['nomGameur'] . "', il est pour l'instant " . $row['statut'] . ". Cliquer la pour <a href='logout.php?loginDeco=" . $row['login'] . "'>l'expulser</a></p>";
                            }
                            $result->close();
                            echo "<p>Cliquer la si vous souhaiter <a href='deleteGame.php'>détruire</a> cette partie.</p>";
                        }
                    ?>
                </article>
            </section>
            <footer>
                <p>Merci de vous <a href='logout.php'>déconecter</a> avant de quitter.</p>
            </footer>
		</div>
	</body>
</html>
