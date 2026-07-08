<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="project organization">
    <meta name="author" content="Regy Special">
    <title>Document</title>
  </head>
  <body>
    <h1>regy-special-project</h1>
    <?php
    function searchDir(string $path){
      $entry = scandir($path);
      for ($i=2;$i<count($entry);$i++){
        $fileOrDir=$entry[$i];
        $shiftColor=(["blue","lime","red"])[$i%3];
        echo"<div style=\"background-color:$shiftColor;\">$fileOrDir</div>";
      }
    }
    searchDir("../..");
    ?>
  </body>
</html>