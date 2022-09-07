<?php
	// Data of session
	session_start();
	$login = NULL;
	if (isset($_SESSION['login'])) 
		$login = $_SESSION['login'];
	// Protect page
	if ($login == NULL) 
		header("Location: logout.php");
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
		
		<meta name="keywords" content="html5, css3, responsive, site template, website template" />

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
				<h2>Bienvenue <?php echo $login;?></h2>
				<article>
					<p>
						<a class="goBack"><img src="./medias/goBack2.png"/></a>
					</p>
					<p class="addDirectory">
						<a><img src="./medias/addDirectory.png"/></a>
					</p>
					<p>
						<img src='./medias/dir-open.png'/>
						<spam>
							<?php echo  $_SESSION['curentDirectory'];?>
						</spam>
					</p>
					<table>
						<?php
							include_once("listFiles.php");
							echo getFiles();
						?>
					</table>
					<input class = "nameDirec" type = 'text' name = 'nameDirectory' placeholder = 'Name Directory' pattern = '[a-z]{3,20}' title = '3 à 20 caractères minuscule' maxlength = '20'>
					<input class = "submit" type="submit" value="OK" name="submit">
				</article>
			</section>

			<aside>
				<h2>Uploader votre fichier</h2>
				<form action="uploadFile.php" method="post" enctype="multipart/form-data">
					<input class = "upFile" type="file" name="fileToUpload" id="fileToUpload"/>
					<input class = "upFile" type="submit" value="Upload Image" name="submit"/>
				</form>
			</aside>
			
			<footer>
				<p>Cliquer la pour vous <a href='logout.php'>déconecter</a></p>
			</footer>
		</div>
	</body>
</html>
