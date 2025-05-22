#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int num[5] = {5, 10, 15, 0, 25};


void* thread_function(void* arg) {
    int* a = (int*)arg;
    int sum = a[2] + a[4];
    printf("The sum is %d\n", sum);
    return NULL;
}

int main() {
    pthread_t thread;

  
    if (pthread_create(&thread, NULL, thread_function, (void*)num) != 0) {
        perror("Thread creation failed");
        return 1;
    }


    pthread_join(thread, NULL);

    return 0;
}
