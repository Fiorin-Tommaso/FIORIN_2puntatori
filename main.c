#include <stdio.h>
#include <string.h>

#include "stdlib.h"

char* duplicate(char *gaspari) {
    char *newgaspari = (char *)malloc(strlen(gaspari) + 1);
    for (int i = 0; i < sizeof(gaspari); i++) {
        gaspari[i] = newgaspari[i];
    }
    return newgaspari;
}

int main(void) {
    char *gaspari = malloc(sizeof(char) * 100);
    fgets(gaspari, 100, stdin);
    for (int i = 0; i < 100; i++ ) {
        if (gaspari[i] == '\0') {
            gaspari = realloc(gaspari, sizeof(char) * (i + 1));
            break;
        }
    }
    char *newgaspari = duplicate(gaspari);
    for (int i = 0; i < sizeof(newgaspari); i++) {
        printf("%c", newgaspari[i]);
    }
    free(newgaspari);
    free(gaspari);
    gaspari = NULL;
    newgaspari = NULL;
    return 0;
}