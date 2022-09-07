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
                <h2>Connexion</h2>
                <form action='checkindex.php' method='post'>
                    <input type='text' name='login' placeholder='Login' pattern='[a-z]{3,20}' title='3 à 20 caractères minuscule' maxlength='20'/>
                    <input type='password' name='pwd' placeholder='Mot de passe' pattern='[a-zA-Z0-9]{3,20}' title='3 à 20 caractères alphanumérique' maxlength='20'/>
                    <input type='submit' value='OK' />
                </form>
            </section>
            <footer>
                <p>Il s'agit de votre première connexion? Vous pouvez vous <a href='inscription.php'>inscrire</a></p>
            </footer>

		</div>
	</body>
</html>
