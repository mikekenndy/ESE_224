#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() :root() {}

BinaryTree::BinaryTree(const BinaryTree& other)
{
  root = other.root;
}

void BinaryTree::insert(int value)
{
  if (root == nullptr)
    root = new Node(value);
  else
    insert(value, root);
}

void BinaryTree::insert(int value, Node* rt)
{
  if (value < rt->getData())
    {
      if (rt->getLeft() == nullptr)
	rt->setLeft(new Node(value));
      else
	insert(value, rt->getLeft());
    }
  else
    {
      if (rt->getRight() == nullptr)
	rt->setRight(new Node(value));
      else
	insert(value, rt->getRight());
    }
}

void BinaryTree::inOrderPrint()
{
  inOrder(root);
}

void BinaryTree::inOrder(Node* rt)
{
  if (rt == nullptr)
    return;
  inOrder(rt->getLeft());
  cout << rt->getData() << ' ';
  inOrder(rt->getRight());
}

void BinaryTree::preOrderPrint()
{
  preOrder(root);
}

void BinaryTree::preOrder(Node* rt)
{
  if (rt == nullptr)
    return;
  cout << rt->getData() << ' ';
  preOrder(rt->getLeft());
  preOrder(rt->getRight());
}

void BinaryTree::postOrderPrint()
{
  postOrder(root);
}

void BinaryTree::postOrder(Node* rt)
{
  if (rt == nullptr)
    return;
  postOrder(rt->getLeft());
  postOrder(rt->getRight());
  cout << rt->getData() << ' ';
}
