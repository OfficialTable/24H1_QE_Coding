#include <stdio.h>
#include <stdlib.h>
#include "Electronics.h"


int main() {
  Electronics* e1 = new TV(710);
  Electronics* e2 = new Cellphone(110);
  Laptop * e3 = new Laptop(360);


  Computer * GPU1 = new Computer(70);


  e3->AddGPU(GPU1);


  e1->PrintSelf();
  e2->PrintSelf();
  e3->PrintSelf();


  delete e1;
  delete e2;
  delete e3;
  delete GPU1;


  return EXIT_SUCCESS;
}
