Taller 03: Suma paralela del contenido de un arreglo de números enteros.

Objetivos:

Crear un programa que llene de un array de numero enteros aleatorios del tipo uint32_t en forma secuencial y que luego los sume en forma paralela. Realizar pruebas de desempeño para mostrar el comportamiento del programa implementado.

 Forma de uso:

./sumArray -N <nro> -t <nro>  -L <nro> [-h]

Parámetros:
	-N   : tamaño del arreglo.
	-t   : número de threads.
	-L   : límite superior rango aleatorio.
	[-h] : muestra la ayuda de uso y termina.
 
Ejemplo de uso:

1) Crea un arreglo de 1000000 posiciones, con 4 threads. 
   Los números enteros aleatorios están en el rango [10,50]

./sumArray -N 1000000 -t 4 -L 50

2) Muestra la ayuda y termina

./sumArray -h
./sumArray


Trabajo a realizar
==================
1) A partir del código entregado, implementar un programa que llene un arreglo de números enteros tamaño N (en forma secuencial) y que luego los sume a través de t threads.
   
2) Realizar pruebas de desempeño para un arreglo de tamaño N=2e9, con t={1,2,3,...,16} threads.
   Obtener gráficos de Tejec/Nro threads (G1), SpeedUp/Nro Threads (G2) y Eficiencia/Nro Threads (G3). 
   Cada medición debe ser obtenida a través de la ejecución de 10 o más experimentos. Debe graficar el promedio y su dispersión de los tiempos de ejecución en G1.



