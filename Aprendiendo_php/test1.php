<?php
   if($_GET["nombre"]){
   		echo "Bienvenido ".$_GET['nombre'];
   		exit();
   }
?>

<html>   
   <body>
 
		<form name="formulario" method="get" action="<?php $_PHP_SELF ?>">
			Nombre: <input type="text" name="nombre" value="">
			<input type="submit" />
		</form>
    
   </body>
</html>