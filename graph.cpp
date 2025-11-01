#include<vector>
#include<iostream>

class Node{
    public:
        int value;
        std::vector<Node*> edge;

    Node(int val):value{val}{
      for(auto item: edge)
      item=nullptr;
    }

    void join(Node*a,int index){
this->edge[index]=a;
    }

};//class ends



std::vector<Node> make(int size){
    std::vector<Node> obj;
    obj.reserve(size);
    for(int i=0;i<size;++i)
        obj[i]=Node(i+1);
    return obj;
}

void printGraph(Node* root){

if(root==nullptr){return;}

std::cout<<root->value<<" ";
for(auto item:root->edge){
printGraph(item);

}//for loop ends

}




std::vector<int> solver(Node* start){
    std::vector<int> sol;
    sol.reserve(10);

if(start==nullptr){
if(sol.at(0)==sol.at(sol.size()-1))
return sol;
}

sol.push_back(start->value);

for(auto item:start->edge){
    sol=solver(item);
    sol.erase(sol.begin()+1,sol.end());
}
std::vector<int> noans(0);

return noans;
}

int main(){
auto i=make(12);

i[0].join(&i[3],0);
i[0].join(&i[1],1);
i[1].join(&i[2],0);

i[1].join(&i[4],1);
i[3].join(&i[7],0);
i[7].join(&i[8],0);
i[8].join(&i[9],0);
i[9].join(&i[10],0);
i[10].join(&i[11],0);

i[4].join(&i[6],0);
i[4].join(&i[5],0);

i.push_back(Node(1));
i[11].join(&i[12],0);


auto sol=solver(&i[0]);
for(auto item:sol){
    std::cout<<item<<" ";

}
std::cout<<std::endl;







}
