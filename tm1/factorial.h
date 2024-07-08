#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <pthread.h>

typedef struct {
    int indice;
    int numero;
    long long resultado;
} thread_data_t;

extern pthread_mutex_t mutex;

long long factorial(int n);
void* calcular_factorial(void* arg);

#endif // FACTORIAL_H
