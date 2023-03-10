#include <stdio.h>

int fibonacci(int max_fib) {
    int ret_fib;
    int i;
    int a;

    ret_fib = 0;
    i = 0;
    a = 1;
    if (max_fib > 1) {
        while (max_fib > 1) {
            ret_fib = i + a ;
            i = a ;
            a = ret_fib ;
            max_fib -= 1 ;
        }
    } 
    else {
        return (max_fib) ;
        } 
    return (ret_fib) ;

}

int main (void) {
    int fib;

    fib = fibonacci(6);
    printf ("%i\n", fib);
    return (1);
}
