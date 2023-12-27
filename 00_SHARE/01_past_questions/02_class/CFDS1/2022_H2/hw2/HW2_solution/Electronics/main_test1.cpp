#include <stdio.h>
#include <stdlib.h>
#include "Electronics.h"


int main() {
  Electronics* e1 = new TV(500);
  Electronics* e2 = new Cellphone(180);
  Laptop * e3 = new Laptop(390);

  e1->PrintSelf();
  e2->PrintSelf();
  e3->PrintSelf();

  delete e1;
  delete e2;
  delete e3;

  return EXIT_SUCCESS;
}