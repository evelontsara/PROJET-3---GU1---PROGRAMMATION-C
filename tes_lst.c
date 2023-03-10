

/*
#1/ Triez array_int avec qsort, ou avec un tri à bulle
2/ Création de 5 "type_lst *" contenant un chiffre chacun

3/ Chainer ses listes grâce au "next". La premiere liste doit être la valeur
   la plus petite, la dernière, la plus grande
4/ Bonus si bouclé, le dernier pointe sur le premier et inversement
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct type_lst type_lst;

struct type_lst {
    int nbr;
    type_lst *next;
};

int intComparator(const void *first, const void *second) {
    int firstInt = *(const int *) first;
    int secondInt = *(const int *) second;
    return firstInt - secondInt;
}

int main(void) {
    int array_int[5] = {4, 5, 3, 2, 1};
    
    qsort(array_int, 5, sizeof(int), intComparator);

    type_lst *lst1 = (type_lst *) malloc(sizeof(type_lst));
    type_lst *lst2 = (type_lst *) malloc(sizeof(type_lst));
    type_lst *lst3 = (type_lst *) malloc(sizeof(type_lst));
    type_lst *lst4 = (type_lst *) malloc(sizeof(type_lst));
    type_lst *lst5 = (type_lst *) malloc(sizeof(type_lst));
 
    lst1->nbr = array_int[0];
    lst2->nbr = array_int[1];
    lst3->nbr = array_int[2];
    lst4->nbr = array_int[3];
    lst5->nbr = array_int[4];
 
    lst1->next = lst2;
    lst2->next = lst3;
    lst3->next = lst4;
    lst4->next = lst5;
    lst5->next = lst1; 

    
    type_lst *lst = lst1;
    do {
        printf("Le nombre = %i\n", lst->nbr);
        lst = lst->next;
    } while (lst != lst1);

    
    free(lst1);
    free(lst2);
    free(lst3);
    free(lst4);
    free(lst5);

    return 0;
}