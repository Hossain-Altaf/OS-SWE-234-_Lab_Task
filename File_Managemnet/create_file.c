#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "w"); 
    if (file == NULL) {
        perror("File creation failed");
        return 1;
    }
    fprintf(file, "This is a new file.\n");
    fclose(file);
    printf("File created successfully.\n");
    return 0;
}
