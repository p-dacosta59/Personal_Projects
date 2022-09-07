<?php
	// Test if user is connected
    include_once("checkPage.php");
    $name = NULL;
    // Data from client
    $name = $_GET['name'];
    $target_file = "up/" . $curentDirectory . "/" . $name;
    if (!file_exists($target_file)) {
        $errors =  "Sorry, file don't exists.";
    }
    else{
        header("Location: " . $target_file);
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
                <h2>
                <?php echo $errors;?></h2>
                <p>Cliquer la pour revenir au <a href='home.php'>home</a></p>
            </section>

            <footer>
              <p>Cliquer la pour vous <a href='logout.php'>déconecter</a></p>
          </footer>
        </div>
    </body>
</html>