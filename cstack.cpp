#include<iostream>
#include<cstddef>
class Darray{

private:
  std::size_t fill;
  std::size_t m_length;
  double* data;
public:
  Darray()
    :fill{0},m_length{0},data{nullptr}
    {
    }
  Darray(std::size_t len)
    :fill{0},m_length{len}
    {
    data =new double[len]();
    }
 ~Darray(){
    delete []data;
    }


friend std::ostream& operator<<(std::ostream& out,const Darray& sos);



  //functions

  void push(double value){
    if(fill<(m_length)){
    data[fill]=value;
    ++fill;
    }
    else{
    std::cout<<"push failed too much"
             <<" stuff pop plz\n";
    }
  }
  void pop(){
    if(fill>0){
    data[fill-1]=0;
    --fill;
    }
    else{
      std::cout<<"Already poped\n";
    }
  }


  void display(){
    std::cout<<"[";
    for(std::size_t i=0;i<m_length;++i){
      std::cout<<data[i]<<" ";
    }
    std::cout<<"]\n";
  }//fn ends


 // void length(){
   // std::cout<<m_length<<"\n";}
  double length(){return m_length;}

//   void space(){
  //  std::cout<<fill<<"\n";}
  double space(){return m_length-fill;}

 void see(){
std::cout<<"length: "<<m_length<<"\n";
std::cout<<"space: "
         <<m_length-fill<<"\n";
  this->display();
  }


};//class ends




int main(){
Darray n(1);
n.see();
  n.push(1);
  n.see();
  n.push(2);
  n.see();
  n.pop();
  n.pop();
  n.see();

}
