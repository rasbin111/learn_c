#include <stdio.h>

struct Student {
  char *name;
  int age;
  char *address;
};

void printInfo(struct Student *self) {

  printf("%s\n", self->name);
  printf("%d\n", self->age);
  printf("%s\n", self->address);
}

int main() {
  struct Student s1;
  s1.name = "Abhisek";
  s1.age = 10;
  s1.address = "Dolakha";

  printInfo(&s1);

  return 0;
}
