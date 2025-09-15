#include<iostream>
#include<cstddef>
class Narray{

private:
  std::size_t m_length{};
  double* data;

public:
  Narray():=default;
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

  Narray operator+(const Narray a,const                              Narray b){
    m_length=a.length()+b.length();
    data =new double[m_length]();
    for(int i=0;i<a.m_length;++i){
      data[i]=a.data[i];
    }
   for(int i=a.m_length;i<m_length;++i){
       data[i]=b.data[i-a.m_length];

  }
    return *this;
  }
  //overload assignment





  std::size_t length(){
    return m_length;
  }



};//class ends
