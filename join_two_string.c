#include <stdlib.h> 
#include <stdio.h>

char *join_two_string (char const *s1, char const *s2) {
    char *ret;
    int len = 0;
    int j = 0;
    
    

    while (s1[len] != '\0')
        len++;
    while(s2[j] != '\0'){
       j++;
       len++; 
    }
    len = len + 1;
    
    ret = (char *)malloc(sizeof(char)  * len);
    len = 0;
    while (s1[len]) {
        ret[len] = s1[len] ;
        len ++;
    }
    j = 0;
    while (s2[j] != '\0') {
        ret[len] = s2[j] ;
        j++;
        len ++;
    }
    return(ret);
}

int main (void) {
    char *join;

    join = join_two_string ("hello", "world");
    printf ("%s\n", join);
    if(join)
        free(join);
}