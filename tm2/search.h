#ifndef SEARCH_H
#define SEARCH_H

#include <pthread.h>

#define MAX 20  // Tamaño del vector

// Estructura para pasar datos a los hilos
typedef struct {
    int id;
    int start;
    int end;
    int nro_a_buscar;
    int* vector;
    int* result;
    pthread_mutex_t* mutex;
    pthread_cond_t* cond;
} thread_data_t;

void* search_in_vector(void* arg);

#endif // SEARCH_H
