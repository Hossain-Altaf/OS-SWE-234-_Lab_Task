#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int data = 0;
int read_count = 0;
pthread_mutex_t mutex, write_lock;

void* reader(void* arg) {
    for (int i = 0; i < 3; i++) {
        pthread_mutex_lock(&mutex);
        read_count++;
        if (read_count == 1)
            pthread_mutex_lock(&write_lock);
        pthread_mutex_unlock(&mutex);

        // Reading section
        printf("Reader %d read data = %d\n", *(int*)arg, data);
        sleep(1);

        pthread_mutex_lock(&mutex);
        read_count--;
        if (read_count == 0)
            pthread_mutex_unlock(&write_lock);
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
    return NULL;
}

void* writer(void* arg) {
    for (int i = 0; i < 2; i++) {
        pthread_mutex_lock(&write_lock);

        // Writing section
        data += 10;
        printf("Writer %d wrote data = %d\n", *(int*)arg, data);
        sleep(2);

        pthread_mutex_unlock(&write_lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t r1, r2, w1;
    int id1 = 1, id2 = 2, wid = 1;

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&write_lock, NULL);

    pthread_create(&r1, NULL, reader, &id1);
    pthread_create(&r2, NULL, reader, &id2);
    pthread_create(&w1, NULL, writer, &wid);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&write_lock);

    return 0;
}
