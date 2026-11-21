#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

int main() {
  int a = 10;
  int b = 20;

  swap(&a, &b);
  printf("a = %d b = %d\n", a, b);
}
