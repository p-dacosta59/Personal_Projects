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
                <h2>Partie en cours</h2>
                <article>
                    <?php
                        // Open DB
                        include_once("dbConfig.php");
                        $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
                        $mysqli->set_charset("utf8");
                        // Query : select
                        $query = "SELECT * FROM game WHERE nbJoueur > 0 AND nbJoueurMax-nbJoueur>0 ORDER BY statut DESC;";
                        $result = $mysqli->query($query);
                        // Query result
                        while ($row = $result->fetch_assoc()) {
                            // Display public game avaible
                            if($row['statut']=="publique"){
                            echo "<p> La partie '" . $row['nomGame'] . "' : " . $row['idGame'] . " cette game a été crée par " . $row['createurGame'] . " avec " . $row['nbJoueur'] . " joueur en ligne. Cette partie est " . $row['statut'] . " <a href='inscriptionGame.php?idGame=" . $row['idGame'] . "'>rejoindre</a> </p>";
                            }
                            // Display private game avaible
                            else{
                                echo "<p> La partie '" . $row['nomGame'] . "' : " . $row['idGame'] . " cette game a été crée par " . $row['createurGame'] . " avec " . $row['nbJoueur'] . " joueur en ligne. Cette partie est " . $row['statut'] . " <a href='inscriptionGamePrive.php?idGame=" . $row['idGame'] . "'>rejoindre</a> </p>";
                        
                            }
                        }
                        $result->close();
                        $mysqli->close();
                    ?>
                </article>
                <h2>Creer votre propre partie</h2>
                <article>
                    <form action='addGame.php' method='post'>
                        <p><input type='text' name='nameGame' placeholder='Nom de votre partie' pattern='[a-zA-Z0-9 ]{3,20}' title='3 à 20 caractères minuscule' maxlength='20'/></p>
                        <p><input type='number' name='nbJoueur' placeholder='Nombre max de joueur' min="3" max="100"/></p>
                        <p><input class ='check' type='checkbox' name='statut' checked>Partie privée?</p>
                        <p><input type='password' name='pwdGame' placeholder='Mot de passe de votre partie' pattern='[a-zA-Z0-9]{3,20}' title='3 à 20 caractères alphanumérique' maxlength='20'/></p>
                        <input type='submit' value='OK' />
                    </form>
                </article>
            </section>
            <footer>
                <p>Cliquer la pour vous <a href='logout.php'>déconecter</a></p>
            </footer>
		</div>
	</body>
</html>