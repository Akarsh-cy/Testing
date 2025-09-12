#include<iostream>
using std::size_t;

class Matrix{
  private:

    size_t row;
    size_t col;
    double** data;
    public:


//Constructor
  Matrix(size_t row=1,size_t col=1){
    if(r!=0 && c!=0)
      {
      row{r};
      col{c};
      data=new double*[r];
    for(size_t i=0;i<r;++i){
      data[i]=new double[c]();
      }//for ends
}//if ends
    else:
      std::cout<<"error";
}//constructor ends


//Destructor
 ~Matrix(){
    for(size_t i=0;i<r;++i){
      delete []data[i];
    }//for ends
      delete []data;
}//destructor


//Copy Constructor
  Matrix(const Matrix& m){
  if( m.row!=0 && m.col !=0){
    this->row=m.row;
    this->col=m.col;
    this->data =new double*[row];
    for(size_t i=0;i<row;++i){
      this->data[i]=new double[col]();
    }//for ends
    for(size_t i=0;i<row;++i){
      for(size_t j=0;j<col;++j){
        data[i][j]=m.data[i][j];
      }//nested for ends
    }// for ends
  }//copy constructor ends


//Copy Assignment operator
Matrix& operator=(const Matrix& m){
    if(this==&m){
      return *this;
    }//self assignment checked
if(this->row==m.row&& this->col==m.col){

  for(size_t i=0;i<row;++i){
        delete [] data[i];
      }//for ends
   delete[] data;
      data =new double*[row];
   for(size_t i=0;i<row;++i){
      this->data[i]=new double[col]();
    }//for ends
    for(size_t i=0;i<row;++i){
      for(size_t j=0;j<col;++j){
        data[i][j]=m.data[i][j];
      }//nested for ends
    }// for ends
    }//big if block ends
  }//assigment Constructor ends


//Move Constructor
  Matrix(Matrix&& m){
    this->row=m.row;
    this->col=m.col;
    this->data=m.data;
    m.data=nullptr;
  }//Move Constructor ends


//Move Assignment operator
  Matrix& operator=(const Matrix& m){
    this->row=m.row;
    this->col=m.col;
    this->data=m.data;
    m.data=nullptr;

  }//Move Assigmrnt operator ends

};//class ends
