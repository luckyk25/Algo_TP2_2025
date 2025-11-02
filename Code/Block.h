#pragma once
#include <iostream>

struct Block
{
  int row;
  int col;
  char value;

  inline Block(int r=-1, int c=-1, char v=-1) : row(r), col(c), value(v) {}
  inline void display() const{
    std::cout << "[" << row << ", " << col << ", " <<"\033[32m"<< value<<"\033[0m" << "]" << std::endl;
  }
}; 

inline bool operator==(const Block& lhs, const Block& rhs)
{
  return lhs.value == rhs.value && lhs.row == rhs.row && lhs.col == rhs.col ;
}