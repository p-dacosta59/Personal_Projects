<?php
    // Data of client
    $pwd = NULL;
    if (preg_match("/^[a-zA-Z0-9]{6,20}$/", $_POST['pwd'])) {
        $pwd = $_POST['pwd'];
    }
    $login = NULL;
   if (preg_match("/^[a-z]{3,20}$/", $_POST['login'])) {
       $login = $_POST['login'];
   }
   $error = FALSE;
    if ($login == NULL || $pwd == NULL){
        // Redirect
		$error = FALSE;
	}
	else{
		// Hash pwd (64 char hash)
		// Define salt (length=100 for 64 chars hash)
		$salt = "dK2mqlOs4dUibu8qHsmiOm6AqZs5DdkGN4KvghM3dqkfN5Dhqdm7hSFG8Kgv9qmOOH5fsuG4Nvf98wGfD7YTdi03mLvXxzT29t7u";
		$pwd = hash("sha256", $pwd . $salt);
		// Open DB
		include_once("dbConfig.php");
		$mysqli = new mysqli(DB_HOST, DB_LOGIN, DB_PWD, DB_NAME);
		$mysqli->set_charset("utf8");
		// Escape chars
		$login = $mysqli->real_escape_string($login);
		$pwd = $mysqli->real_escape_string($pwd);
		// Query : select
		$query = "SELECT * FROM data_client WHERE login = '$login' AND pwd = '$pwd';";
		$result = $mysqli->query($query);
		// Query result
		$numRows = $result->num_rows;
		$result->close();
		// Close DB
		$mysqli->close();
		//Check if good login
		if( $numRows == 1){
			// Data to session
			session_start();
			$_SESSION['login'] = $login;
			$_SESSION['curentDirectory'] = $login;
			$_SESSION['baseDirectory'] = "/Applications/MAMP/htdocs/serveurFichier/up/";
			// Redirect
			header("Location: home.php");
		}else{
			$error = TRUE;
		}
	}
?>

<!DOCTYPE html>

<html dir="ltr" lang="fr" xml:lang="fr">
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
		<meta charset='UTF-8'/>
		
		<!-- Prevent from zooming -->
		<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1, user-scalable=0,  shrink-to-fit=no"/>

		<!-- Icon -->
		<link rel='icon' type='image/png' href='./images/favicon.png'/>

		<!-- Title -->
		<title>Serveur Cloud</title>
	</head>

	<!-- Body -->
	<body>
		<!-- Wrapper -->
		<div class='wrapper'>
            <header>
                <h1>Serveur Cloud</h1>
            </header>

            <section>
                <h2>Connexion</h2>
				<?php 
					if($error) 
						echo "<p class = red>Error in login or pwd.</p>";
				?>
                <form action = 'login.php' method = 'post'>
                    <input type = 'text' name = 'login' placeholder = 'Login' pattern = '[a-z]{3,20}' title = '3 à 20 caractères minuscule' maxlength = '20' value = '<?php if($error) echo $login;?>'/>
                    <input type = 'password' name = 'pwd' placeholder = 'Mot de passe' pattern = '[a-zA-Z0-9]{6,20}' title = '6 à 20 caractères alphanumérique' maxlength = '20'/>
                    <input type = 'submit' value = 'OK' />
                </form>
            </section>
			
            <footer>
                <p>Il s'agit de votre première connexion? Vous pouvez vous <a href='inscription.php'>inscrire</a></p>
            </footer>
		</div>
	</body>
</html>
