# RakionLauncher
Este Launcher se encarga de bypassear la seguridad del gameguard del cliente, sin necesidad de usar el antiguo Launcher incluido en el source de CarlosX (creditos por su proyecto).
Los unicos requisitos para compilar y poder utilizar el Launcher son los siguientes:

Visual Studio Comunnity 17.0+
Xampp (requisito PHP 7.1+) para el servidor local del server en caso de que requieras añadir la estructura para actualizaciones o para validar credenciales. 
Archivo rakion.bin includo en el source de CarlosX en RakionLauncher (el archvo se llama "rakion.bin"), este archivo tambien puedes obtenerlo en cualquiera de los demas clientes privados.

LauncherSrc

https://www.mediafire.com/file/cfawvzqul260sxa/GameLaunch SRC.rar/file


Como validar credenciales:

Si deseas poder validar las credenciales puedes hacerlo mediante un php asi como lo hace el load.bin
![image](https://github.com/user-attachments/assets/4886bdc4-ec87-48f9-b380-49d00f9789e3)
En esta parte tendrias que llamar al php y de acuerdo a la respuesta, si usuario existe llamar a launchprocess

//Offsets a reemplazar(v258 requiere esos tres offesets) mientras que en la v164 puedes comentar la tercera linea.

(Offsets (258)

offset 0x496616a
offset 2 = 0x416f7c
offset 3 = 0x40d46d

(Offsets v164)

offset = 0x413d00e
offset 2 = 0x46bcf8
La tercera no es necesario, solo comenta el codigo

![image](https://cdn.discordapp.com/attachments/1224798416727441489/1362560846907047966/image.png?ex=6806cbad&is=68057a2d&hm=5740532844383783b19f82f2c169444fb76fd0707f64d9f9d72ce01a9a16ef1d&)
Donde se señala en la imagen se reemplazan los offset


El sistema de actualizaciones tu veras como lo implementas, puedes utilizar el archivo file.php(tambien includo en el repositorio RakionLauncher de CarlosX) para la validacion mediante hash MD5 pero de eso ya te encargas tu ;) 

Este es el codigo que se encarga de bypassear el GameGuard de rakion
![image](https://cdn.discordapp.com/attachments/1224798416727441489/1362559865167548658/image.png?ex=6806cac2&is=68057942&hm=444d5c6ed490b6955b7ddb323646a875c36a654031488eea0e64523619f5f291&)


