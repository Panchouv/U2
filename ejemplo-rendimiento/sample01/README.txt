Ejemplo 01
==========

Ejemplo de aceleración de código. Se realizan operación de elevación
a potencia y extracción de raíz cuadrada en forma repetitiva, de tres
formas equivalente, y se toman los tiempos. 

Sin optimización de código a través del compilador (-O0)
================================================================
$ ./sample01 -r 100000000

Repeticiones: 100000000
====Versión 1====
Tiempo01 :5060[ms]
Distancia:7.82821e+08

====Versión 2====
Tiempo02 :277[ms]
Distancia:7.82821e+08

====Versión 3====
Tiempo03 :276[ms]
Distancia:7.82821e+08

====Desempeño====
Aceleración A(1,2) = 18.2671
Aceleración A(1,3) = 18.3333


Con optimización de código (-O2)
================================================================
./sample01 -r 100000000
Repeticiones: 100000000
====Versión 1====
Tiempo01 :93[ms]
Distancia:7.82821e+08

====Versión 2====
Tiempo02 :94[ms]
Distancia:7.82821e+08

====Versión 3====
Tiempo03 :93[ms]
Distancia:7.82821e+08

====Desempeño====
Aceleración A(1,2) = 0.989362
Aceleración A(1,3) = 1



 _________________________________________
/ Algunas veces no hay que pensar en      \
\ paralelismo para obtener aceleración... /
 -----------------------------------------
   \         ,        ,
    \       /(        )`
     \      \ \___   / |
            /- _  `-/  '
           (/\/ \ \   /\
           / /   | `    \
           O O   ) /    |
           `-^--'`<     '
          (_.)  _  )   /
           `.___/`    /
             `-----' /
<----.     __ / __   \
<----|====O)))==) \) /====
<----'    `--' `.__,' \
             |        |
              \       /
        ______( (_  / \______
      ,'  ,-----'   |        \
      `--{__________)        \/
	  
 
 
	  
	  

