#include<vector>
#include<iostream>
using std::vector;
namespace Custom{

template<typename T>
void display_reverse(vector<T>& v){
for(std::size_t i=std::size(v);i>0;i--){
      std::cout<<v[i-1]<<",";
   }
   }//fn ends

vector<float> reverse(vector<float> v){
      vector<float> s(v.size());
      for(int i =v.size();i>0;i--){
         s[v.size()-i]=v[i-1];
      }
      return s;
   }//fn ends


}//namespace ends
int main(){
vector v{1,2,3,4,5,6,7,8,9,10};
//Custom::display_reverse(v);
Custom::reverse(v);

}
