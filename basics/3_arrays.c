#include <stdio.h>

int main() {
  int a[4];
  a[0] = 3;
  a[1] = 4;
  a[2] = 1;

  printf("%d\n", *a);
  printf("%d\n", *(a + 2));

  printf("size of array a: %lu\n", sizeof(a) / sizeof(int));
  return 0;
}
