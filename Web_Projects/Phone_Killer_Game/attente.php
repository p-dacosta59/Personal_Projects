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
        header("Location: accueil.php");
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
                <p>Il n'y as pas acces de joueur pour l'instant veillez patienter.</p>
                    <?php
                    echo "<p>Cliquer la pour <a href='inscriptionGame.php?idGame=$idGame'>recharger</a></p>";
                ?>
            </section>
            <footer>
                <p>Cliquer la pour vous <a href='logout.php'>déconecter</a></p>
            </footer>
		</div>
	</body>
</html>
