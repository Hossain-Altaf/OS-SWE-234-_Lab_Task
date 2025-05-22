#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* threadFunction(void* arg) {
    int id = *((int*)arg);
    printf("Thread %d: Hello from the thread!\n", id);
    pthread_exit(NULL);  
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;

   
    if (pthread_create(&thread1, NULL, threadFunction, &id1) != 0) {
        perror("Failed to create thread 1");
        return 1;
    }

    if (pthread_create(&thread2, NULL, threadFunction, &id2) != 0) {
        perror("Failed to create thread 2");
        return 1;
    }


    if (pthread_join(thread1, NULL) != 0) {
        perror("Failed to join thread 1");
        return 1;
    }

    if (pthread_join(thread2, NULL) != 0) {
        perror("Failed to join thread 2");
        return 1;
    }

    printf("Main: All threads have finished.\n");
    return 0;
}
