#include "Node.h"

class BinaryTree
{
 private:
  Node* root;
  void insert(int value, Node* rt);
  void inOrder(Node* rt);
  void preOrder(Node* rt);
  void postOrder(Node* rt);
 public:
  BinaryTree();
  BinaryTree(const BinaryTree& other);
  void insert(int value);
  void inOrderPrint();
  void preOrderPrint();
  void postOrderPrint();
};
