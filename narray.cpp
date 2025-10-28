#include<iostream>
#include<cstddef>

template<typename>
class Narray{
private:
    std::size_t m_length;
    std::size_t m_capacity;
    T* data;

public:

Narray()=default
:m_length{0},data{nullptr},m_capacity{0}
  {
  }//default constructor

  Narray(std::size_t c)
  :m_capacity{c},m_length{0}
  {
    data =new T[m_capacity](0);
  }//construct capacity c

 ~Narray(){
    delete[] data;
  }//destructor


//copy constructor
Narray(const Narray& source){
assert(this->m_capacity==source.m_capacity){
  this->m_length=source.m_length
  for(int i=0;i<m_length;++i){
    data[i]=source.data[i];
      }//for ends
    }//if ends
  }
//copy constructor ends


//copy assignment
Narray& operator=(const Narray& source){
if(this==&source){
  return *this;
    }// self assignment done

//clean
if(data){
      delete[] data;
    }
this->m_capacity=source.m_capacity;
this->m_length=source.m_length;
this->data=new T[capacity]();
for(int i=0;i<m_length;++i){
data[i]=source.data[i];
    }//for ends
  return *this;
  }
//copy assignment done


//move operator
Narray& operator=(const Narray& source)
noexcept
  {
 if(this==&source){
      return *this;
    }//self assignment
this->m_capacity=source.m_capacity;
this->m_length=source.m_length;
    if(data){
      delete[]data;
    }
data=source.data;
source.m_capacity=0;
source.m_length=0;
source.data=nullptr;


return *this;
  }//move operator ends






};//class ends
