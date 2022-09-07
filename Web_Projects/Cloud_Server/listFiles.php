<?php
    function getFiles(){
        // Data of session
        session_start();
        $login = NULL;
        if (isset($_SESSION['login'])) {
            $login = $_SESSION['login']; 
        }
        $curentDirectory = NULL;
        if (isset($_SESSION['curentDirectory'])) {
            $curentDirectory = $_SESSION['curentDirectory'];
        }
        $baseDirectory = NULL;
        if (isset($_SESSION['baseDirectory'])) {
            $baseDirectory = $_SESSION['baseDirectory'];
        }
        // Protect page
        if ($login == NULL){
            header("Location: logout.php");
        }
        $dataToSend = "";
        // Actual path
        $curentDirectory = $baseDirectory . $curentDirectory;
        $dir = opendir($curentDirectory);
        chdir($curentDirectory);
        // List files of a directory
        while($entry = readdir($dir)) {
            // If is a dir and not masked
            if(is_dir($entry) && !in_array($entry, array(".",".."))){
                $dataToSend .=  "<tr><td><img src='./medias/dir-close.png'/><a class = 'dir'>" . $entry . "</a></td><td><img class = 'trash' src='./medias/trash.png'/></td></tr>";
            }
            // Is a file text
            else if(is_file($entry) && strstr($entry, '.txt') != NULL){
                $dataToSend .=  "<tr><td><img src='./medias/file-txt.png'/><a href='getFile.php?name=" . $entry . "'/>" . $entry . "</a></td><td><img class = 'trash' src='./medias/trash.png'/></td></tr>";
            }
            // Is a pdf
            else if(is_file($entry) && strstr($entry, '.pdf') != NULL){
                $dataToSend .=  "<tr><td><img src='./medias/file-pdf.png'/><a href='getFile.php?name=" . $entry . "'/>" . $entry . "</a></td><td><img class = 'trash' src='./medias/trash.png'/></td></tr>";
            }
            // Is a excel file
            else if(is_file($entry) && strstr($entry, '.exe') != NULL){
                $dataToSend .=  "<tr><td><img src='./medias/file-exe.png'/><a href='getFile.php?name=" . $entry . "'/>" . $entry . "</a></td><td><img class = 'trash'src='./medias/trash.png'/></td></tr>";
            }
        }
        closedir($dir);
        return $dataToSend;
    }
?>