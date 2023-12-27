#include <stdio.h>
#include <stdlib.h>
#include "Electronics.h"


int main() {
  Electronics* e1 = new TV(560);
  Electronics* e2 = new Cellphone(200);
  Laptop * e3 = new Laptop(230);


  Computer * GPU1 = new Computer(10);
  Computer * GPU2 = new Computer(80);


  e3->AddGPU(GPU1);
  e3->AddGPU(GPU2);


  e1->PrintSelf();
  e2->PrintSelf();
  e3->PrintSelf();


  delete e1;
  delete e2;
  delete e3;
  delete GPU1;
  delete GPU2;


  return EXIT_SUCCESS;
}
