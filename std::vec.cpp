#include<iostream>
#include<vector>
struct Point{
   double m_x{0};
   double m_y{0};
   double m_z{0};
   Point()=default;
   Point(double x,double y,double z)
      : m_x{x},m_y{y},m_z{z} {}
};
int main(){
   std::vector<Point> p(10);
   for(int i=0;i<p.size();i++){
      p[i]=Point(i,i+1,i+2);
   }

   for(int i=0;i<p.size();i++){
std::cout<<"("<<p[i].m_x<<","
           <<p[i].m_y<<","
	   <<p[i].m_z<<")\n";
   }
}
