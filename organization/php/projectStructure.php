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
    <form method="get">
      <select name="view">
        <option value="tree">tree</option>
        <option value="square">square</option>
      </select>
      <button name="inputSend" value="1">output</button>
    </form>
    <h1>regy-special-project</h1>
    <?php
      function searchDir(string $path)
      {
        $entry = scandir($path);
        for ($i = 2;$i < count($entry);$i++){
          $fileOrDir = filter_var($entry[$i],FILTER_SANITIZE_SPECIAL_CHARS);
          switch($_GET['view']){
            case 'square':
              $square=round(
                sqrt(
                  count($entry)
                )
              );
              $num = str_repeat(
                "auto ",
                $square
              );
              echo "<div
                style=\"
                  border:1px solid;
                  display:grid;
                  place-items:center;
                  gap:10px;
                  padding:10px;
                \"
              >";
              echo "<h1 style=\"
                grid-column: 1;
                text-align:center;
              \">$fileOrDir</h1>";
              if (is_dir("$path/$fileOrDir"))
                searchDir("$path/$fileOrDir");
              echo "</div>";
              break;
            case 'tree':
              $full="$path/$fileOrDir";
              $branch=str_replace("$path/",str_repeat("-",strlen("$path/")),$full);
              echo "<p>$branch</p>";
              if (is_dir("$path/$fileOrDir"))
                searchDir("$path/$fileOrDir");
              break;
          }
        }
      }
      searchDir("../..");
    ?>
  </body>
</html>