#include<iostream>
#include<vector>

//singly linked list
class Node{

private:
    int value;
    Node* ptr;
public:
Node(int val):value{val}{ptr=nullptr;}


void add(Node& n){
ptr=&n;

}

void go(){
    std::cout<<"[";

while(ptr!=nullptr){
    std::cout<<value<<" ";
*this=*ptr;
}

if(ptr==nullptr){std::cout<<value<<" ";}
std::cout<<"]"<<std::endl;


}//transverse ends
};//class node ends

void stich(Node& head,std::vector<Node>& body){

for(int i=0;i<body.size()-1;++i){
body[i].add(body[i+1]);
}
head.add(body[0]);
}


