/*--------------------------------------------------------*/
/* class declaration for node:                            */
/* filename node.h                                        */

#ifndef NODE_H
#define NODE_H

class Node
{
  //Private attributes
 private:
  int data;
  Node *left;
  Node *right;
  
  //Public interface.
 public:
  Node(); //Default constructor
  Node(int); //Parameterized constructor
  
  //Accessors
  Node* getLeft() const;
  Node* getRight() const;
  int getData() const;
  
  //Mutators
  void setLeft(Node*);
  void setRight(Node*);
  void setData(int v);
};
#endif
/*---------------------------------------------------*/
