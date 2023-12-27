#include "myset.h"

void MySet::Insert(int data) {
  // TODO: insert 'data' into set
  if (rbt->Search(rbt->GetRoot(),data)==NULL){
    rbt->Insert(data);
    size++;
  }
}

void MySet::Erase(int data) {
  // TODO: erase 'data' from set
  if ((rbt->Search(rbt->GetRoot(),data))!= NULL){
    rbt->Delete(rbt->Search(rbt->GetRoot(),data));
    size--;
  }
}

bool MySet::Find(int data) {
  // TODO: return true if 'data' exists in the set
  if (rbt->Search(rbt->GetRoot(),data)==NULL){return false;}
  else {return true;}
}

size_t MySet::Size() {
  // TODO: return number of elements in the set
  return this->size;
}
