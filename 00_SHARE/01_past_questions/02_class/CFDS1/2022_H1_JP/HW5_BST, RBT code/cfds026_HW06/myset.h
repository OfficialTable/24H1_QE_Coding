#pragma once

#include "bst.h"
#include "rbt.h"

class MySet {
  RBT* rbt;
  size_t size;
public:
  MySet(){rbt = new RBT(); size = 0;}
  void Insert(int data);
  void Erase(int data);
  bool Find(int data);
  size_t Size();
};
