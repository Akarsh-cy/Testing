#include <vector>
#include <iostream>

class Node {
public:
    int value;
    std::vector<Node*> edge;

    Node(int val = 0) : value{val} {}

    void join(Node* a) {
        edge.push_back(a);
    }
};

std::vector<Node> make(int size) {
    std::vector<Node> obj;
    for (int i = 0; i < size; ++i)
        obj.emplace_back(Node(i+1));
    return obj;
}

std::vector<int> dfs_find(Node* root, std::vector<bool>& visited,int& target,std::vector<int>& path,int& nodeNumber){

if(root==nullptr && !path.empty()){
path.pop_back();
return path;
}



path.push_back(root->value);

if(path[path.size()-1]==target)return path;

if(root->value>visited.size()){
visited.resize(2*nodeNumber);
visited[root->value]=true;
}

if(root->value<=visited.size()){

if(!visited[root->value]){

visited[root->value]=true;
for(auto item:root->edge){

auto res=dfs_find(item,visited,target,path,nodeNumber);
if(!res.empty()){return res;}
}
 }
}

return {};//empty vector symbolizes not found

}
 





void dfs(Node* start, std::vector<int>& path) {
    if (start==nullptr) return;
    path.push_back(start->value);
    for (auto item : start->edge)
        dfs(item, path);
}

int main() {
    auto i = make(12);

    i[0].join(&i[3]);
    i[0].join(&i[1]);
    i[1].join(&i[2]);
    i[1].join(&i[4]);
    i[3].join(&i[7]);
    i[7].join(&i[8]);
    i[8].join(&i[9]);
    i[9].join(&i[10]);
    i[10].join(&i[11]);
    i[4].join(&i[6]);
    i[4].join(&i[5]);

    i.push_back(Node(13));
    i[11].join(&i[12]);

    std::vector<int> sol;
    dfs(&i[0], sol);

    for (auto item : sol)
        std::cout << item << " ";
    std::cout << std::endl;
}
