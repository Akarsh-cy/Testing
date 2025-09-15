#include<iostream>
#include<cstddef>
class Narray{

private:
  std::size_t m_length{};
  double* data;

public:
  Narray():
    m_length{0},data{nullptr}
    {
    }

  //default constructor

  Narray(std::size_t size){

    if(size>0){
      data=new double[size]();
      m_length=size;
  }
  }
  //construstor no 2

 ~Narray(){
   delete[] data;
  }
  //destroyer


friend  Narray operator+(const Narray a,                        const Narray b);



  std::size_t length()const{
    return m_length;
  }



};//class ends


  Narray operator+(const Narray a,const                              Narray b){
  Narray obj;
    obj.m_length=a.length()+b.length();
   obj.data =new double[obj.m_length]();
    for(int i=0;i<a.m_length;++i){
      obj.data[i]=a.data[i];
    }
for(int i=a.m_length;i<obj.m_length;++i){
       obj.data[i]=b.data[i-a.m_length];

  }
    return obj;
  }
  //overload assignment

int main(){

}
