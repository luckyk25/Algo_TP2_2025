#include "stdafx.h"
#include "Stack.h"
#include <iostream>

Stack::Stack()
  : DataStructure()
{

}

Stack::Stack(const Stack& src)
	: DataStructure()
{
	if (!src.isEmpty()) {
		setFirstNode(new Node());
		getFirstNode()->setContent(src.getFirstNode()->getContent());

		Node* currentSrc = src.getFirstNode()->getNext();
		Node* currentDest = getFirstNode();

		while (currentSrc != nullptr) {
			Node* newNode = new Node();
			newNode->setContent(currentSrc->getContent());
			currentDest->setNext(newNode);
			currentDest = newNode;
			currentSrc = currentSrc->getNext();
		}
	}
}

Stack::~Stack()
{
	while (!this->isEmpty())
	{
		this->pop();
	}
}


bool Stack::operator==(const Stack& Stack) const
{
  const Node* current = getFirstNode();
  const Node* otherCurrent = Stack.getFirstNode();
  while (current != nullptr && otherCurrent != nullptr)
  {
    if (current->getContent() != otherCurrent->getContent())
    {
      return false;
    }
    current = current->getNext();
    otherCurrent = otherCurrent->getNext();
  }
  return current == nullptr && otherCurrent == nullptr;
}


void Stack::push(const Content& content)
{
	Node* node = new Node();
	node->setContent(content);
	node->setNext(getFirstNode());
	setFirstNode(node);
}

void Stack::pop()
{
	if (this->isEmpty())
	{
		throw std::runtime_error("Empty Stack");
	}
	Node* node = getFirstNode();
	setFirstNode(getFirstNode()->getNext());
	delete node;
	return;
}

const Content& Stack::top() const
{
	if (this->isEmpty())
	{
		throw std::runtime_error("Empty Stack");
	}
	return getFirstNode()->getContent();
}

void Stack::display() const
{
	const Node* current = getFirstNode();
	std::cout << "[" << std::endl;
	while (current != nullptr)
	{
		current->getContent().display();
		current = current->getNext();
	}
	std::cout << "]" << std::endl;
	return;
}

void Stack::clear()
{
	while (!isEmpty()) {
		pop();
	}
}