<?php

    // Data of user
    $login = NULL;
    if (preg_match("/^[a-z]{3,20}$/", $_POST['login'])) {
        $login = $_POST['login'];
    }
    $pwd = NULL;
    if (preg_match("/^[a-zA-Z0-9]{6,20}$/", $_POST['pwd'])) {
        $pwd = $_POST['pwd'];
    }
    $pseudo = NULL;
    if (preg_match("/^[a-zA-Z0-9]{6,20}$/", $_POST['pseudo'])) {
        $pseudo = $_POST['pseudo'];
    }
    // Protect page
    if ($pseudo == NULL || $login == NULL || $pwd == NULL) {
        // Redirect
        header("Location: inscription.php");
    }else{
        // Hash pwd (64 char hash)
        $salt = "dK2mqlOs4dUibu8qHsmiOm6AqZs5DdkGN4KvghM3dqkfN5Dhqdm7hSFG8Kgv9qmOOH5fsuG4Nvf98wGfD7YTdi03mLvXxzT29t7u";
        // Define salt (length=100 for 64 chars hash)
        $pwd = hash("sha256", $pwd . $salt);

        // Open DB
        include_once("dbConfig.php");
        $mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
        $mysqli->set_charset("utf8");
        //Escape Date
        $login = $mysqli->real_escape_string($login);
        //Query : insert
        $query = "INSERT INTO `joueur` (`id`, `login`, `pwd`, `nomGameur`, `cible`, `partieEnCour`, `nbKill`, `posX`, `posY`, `statut`, `lastPollingDate`) VALUES (NULL, '$login', '$pwd', '$pseudo', NULL, NULL, NULL, NULL, NULL, NULL, NULL);";
        $success = $mysqli->query($query);
        // Query success
        if ($success){
            $lastInsertedId = $mysqli->insert_id;
        }
        // Close DB
        $mysqli->close();
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
		<script type='text/javascript' src='./js/jquery-2.0.3.min.js'></script>
		<script type='text/javascript' src='./js/web.js'></script>

		<!-- UTF8 encoding -->
		<meta charset='UTF-8'>

		<!-- Prevent from zooming -->
		<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1, user-scalable=0,  shrink-to-fit=no">

		<!-- Icon -->

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
                <h2>Nouveau compte</h2>
                <?php
                    // If client was added
                    if($success){
                            echo "<p>Votre conte '" . $login . "' a été créée avec succés. Notez bien votre mot de passe.</p>
                                <p>Vous etes la ". $lastInsertedId . "ieme personne a vous inscrire.</p>

                        </section>
                        <section>
                                <p>Vous pouvez maintenant vous connecter en allant à <a href='index.php'>l'accueil</a></p>";
                    }else{
                        echo "<p>Un conte avec le nom '" . $login . "' existe déjà. Merci d'essayer avec un autre login.</p>
                        </section>
                        <section>
                            <p> Pour réessayer, retourner à <a href='inscription.php'>la page de création</a></p>";
                    }
                ?>
            </section>    
		</div>
	</body>
</html>
