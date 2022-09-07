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
		<link rel='icon' type='image/png' href='./images/favicon.png' />

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
                <h2>Création de votre compte</h2>
                <form action='checkInscription.php' method='post'>
                    <input type='text' name='login' placeholder='Vote login' pattern='[a-z]{3,20}' title='3 à 20 caractères minuscule' maxlength='20'/>
                    <input type='password' name='pwd' placeholder='Votre mot de passe' pattern='[a-zA-Z0-9]{6,20}' title='6 à 20 caractères alphanumériques' maxlength='20'/>
                    <input type='submit' value='OK' />
                </form>
            </section>

            <footer>
                <p> Retour à <a href='login.php'>l'accueil</a></p>
            </footer>
		</div>
	</body>
</html>
