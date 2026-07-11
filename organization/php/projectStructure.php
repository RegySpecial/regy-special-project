<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="project organization">
    <meta name="author" content="Regy Special">
    <title>projectStructure</title>
  </head>
  <body>
    <h1>regy-special-project</h1>
    <?php
    function searchDir(string $path){
      $entry = scandir($path);
      for ($i = 2;$i < count($entry);$i++){
        $fileOrDir = $entry[$i];
        $backgroundColor = (["blue","lime","red"])[$i % 3];
        $borderColor = (["blue","lime","red"])[($i + 1) % 3];
        echo"<div style=\"background-color:$backgroundColor;border:1px solid $borderColor;\">$fileOrDir</div>";
        if(is_dir("$path/$fileOrDir"))searchDir("$path/$fileOrDir");
      }
    }
    searchDir("../..");
    ?>
  </body>
</html>