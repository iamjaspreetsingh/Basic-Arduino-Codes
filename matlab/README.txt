USB-TTL module is used for serial communication between matlab and arduino as different COM port was required for it.
The data can be sent or received to arduino using Software serial in arduino code and rgb led color changes according to rgb values sent by matlab.
Matlab finds the rgb values by various functions of webcam.
Few commonly used are webcam(),preview( ),snapshot([vid]),size([img]),serial([COM],'Baudrate',[]),fopen( ),fread( ),fgets( ),fwrite( ),fclose( )...


 