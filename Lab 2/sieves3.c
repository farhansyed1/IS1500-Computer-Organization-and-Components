/*
  Farhan Syed
  Abhinav Sasikumar
  
  2022
*/
#include <stdio.h> 
#include <stdlib.h>
#include "print-primes.c"


void print_sieve(int n){
    int primes[n-1];

    // Initializes array to 1
    for(int i = 2; i <= n; i++){
        primes[i-2] = 1;
    }

    // Sieve of Erast
    for(int i = 2; i*i <= n; i++){
        if(primes[i-2]){
            for(int j = 2*i; j <= n; j += i){
                primes[j-2] = 0;
            }
        }
        
    }
    int distance_count = 0;
    for(int i = 2; i < n; i++){
        if(primes[i-2]){
                for(int j = i; j < i+5 ; j++ ){
                    if(primes[j-2] && j - i == 4){
                        distance_count++;
                    } 
                }
                print_number(i);
            }       
    }

    printf("Prime numbers that have the distance 4: %d\n", distance_count);
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
 if(argc == 2){
    print_sieve(atoi(argv[1]));
  }
    
  else
    printf("Please state an integer number.\n");
  return 0;
}