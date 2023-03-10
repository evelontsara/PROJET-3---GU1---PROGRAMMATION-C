#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void find(int **board, int line, int columm, int *possible_numbers) {

    // Vérifier les chiffres sur la ligne
    for (int i = 0; i < 9; i++) {
        int num = board[line][i];
        possible_numbers[num] = 1;
    }

    // Vérifier les chiffres dans la colone
    for (int i = 0; i < 9; i++) {
        int num = board[i][columm];
        possible_numbers[num] = 1;
    }

    // Marquer les chiffres possibles
    for (int i = 1; i <= 9; i++) {
        if (!possible_numbers[i]) {
            printf("%d ", i);
        }
    }
}

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
        // lire les valeur du fichier
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

    
    int possible_numbers[10];
    printf("Les chiffres possibles pour la case sont : ");
    find(board, 1, 2, possible_numbers);
    printf("\n");

    for (int a = 0; a < 9; a++) {
        free(board[a]);
    }
    free(board);
}
