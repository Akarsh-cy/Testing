#include<iostream>
#include<algorithm>
#include<string>

class Tree{
    public:
        int m_key;
        std::string m_value;
        Tree* m_left;
        Tree* m_right;

    Tree(int key=0,std::string value="default"):m_key{key},m_value{value}
     {
      m_left=nullptr;
      m_right=nullptr;
     }
  ~Tree()=default;
};

//height recursive
int height(Tree* root){
  if(root==nullptr){return 0;}
  int subleft=height(root->m_left);
  int subright=height(root->m_right);
  return 1+std::max(subleft,subright);
}

//searxh using key
std::string search(const int key,Tree* root){
 
  if(root==nullptr){return "Not found";}
  if(key==root->m_key){return root->m_value;}
  if(key<root->m_key){
    return search(key,root->m_left);
  }
  return search(key,root->m_right);
}

void insert(Tree* src,Tree*& root){
  //already exist case
  if(root==nullptr){root=src;
    return;
  }
  else if(src->m_key==root->m_key){
    return;
  }
  else if(src->m_key<root->m_key){
    insert(src,root->m_left);
    return;
  }
  else {
    insert(src,root->m_right);
    return;
  }
return;
}

// gives a pointer to minimum node

Tree* find_min(Tree* root){
  
  if(root==nullptr){return root;}

  if(root->m_left==nullptr){
    return root;
  }

  return find_min(root->m_left);

}//find_min function end


//delete node with a key and tree root
void delete_node(const int& key,Tree*& root){

  //default key not supported
  if(key==0){return;}
  else if(root==nullptr){return;}


  if(key<root->m_key){
    delete_node(key,root->m_left);
  }
  else if(key>root->m_key){
    delete_node(key,root->m_right);
  }
  //handles the main deletion process
  else {

  //no children case
  if(root->m_left==nullptr&&root->m_right==nullptr){
delete root;
    }

  //only left child
  else if(root->m_left!=nullptr&&root->m_right==nullptr){
     Tree* temp=root;
     root=root->m_left;
     delete temp;
    }

  //only right child

  else if(root->m_left==nullptr&&root->m_right!=nullptr){
     Tree* temp=root;
     root=root->m_right;
     delete temp;
    }

  //both child
  else{
    //storing the node in temp
    Tree* temp=find_min(root->m_right);
    root->m_value=temp->m_value;
    root->m_key=temp->m_key;
    delete_node(temp->m_key,root->m_right);
    }

    }//main functional body end
 

}//delete function end




int main(){}
