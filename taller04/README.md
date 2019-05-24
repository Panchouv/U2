
# Taller 04: Paralelización del Juego de la Vida

## Objetivos:

Diseñar e implementar en C++ (std14), con threads, el autómata celular "Game of Life" . El tablero es limitado y deberá tener la misma cantidad de filas y de columnas. Una implementación en C++ la puede obtener de [aquí](https://github.com/gabriel-astudillo/Game-of-live/tree/master/agent%20version) o ver implementaciones en [RossetaCode](http://rosettacode.org/wiki/Conway%27s_Game_of_Life).

## Descripción del Juego de la vida

El juego evoluciona en pasos discretos y la primera generación de células es generada en forma aleatoria, con cierta probabilidad de que esté viva. Cada célula puede nacer, vivir o morir según la cantidad de células vivas en su vecindad de Moore de radio unitario:
* Una célula muerta con exactamente 3 células vecinas vivas “nace” en la siguiente iteración.
* Una célula viva con 2 o 3 células vecinas vivas sigue viva
* En otro caso muere (por "soledad" o "superpoblación").

## Forma de uso:
```
./gameOfLife -t <nro> -T <nro>  -p <nro>  -i <nro> -P <0|1> [-h]

Parámetros:
	-t   : número de threads.
	-T   : Tamaño del tablero.
	-p   : Probabilidad inicial de que una célula esté viva.
	-i   : Cantidad de iteraciones.
	-P   : Tipo de partición: 0->Franjas, 1:Bloques
	[-h] : muestra la ayuda de uso y termina.
``` 
## Ejemplo de uso:

En su versión secuencial pura, por cada iteración, su programa debe entregar la cantidad de células vivas. Por ejemplo:
```
Generación: 1, Cantidad de células vivas (S/P): 300/300
Generación: 2, Cantidad de células vivas (S/P): 310/310
Generación: 3, Cantidad de células vivas (S/P): 290/290
Generación: 4, Cantidad de células vivas (S/P): 280/280
```

*Observación*: En cada iteración, se resolverá el juego en forma secuencial y paralela.

### Trabajo a realizar

1) Implementar el Juego de la Vida con threads, en base a los requerimientos explicados.
   
2) Realizar pruebas de desempeño para un tablero de tamaño 2^n x 2^n, con t={1,2,3,...,16} threads y n={10,11,12,13,14,15}.
   Obtener gráficos de Tejec/Nro threads (G1), SpeedUp/Nro Threads (G2) y Eficiencia/Nro Threads (G3). 
   Cada medición debe ser obtenida a través de la ejecución de 10 o más experimentos. Debe graficar el promedio y su dispersión de los tiempos de ejecución en G1.
   
3) Entregar Informe en Aula Virtual y códigos en el servidor.



