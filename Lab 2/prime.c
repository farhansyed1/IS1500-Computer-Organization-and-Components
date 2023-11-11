/*
  Farhan Syed
  Abhinav Sasikumar
  
  2022
*/
#include <stdio.h>

int is_prime(int n){
  if(n == 1 || n == 0){
    return 0;
  }
  for(int i = 2;i < n;i++){
    if(n%i == 0) return 0;
  }

  return 1;
}

int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
  printf("%d\n", is_prime(1)); 
  
}
