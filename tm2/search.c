#include "search.h"
#include <pthread.h>
#include <stdlib.h>

void* search_in_vector(void* arg) {
    thread_data_t* data = (thread_data_t*) arg;
    for (int i = data->start; i <= data->end; i++) {
        pthread_mutex_lock(data->mutex);
        if (*data->result != -1) {  // Si ya se encontro el numero
            pthread_mutex_unlock(data->mutex);
            break;
        }
        if (data->vector[i] == data->nro_a_buscar) {
            *data->result = i;
            pthread_cond_broadcast(data->cond);  // Notificacion a todos los hilos
            pthread_mutex_unlock(data->mutex);
            break;
        }
        pthread_mutex_unlock(data->mutex);
    }
    pthread_exit(NULL);
}
