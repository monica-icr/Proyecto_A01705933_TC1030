# Proyecto_A01705933_TC1030
### Mafia 
El proyecto simula un juego de Mafia. 

Este es un juego de rol donde todos los jugadores tienen un papel. Los jugadores o son civiles o son parte de la mafia. La mafia gana matando civiles cuando son mayoría, y los civiles ganan votando para eliminar a todas las mafias. Algunos civiles tienen roles especiales con una acción especial por turno como lo son el investigador que puede preguntar si un jugador es bueno o malo y el doctor que puede salvar a un jugador. Existen dos momentos en el juego, la noche y el día. En la noche las mafias votan para matar a alguien y los civiles con roles especiales realizan sus acciones especiales. En el día se anuncia si murió alguien en la noche y se realiza una votación para eliminar a alguien. 

En el programa se lleva acabo este juego con ayuda de una estructura de clases con los distintos tipos de jugador y les asigna sus propias características y acciones a cada rol.

### Funcionalidad
El programa es una versión limitada del juego ya que solo existen 4 roles distintos (civil, doctor, investigador y mafia), cuando en el juego real existen muchos más. 

El programa esta diseñado para que el dios (es decir, un moderador que no es jugador pero guía la partida) sea el usuario. 

El programa termina cuando después de las rondas ganen las mafias al ser mayoría, o ganen los civiles matando a todas las mafias. 

### Consideraciones 
El programa necesita que los archivos se encuentren en la misma carpeta. 

El programa corre en consola, y esta programado en c++ estándar con la biblioteca iostream y string por lo que corre en cualquier sistema operativo.

Para compilar buscar la ruta donde se encuentre la carpeta con los archivos y escribe "g++ main.cpp"

correr en windows: "a.exe"
correr en linux: "/a.out"

### Fallas (consideraciones para el usuario) 
El programa falla si el usuario ingresa un valor string cuando se le pide un valor int. 

Es importante que usuario no ingrese el mismo nombre para distintos jugadores ya que el juego no va a funcionar de la manera en la que se busca. También como recomendación, eviten los espacios después de los nombres ingresados. 

### Correcciones

No hay correcciones que mencionar ya que todas las subcompetencias evaluadas en las entregas previas fueron acreditadas. 
Lo único que se puede mencionar es que en la segunda retroalimentación se pide que se separen las clases en distintos archivos. Sin embargo, este archivo resulto no ser tan largo (jugador.h), por lo que no fue necesario hacerlo. 

