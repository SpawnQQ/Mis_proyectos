<?php
   if( $_GET["name"] || $_GET["age"] ) {
      if (preg_match("/[^A-Za-z'-]/",$_GET['name'] )) {
         die ("invalid name and name should be alpha");
      }
      echo "Bienvenido ". $_POST['name']. "<br />";
      echo "Tu tienes ". $_POST['age']. " anos de edad.";
      
      exit();
   }
?>
<html>
   <body>
   
      <form action = "<?php $_PHP_SELF ?>" method = "get">
         Name: <input type = "text" name = "name" />
         Age: <input type = "text" name = "age" />
         <input type = "submit" />
      </form>
   
   </body>
</html>