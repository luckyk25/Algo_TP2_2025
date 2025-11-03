#pragma once
#include "Node.h"
#include "DataStructure.h"

using namespace std;
class Stack : public DataStructure
{
public:
  Stack();
  Stack(const Stack& src);
  ~Stack();
  bool operator==(const Stack& stack) const;
  const Content& top() const;
  void push(const Content& content);
  void pop();
  void clear();
  void display() const override;
};


