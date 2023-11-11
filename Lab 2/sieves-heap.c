/*
  Farhan Syed
  Abhinav Sasikumar
  
  2022
*/

#include <stdio.h> 
#include <stdlib.h>
#include "print-primes.c"

void print_sieve(int n){
    int* primes = malloc((n-1)*sizeof(int));

    for(int i = 0; i < n; i++){
        primes[i] = 1;
    }

    for(int i = 2; i*i < n; i++){
        if(primes[i-2]){
            for(int j = 2*i; j < n; j += i){
                primes[j-2] = 0;
            }
        }
        
    }

    for(int i = 2; i < n; i++){
        if(primes[i-2]){
            print_number(i);
        }
    }

    free(primes);
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
 if(argc == 2){
    print_sieve(atoi(argv[1]));
  }
    
  else
    printf("Please state an interger number.\n");
  return 0;
}