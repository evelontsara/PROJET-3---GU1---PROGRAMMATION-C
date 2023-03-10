#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
    
    int **board = (int **)malloc(9 * sizeof(int *));
    for (int a = 0; a < 9; a++) {
        board[a] =(int *)malloc(9 * sizeof(int));
    }

    int fd = open(argv[argc-1], O_RDONLY);
    

    // double boucle pour la création du tableau
    char c;
    for (int a = 0; a < 9; a++) {
        for (int b = 0; b < 9; b++) {
            read(fd, &c, 1); 
            // convertir la valeur en entier et stocker dans le tableau
            board[a][b] = c - '0';
        }
        read(fd, &c, 1);  
    }

    close(fd);

    // La boucle avec les printf pour afficher le sudoku initial
    printf("Le sudoku avec le tableau :\n");
    for (int a = 0; a < 9; a++) {
        for (int b = 0; b < 9; b++) {
            printf("%d ", board[a][b]);
        }
        printf("\n"); 
    }


    for (int a = 0; a < 9; a++) {
        free(board[a]);
    }
    free(board);
}
