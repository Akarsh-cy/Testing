#include<iostream>
#include<cmath>
namespace Dim_3{
//whitespace
    struct Vector{
     double x{};
     double y{};
     double z{};
     };//struct ends
//functions
    double length(Vector& v){
     return std::hypot(v.x,v.y,v.z);
     }//fn ends
    Vector scale(Vector& v,double p){
     return {v.x*p,v.y*p,v.z*p};
     }//fn ends
    

};//namespace ends
int main(){
using namespace Dim_3;
return 0;
}
