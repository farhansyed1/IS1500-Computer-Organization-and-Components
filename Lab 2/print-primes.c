/*
  Farhan Syed
  Abhinav Sasikumar
  
  2022
*/
#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6
int counter;

void print_number(int number){
  if(counter == COLUMNS-1){       // if counter is currently 5, create new row
    printf("%d \n", number);
    counter = 0;
  }else{
    printf("%d \t", number);      //create new column
    counter++;
  }  
}

int is_prime(int n){
  if(n == 1 || n == 0){
    return 0;
  }
  for(int i = 2;i < n;i++){
    if(n%i == 0) return 0;
  }

  return 1;
}

void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS

  for(int i = 2;i < n;i++){
    if(is_prime(i)) {
      print_number(i);
    }
  }

}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
/*
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
} */

 
