Sobre el proyecto. 

B.A.L.T.A.M. es un proyecto que nace con el prposito de facilitar y agilizar la operatoria matricial. 
En este software encontraras las opciones de "Operaciones básicas con matrices" y "Operar sobre una matriz" de las cuales se desprenden otras 3 opciones en cada una; suma, resta y multiplicación en la primera y diagonal, traspuesta e inversa en la segunda.

Proceso de instalación. 

Para la instalación del pograma presisamos de tener instalado el software de QT con la finalidad de agregar un "INCLLUDEPATH += $$PWD" en el archivo .pro en caso de trabajar con el compilador de windows entre otros. 

1. Descargar el archivo del proyecto B.A.L.T.A.M. en .zip y descomprimelo.

2. Ejecuta el programa con QT en modo Release una sola vez esto generará un build del proyecto.

3. Dentro del archivo built que se genero habrá un archibo release, de este solo nos interesa el .exe que será el ejecutable de nustro programa. 

4. Luego, abrimos la terminal de nuestro QT y confirmamos que este instalada la aplicación >windeployqt.exe (de no estarla ejecutamos su instalación).

5. En la misma consola prcedemos a ingresar al directorio donde tenemos el archivo .exe de nuestro programa para esto ejecutamos como >cd *nombre del directorio*

6. Luego ejecutamos el >windeployqt.exe . (el puto es nuestro parametro para que actue sobre el directorio en el que estamos). 

7. Ahora, con este proceso evitamos ingresar los archivos manualmente en la carpeta para que el .exe funcione. 

Para la instalación del programa presisamos de lo siguiente.

Links relevantes. 
