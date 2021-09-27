#include <stdio.h>

int main(){
  int i;
  float f;
  char c;

  i = 55;
  f = 8.125;
  c = 'o';

  printf("i: %d\t f: %f\t c: %c\t \n", i, f, c);
  printf("i: %03d\t f: %0.2f\t c: %c\t \n", i, f, c);
  
  printf("i: %d\t f: %f\t c: %c\t \n", f, i , c);
}
