<?php
   $filename = "/home/spawnqq/Mis_proyectos/Aprendiendo_php/newfile.txt";
   $file = fopen( $filename, "w+" );
   
   if( $file == false ) {
      echo ( "Error in opening new file" );
      exit();
   }
   fwrite( $file, "This is  a simple test\n" );
   fclose( $file );
?>
<html>
   
   <head>
      <title>Writing a file using PHP</title>
   </head>
   
   <body>
      
      <?php
         $filename = "newfile.txt";
         $file = fopen( $filename, "r" );
         
         if( $file == false ) {
            echo ( "Error in opening file" );
            exit();
         }
         
         $filesize = filesize( $filename );
         $filetext = fread( $file, $filesize );
         
         fclose( $file );
         
         echo ( "File size : $filesize bytes <br />" );
         echo ( "$filetext <br />" );
         echo("file name: $filename <br />");
      ?>
      
   </body>
</html>