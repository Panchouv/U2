
# Taller 04: Paralelización del Juego de la Vida

## Objetivos:

Diseñar e implementar en C/C++, con openMP y operaciones SSE, el autómata celular “Game of Life” . El tablero es limitado y deberá tener la misma cantidad de filas y de columnas.

## Descripción del Juego de la vida

El juego evoluciona en pasos discretos y la primera generación de células es generada en forma aleatoria, con cierta probabilidad de que esté viva. Cada célula puede nacer, vivir o morir según la cantidad de células vivas en su vecindad de Moore de radio unitario:
* Una célula muerta con exactamente 3 células vecinas vivas “nace” en la siguiente iteración.
* Una célula viva con 2 o 3 células vecinas vivas sigue viva
* En otro caso muere (por "soledad" o "superpoblación").


## Forma de uso:
```
./gameOfLife -t <nro> -T <nro>  -p <nro>  -i <nro> -P <0|1>[-h]

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

Generación: 1, Cantidad de células vivas (S/P): 300/300
Generación: 2, Cantidad de células vivas (S/P): 310/310
Generación: 3, Cantidad de células vivas (S/P): 290/290
Generación: 4, Cantidad de células vivas (S/P): 280/280



### Trabajo a realizar

1) A partir del código entregado, implementar un programa que llene un arreglo de números enteros tamaño N (en forma secuencial) y que luego los sume a través de t threads.
   
2) Realizar pruebas de desempeño para un arreglo de tamaño N=2e9, con t={1,2,3,...,16} threads.
   Obtener gráficos de Tejec/Nro threads (G1), SpeedUp/Nro Threads (G2) y Eficiencia/Nro Threads (G3). 
   Cada medición debe ser obtenida a través de la ejecución de 10 o más experimentos. Debe graficar el promedio y su dispersión de los tiempos de ejecución en G1.



