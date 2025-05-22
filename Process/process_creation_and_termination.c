#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork(); 

    if (pid < 0) {
        
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        
        printf("Child Process: PID = %d, PPID = %d\n", getpid(), getppid());
        printf("Child Process: Doing some work...\n");
        sleep(2);
        printf("Child Process: Exiting.\n");
        exit(0);  
    } else {
       
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        printf("Parent Process: Waiting for child to terminate...\n");
        wait(NULL); 
        printf("Parent Process: Child terminated. Exiting.\n");
    }

    return 0;
}
