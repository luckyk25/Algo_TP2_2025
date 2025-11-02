#include "stdafx.h"
#include "Node.h"

Node::Node()
	: next(nullptr)
{
}


Node::~Node()
{
}

Node* Node::getNext() const
{
	return this->next;
}

void Node::setNext(Node* _next)
{
	this->next = _next;
}

const Content&  Node::getContent() const
{
	return this->content;
}

Content& Node::getContent() 
{
	return this->content;
}

void Node::setContent(const Content& _content)
{
	this->content = _content;
}


