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

Donde se señala en la imagen se reemplazan los Offset.

----------Actualizaciones----------

Lo añades tu a tu gusto, puedes utilizar el archivo (file.php) que se incluye en la mayoria de files por aqui en RaGezone.

//
// ENGLISH
//
This launcher bypasses the client's GameGuard security, without the need to use the old launcher included in CarlosX's source (credits for his project). The only requirements for compiling and using the launcher are the following:

Visual Studio Community 17.0+ XAMPP (requires PHP 7.1+) for the server's local server in case you need to add the structure for updates or to validate credentials. The rakion.bin file is included in CarlosX's source in RakionLauncher (the file is called "rakion.bin"). You can also obtain this file from any of the other private clients.

LauncherSrc

https://www.mediafire.com/file/cfawvzqul260sxa/GameLaunch SRC.rar/file

How to validate credentials:

If you want to be able to validate credentials, you can do so using PHP (launcherlogin.php), just like load.bin does.
![image](https://github.com/user-attachments/assets/4886bdc4-ec87-48f9-b380-49d00f9789e3)

In this section, you would need to call PHP and, depending on the response, call launchprocess if the user exists.

BypassGG (V164 and V258)

(This is the code that bypasses Rakion's GameGuard.)

![image](https://cdn.discordapp.com/attachments/1224798416727441489/1362559865167548658/image.png?ex=6806cac2&is=68057942&hm=444d5c6ed490b6955b7ddb323646a875c36a654031488eea0e64523619f5f291&)

This requires a small modification to the offsets written by the LaunchProcess() function. Below I'll list the offsets corresponding to each client version.

Offsets 258

Offset = 0x496616a
Offset 2 = 0x416f7
Offset 3 = 0x40d46d

Offsets 164:

Offset = 0x413d00e
Offset 2 = 0x46bcf8
The third offset is not necessary; just comment out the code.

![image](https://cdn.discordapp.com/attachments/1224798416727441489/1362560846907047966/image.png?ex=6806cbad&is=68057a2d&hm=5740532844383783b19f82f2c169444fb76fd0707f64d9f9d72ce01a9a16ef1d&)

The offsets are replaced where indicated in the image.


----------Updates----------

Add it yourself as you wish. You can use the file (file.php) included in most files here on RaGezone.

--End of thread--

Here are my social media accounts and the GitHub link so you can check out the project:
Discord = s00rk (Ransom)
RageZone = MauriGame9

--Fin del hilo--





