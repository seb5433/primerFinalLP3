#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "factorial.h"

void crear_hilos(pthread_t* hilos, thread_data_t* datos_hilo, int total_numeros, char* argv[]);
void esperar_hilos(pthread_t* hilos, int total_numeros);
void clean_all();

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s num1 num2 ... numN\n", argv[0]);
        return 1;
    }

    int total_numeros = argc - 1;
    pthread_t hilos[total_numeros];
    thread_data_t datos_hilo[total_numeros];

    crear_hilos(hilos, datos_hilo, total_numeros, argv);
    esperar_hilos(hilos, total_numeros);
    clean_all();

    return 0;
}

void crear_hilos(pthread_t* hilos, thread_data_t* datos_hilo, int total_numeros, char* argv[]) {
    for (int i = 0; i < total_numeros; i++) {
        datos_hilo[i].indice = i;
        datos_hilo[i].numero = atoi(argv[i + 1]);
        int rc = pthread_create(&hilos[i], NULL, calcular_factorial, (void*) &datos_hilo[i]);
        if (rc) {
            fprintf(stderr, "Error al crear el hilo %d\n", i);
            exit(1);
        }
    }
}

void esperar_hilos(pthread_t* hilos, int total_numeros) {
    for (int i = 0; i < total_numeros; i++) {
        pthread_join(hilos[i], NULL);
    }
}

void clean_all() {
    pthread_mutex_destroy(&mutex);
}
