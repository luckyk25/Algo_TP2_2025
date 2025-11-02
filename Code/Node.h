#pragma once
#include "Block.h"

typedef Block Content; // Assuming Content is an int for simplicity

class Node
{
public:
  Node();
  ~Node();
  Node* getNext() const;
  void setNext(Node* _next);
  const Content& getContent() const;
  Content& getContent() ;
  void setContent(const Content& _content);

private:
  Content content; 
  Node* next; 
};


