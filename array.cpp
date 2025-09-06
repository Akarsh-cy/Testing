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

template<typename T>
   vector<T> reverse(vector<T>& v){
   const std::size_t size{std::size(v)};
   std::cout<<size;
   vector<auto> c(size,0)
   for(std::size_t i=0;i<size;i++){
   c[i]=v[size-i];
   }//for ends



   }//fn ends









}//namespace ends
int main(){
vector v{1,2,3,4,5,6,7,8,9,10};
//Custom::display_reverse(v);
 vector s{Custom::reverse(v)};
 std::cout<<v<<"nigger\n"<<s;

}
