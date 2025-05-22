#include <pthread.h>
#include <stdio.h>
#include <unistd.h>  // <-- Add this line for sleep()

void* printMessage(void* arg) {
    char* msg = (char*)arg;
    printf("Thread says: %s\n", msg);
    return NULL;
}

int main() {
    pthread_t thread;
    char* message = "Hello from thread!";

    pthread_create(&thread, NULL, printMessage, (void*)message);
    pthread_join(thread, NULL);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", i);
        sleep(1);
    }
 printf(“join”);
    return 0;
}
