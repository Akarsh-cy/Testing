#include<iostream>
#include<vector>

class Parent{
    public:
        int value;
        std::vector<Parent*> child;
    Parent(int val):value{val}{
for(auto thing:child){thing=nullptr;}
    }

    void join(Parent* obj){
    child.push_back(obj);
    }


};

void printTree(Parent* root){
if(root==nullptr){return;}

std::cout<<" ";
std::cout<<root->value;
for(auto item:root->child){
printTree(item);
}

}




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

void printBtree(Node* root){
if(root==nullptr)return;

std::cout<<root->data;
printBtree(root->left);
printBtree(root->right);
}

std::vector<Parent> make(int n){
std::vector<Parent> obj;
obj.reserve(n);
for(int i=0;i<n;++i){
obj.push_back(Parent(i+1));
}
return obj;
}

int main(){
Node root=Node(6);
Node l=Node(7);
Node r=Node(8);

root.left=&l;
root.right=&r;

//printBtree(&root);

//general tree
std::vector<Parent> vec=make(8);

vec[0].join(&vec[1]);
vec[0].join(&vec[2]);

vec[1].join(&vec[3]);

vec[1].join(&vec[4]);

vec[1].join(&vec[5]);

vec[2].join(&vec[6]);
vec[2].join(&vec[7]);

printTree(&vec[0]);





}
