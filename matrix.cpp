#include<iostream>
using std::size_t;

class Matrix{
  private:

    size_t row;
    size_t col;
    double** data;
    public:


//Constructor
  Matrix(size_t r=1,size_t c=1){
    if(r!=0 && c!=0)
      {
      row{r};
      col{c};
      data=new double*[r];
    for(size_t i=0;i<r;++i){
      data[i]=new double[c]();
      }//for ends
}//if ends
    else{
      std::cout<<"error\n";
      row=col=0;
      data=nullptr;
  }//else ends
}//constructor ends


//Destructor
 ~Matrix(){
    if(data){
    for(size_t i=0;i<r;++i){
      delete []data[i];
    }//for ends
      delete []data;
  }
}//destructor


//Copy Constructor
  Matrix(const Matrix& m)
    :row{m.row},col{m.col},data{nullptr}
{
  if( m.row!=0 && m.col !=0){
    this->data =new double*[row];
    for(size_t i=0;i<row;++i){
      this->data[i]=new double[col]();
      for(size_t j=0;j<col;++j){
        data[i][j]=m.data[i][j];
      }//nested for ends
    }// for ends
   }//if ends
  }//copy constructor ends


//Copy Assignment operator

Matrix& operator=(const Matrix& m){
    if(this==&m){
      return *this;
    }//self assignment checked

//clean previous record
if(data){
    for(size_t i=0;i<row;++i){
      delete[]data[i]
    }//for ends
      delete[] data;
  }//if ends

row=m.row;
col=m.col;
data=nullptr;

if(row!=0 && col!=0){
    data=new double*[row];
    for(size_t i=0;i<row;++i){
      data[i]=new double[col]();
      for(size_t j=0;j<col;++j){
        data[i][j]=m.data[i][j];


      }//for ends
    }//for ends
    return *this;
  }//if ends







//Move Constructor
  Matrix(Matrix&& m)
    noexcept:row{m.row},col{m.col},data{m.data}
  {
    m.row=0;
    m.col=0;
    m.data=nullptr;
  }//Move Constructor ends


//Move Assignment operator
  Matrix& operator=(const Matrix&& m)
  noexcept
  {
    if(this==&m){
      return *this;
    }//if ends

//cleaning exist data
  if(data){
      for(size_t i=0;i<row;++i){
        delete[] data[i];
      }//for ends
     delete[] data;
    }
row=m.row;
col=m.col;
data=m.data;

m.row=0;
m.col=0;
m.data=nullptr;

return *this;
  }//Move Assigmrnt operator ends

};//class ends
