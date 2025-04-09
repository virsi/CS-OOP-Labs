#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>

#include "myvector.h"

class MySet : public MyVector {
 public:
  MySet(char *el = NULL) : MyVector(el){};
  bool operator==(MySet &s);
  MySet &operator+=(MySet &s);
  MySet &operator-=(MySet &s);
  MySet &operator*=(MySet &s);
  void add_element(char *el);
  void delete_element(char *el);
  bool is_element(char *el);
  friend std::ostream &operator<<(std::ostream &out, MySet &s);
  friend MySet operator+(MySet &s1, MySet &s2);
  friend MySet operator-(MySet &s1, MySet &s2);
  friend MySet operator*(MySet &s1, MySet &s2);
};

#endif  // INHERITANCE_MYSET_H
