<!doctype html>
<html lang="it">
  <head>
    <title>My VideoGame</title>
    <meta name="author" content="Regy Special">
    <meta name="description" content="Web version of the regy-special-prject videogame">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="keywords" content="Regy Special, RegySpecial, regyspecial, REGYSPECIAL, regy special, REGY SPECIAL">
    <meta charset="UTF-8">
    <link rel="stylesheet" href="../css/web.css" type="text/css">
    <link rel="icon" href="../../bin/blob/images/RegySpecial.jpg" type="image/jpeg">
    <script defer src="../js/web.js" type="text/javascript"></script>
  </head>
  <body>
    <audio
      controls
      src="../../bin/blob/audio/music/co.ag/Sinister_Dark_Ambient_Background_Music_-_Dark_Rage_[_YouConvert.net_].mp3"
      id="music"
      autoplay
    >
    </audio>
    <section id="intro">
      <img src="../../bin/blob/image/icons/RegySpecial.ico">
      <h1>A videogame developed by Regy Special</h1>
    </section>
    <section id="buttonGrid">
      <?php
        foreach (["Play","Exit","Options","More information"] as $buttonText)
      ?>
      <button id="<?php echo $buttonText; ?>"><?php echo $buttonText; ?></button>
    </section>
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
          $connection=new PDO("sqlite:db=bin/db/database.db");
          $statement=$connection->prepare("select * from users where name=?");
          $statement->exec($_GET["user"]);
          print_r($statement->fetchAll(PDO::FETCH_ASSOC));
          $statement->closeCursor();
          $connection=null;
      ?>
        <h1><?php $_GET["user"]?></h1>
      <?php } ?>
    </seciton>
    <?php
      foreach (["Play","Exit","Options","More information"] as $buttonText)
    ?>
    <dialog id="<?php echo $buttonText,"Dialog"; ?>">
    <?php
      switch ($buttonText) {
        case "Play":
    ?>
      <button>Semplice</button>
      <button>Intermedia</button>
      <button>Avanzata</button>
      <button>Estrema</button>
      <button>Personalizzata</button>
    <?php
          break;
        case "Exit":
    ?>
      <p>Sei sicuro di voler uscire</p>
    <?php 
          break;
        case "Options":
    ?>
      <input type="range" min="0" max="255" value="127" name="music" id="music">
      <input type="range" min="0" max="255" value="127" name="voice" id="voice">
      <input type="range" min="0" max="255" value="127" name="sound" id="sound">
    <?php
          break;
        case "More Information":
    ?>
      <p id="moreinfo"></p>
    <?php
          break;
      } 
    ?>
      <button>Annulla</button>
      <button>Conferma</button>
    </dialog>
  </body>
</html>
