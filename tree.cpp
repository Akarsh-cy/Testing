#include<iostream>

class Node{

public:
  int data;
  Node* left;
  Node* right;
public:
  Node(int val):data{val}{
  left=nullptr;
  right=nullptr;
  }
};//class ends

void printTree(Node* root){
if(root==nullptr)return;

std::cout<<root->data;
printTree(root->left);
printTree(root->right);
}


int main(){
Node root=Node(6);
Node l=Node(7);
Node r=Node(8);

root.left=&l;
root.right=&r;

printTree(&root);
}
