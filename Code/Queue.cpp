#include "stdafx.h"
#include "Queue.h"
#include <stdexcept>
#include <iostream>
Queue::Queue()
  : DataStructure()
{
  //TODO : Constructeur par d�faut selon les sp�cifications

}

Queue::Queue(const Queue& src)
{

}

Queue::~Queue()
{
	while (!this->isEmpty())
	{
		Node* node = getFirstNode();
		setFirstNode(getFirstNode()->getNext());
		delete node;
	}
}

bool Queue::operator==(const Queue& queue) const
{
  bool areEquals = size() == queue.size();
  //TODO : Surcharge de l'op�rateur == selon les sp�cifications
  const Node* current = getFirstNode();
  const Node* otherCurrent = queue.getFirstNode();
  while (current != nullptr && otherCurrent != nullptr && areEquals)
  {
    if (current->getContent() != otherCurrent->getContent())
    {
      areEquals = false;
    }
    current = current->getNext();
    otherCurrent = otherCurrent->getNext();
  }
  return areEquals;
}


const Node* Queue::getLastNode() const
{
  const Node* current = getFirstNode();
  if (current != nullptr)
  {
    while (current->getNext() != nullptr)
    {
      current = current->getNext();
    }
  }

  return current;
}

Node* Queue::getLastNode()
{
  Node* current = getFirstNode();
  if (current != nullptr)
  {
    while (current->getNext() != nullptr)
    {
      current = current->getNext();
    }
  }

  return current;
}

void Queue::push_back(const Content& _content)
{
	Node* node = new Node();
	node->setContent(_content);
	node->setNext(nullptr);

	if (getFirstNode() == nullptr)
	{
		setFirstNode(node);
		return;
	}

	Node* current = getFirstNode();
	while (current->getNext() != nullptr)
	{
		current = current->getNext();
	}
	current->setNext(node);
}

const Content& Queue::front() const
{
	if (isEmpty())
		throw std::out_of_range("Queue is empty");

	return getFirstNode()->getContent();
}

void Queue::pop_front()
{
	if (isEmpty())
		throw std::out_of_range("Queue is empty");
	Node* node = getFirstNode();
	setFirstNode(node->getNext());
	delete node;
}

void Queue::display() const
{
	const Node* node = getFirstNode();
	while (node != nullptr) {
		node->getContent().display();
		node = node->getNext();
	}
}

void Queue::clear()
{
	while (!isEmpty()) {
		pop_front();
	}
}