<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="project organization">
    <meta name="author" content="Regy Special">
    <title>projectStructure</title>
    <style>
      #ID
      {
        border:1px solid;
        display:grid;
        place-items:center;
        gap:10px;
        padding:10px;
        text-align: center;
      }

      pre
      {
        display: none;
        position: fixed;
        top: 0px;
        left: 0px;
        z-index: 1000;
      }
    </style>
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
    <pre>coso</pre>
    <?php
      function searchDir(string $path)
      {
        $entry = scandir($path);
        for ($i = 2;$i < count($entry);$i++){
          $fileOrDir = str_replace('<', '&lt;', str_replace('>', '&gt;', str_replace('"', "&doublequote;", $entry[$i])));
          $fileType = filetype("$path/$fileOrDir");
          $fileMime = mime_content_type("$path/$fileOrDir");
          switch($_GET['view']){
            case 'square':
              echo "<div id=\"ID\" class=\"$fileType:$fileMime\">$fileOrDir";
              if (is_dir("$path/$fileOrDir"))
                searchDir("$path/$fileOrDir");
              echo "</div>\n";
              break;
            case 'tree':
              $full="$path/$fileOrDir";
              $branch=str_replace("$path/",str_repeat("-",strlen("$path/")),$full);
              echo "<p>$branch</p>\n";
              if (is_dir("$path/$fileOrDir"))
                searchDir("$path/$fileOrDir");
              break;
          }
        }
      }
      searchDir("../..");
    ?>
    <script>
      document.querySelectorAll`#ID`.forEach(element=>{
        element.addEventListener("mouseover",function(e){
          document.querySelector("pre").style.display = "block"
          document.querySelector("pre").style.top = `${e.clientY}px`
          document.querySelector("pre").style.left = `${e.clientX}px`
          document.querySelector("pre").textContent = element.className
        },1)
        element.addEventListener("mousemove",function(e){
          document.querySelector("pre").style.display = "block"
          document.querySelector("pre").style.top = `${e.clientY}px`
          document.querySelector("pre").style.left = `${e.clientX}px`
          document.querySelector("pre").textContent = element.className
        },1)
        element.addEventListener("mouseout",function(){
          document.querySelector("pre").style.display = "none"
        },1)
      })
    </script>
  </body>
</html>