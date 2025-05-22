#include <stdio.h>

int main() {
    if (rename("oldname.txt", "newname.txt") == 0) {
        printf("File moved/renamed successfully.\n");
    } else {
        perror("File move/rename failed");
    }
    return 0;
}
