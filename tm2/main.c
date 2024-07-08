#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "search.h"

void initVector(int *vector, int size);
void imprimir_vector(const int *vector, int size);
void crear_hilos(pthread_t *hilos, thread_data_t *thread_data, int nro_de_hilos, int *vector, int nro_a_buscar, int *result, pthread_mutex_t *mutex, pthread_cond_t *cond);
void wait_for_hilos(pthread_t *hilos, int nro_de_hilos);
void limpiar_mutex_y_cond(pthread_mutex_t *mutex, pthread_cond_t *cond);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Uso: %s <numero_a_buscar> <numero_de_hilos>\n", argv[0]);
        return 1;
    }

    int nro_a_buscar = atoi(argv[1]);
    int nro_de_hilos = atoi(argv[2]);
    int vector[MAX];
    pthread_t hilos[nro_de_hilos];
    thread_data_t thread_data[nro_de_hilos];
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
    int result = -1; // Indice donde se encuentra el número o -1 si no se encuentra

    initVector(vector, MAX);
    imprimir_vector(vector, MAX);
    crear_hilos(hilos, thread_data, nro_de_hilos, vector, nro_a_buscar, &result, &mutex, &cond);
    wait_for_hilos(hilos, nro_de_hilos);
    limpiar_mutex_y_cond(&mutex, &cond);

    // Imprimir el resultado
    if (result != -1)
    {
        printf("Número %d encontrado en la posición %d\n", nro_a_buscar, result);
    }
    else
    {
        printf("Número %d no encontrado en el vector\n", nro_a_buscar);
    }

    return 0;
}

void initVector(int *vector, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        vector[i] = rand() % 10;
    }
}

void imprimir_vector(const int *vector, int size)
{
    printf("Vector generado: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void crear_hilos(pthread_t *hilos, thread_data_t *thread_data, int nro_de_hilos, int *vector, int nro_a_buscar, int *result, pthread_mutex_t *mutex, pthread_cond_t *cond)
{
    int segment_size = MAX / nro_de_hilos;
    int remainder = MAX % nro_de_hilos;
    int start = 0;

    for (int i = 0; i < nro_de_hilos; i++)
    {
        int end = start + segment_size - 1;
        if (i < remainder)
        {
            end++;
        }
        thread_data[i] = (thread_data_t){.id = i, .start = start, .end = end, .nro_a_buscar = nro_a_buscar, .vector = vector, .result = result, .mutex = mutex, .cond = cond};
        start = end + 1;
        int rc = pthread_create(&hilos[i], NULL, search_in_vector, (void *)&thread_data[i]);
        if (rc)
        {
            fprintf(stderr, "Error al crear el hilo %d\n", i);
            exit(1);
        }
    }
}

void wait_for_hilos(pthread_t *hilos, int nro_de_hilos)
{
    for (int i = 0; i < nro_de_hilos; i++)
    {
        pthread_join(hilos[i], NULL);
    }
}

void limpiar_mutex_y_cond(pthread_mutex_t *mutex, pthread_cond_t *cond)
{
    pthread_mutex_destroy(mutex);
    pthread_cond_destroy(cond);
}
