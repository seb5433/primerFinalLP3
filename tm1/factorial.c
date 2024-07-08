#include "factorial.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int siguiente_indice = 0;

// Funcion para iniciar el calculo del factorial
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Funcion que calcula el factorial de un numero
void* calcular_factorial(void* arg) {
    thread_data_t* data = (thread_data_t*) arg;
    data->resultado = factorial(data->numero);

    pthread_mutex_lock(&mutex);
    while (data->indice != siguiente_indice) {
        pthread_mutex_unlock(&mutex);
        sched_yield();
        pthread_mutex_lock(&mutex);
    }
    printf("Factorial de %d: %lld\n", data->numero, data->resultado);
    siguiente_indice++;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}
