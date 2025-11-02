#pragma once
#include "DataStructure.h"

class Queue : public DataStructure
{
public:
  Queue();
  Queue(const Queue& src);
  ~Queue();
  bool operator==(const Queue& queue) const;
  void push_back(const Content& _content);
  void pop_front();
  const Content& front() const;
  void display() const override;
  const Node* getLastNode() const;
  Node* getLastNode();

  void clear();
private:
};


