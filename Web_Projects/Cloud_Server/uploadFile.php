<?php
	// Test if user is connected
    include_once("checkPage.php");

    // Actual path
    $target_dir = $baseDirectory .  $curentDirectory . "/";

    $target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
    $uploadOk = 1;
    $imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));
    $errors = "";

    // Check if image file is a actual image or fake image
    if(isset($_POST["submit"])) {
        $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
        if($check != false) {
            $errors .= "File is an image - " . $check["mime"] . ".";
            $uploadOk = 0;
        }
    }

    // Check if file already exists
    if (file_exists($target_file)) {
        $errors .= "Sorry, file already exists.";
        $uploadOk = 0;
    }

    // Check file size
    if ($_FILES["fileToUpload"]["size"] > 500000) {
        $errors .= "Sorry, your file is too large.";
        $uploadOk = 0;
    }

    // Check if $uploadOk is set to 0 by an error
    if ($uploadOk == 0)
        $errors .= "Sorry, your file was not uploaded ";
    else {
        if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file))
            header("Location: home.php");
        else
            $errors .= "Sorry, there was an error uploading your file.";
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
                <h2><?php echo $errors;?></h2>
                <p>Cliquer la pour revenir au <a href='home.php'>home</a></p>
            </section>
            
            <footer>
                <p>Cliquer la pour vous <a href='logout.php'>déconecter</a></p>
            </footer>
        </div>
    </body>
</html>