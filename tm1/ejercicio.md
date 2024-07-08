Implementar un programa en C que calcule el factorial de los números que se le pasan
como argumentos. El programa creará tantos hilos con Pthreads como argumentos se
introduzcan y cada uno de los hilos recibirá uno de esos argumentos y calculará su
factorial de manera concurrente, pero la salida que imprimen los hilos deberán ser en
orden (utilice las herramientas de sincronización estudiadas para cumplir con este
proposito). Cada hilo ha de recibir como argumento el número cuyo factorial debe calcular.
Un ejemplo de la ejecución del programa podria ser la siguiente:

$ factorial 3 6 4 1 0

Salida
Factorial de 3: 6
Factorial de 6: 720
Factorial de 4: 24
Factorial de 1: 1
Factorial de 0: 1