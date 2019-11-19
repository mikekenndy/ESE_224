/*---------------------------------------------------*/
/* Class implementation for node                     */
/* filename: node.cpp                                */

#include "Node.h" //Required for Node.

//Constructors.
Node::Node() : data(0),left(0),right(0)
{}

Node::Node(int v):data(v), left(0), right(0)
{}

//Accessors
Node* Node::getLeft() const
{
  return left;
}

Node* Node::getRight() const
{
  return right;
}

int Node::getData() const
{
  return data;
}

//Mutators
void Node::setLeft(Node* l)
{
  left=l;
}

void Node::setRight(Node* r)
{
  right=r;
}

void Node::setData(int v)
{
  data=v;
}
/*--------------------------------------------------*/
