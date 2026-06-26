<!doctype html>
<html lang="it">
  <head>
    <title>My VideoGame</title>
    <meta name="author" content="Regy Special">
    <meta name="description" content="Tentativo di creare un videogioco da zero">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="keywords" content="Regy Special, RegySpecial, regyspecial, REGYSPECIAL, regy special, REGY SPECIAL">
    <meta charset="UTF-8">
    <link rel="stylesheet" href="Web.css" type="text/css">
    <link rel="icon" href="../../RegySpecial.jpg" type="image/jpeg">
    <script defer src="Web.js" type="text/javascript"></script>
  </head>
  <body>
    <audio
      controls
      src="file:///media/regyspecial/REGYSPECIAL/Regy%20Special/Regy%20Special%20Project/binary large objects/audios/Sinister_Dark_Ambient_Background_Music_-_Dark_Rage_[_YouConvert.net_].mp3"
      id="music"
      autoplay
    >
    </audio>
    <div id="intro">
      <img src="file:///media/regyspecial/REGYSPECIAL/Regy%20Special/RegySpecial.jpg">
      <br>
    </div>
    <section id="mainScreen">
      <?php
        if(!isset($_GET["user"])){
      ?>
      <form>
        <input type="text">
        <input type="submit" name="submit" value="Invia">
      </form>
      <?php
        }else{
          $connection=new PDO("sqlite:");
      ?>
        <h1><?php $_GET["user"]?></h1>
      <?php } ?>
    </seciton>
  </body>
</html>
