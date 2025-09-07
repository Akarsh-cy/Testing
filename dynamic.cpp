#include<iostream>
class Matrix{
 private:
  std::size_t row{};
  std::size_t col{};
  double **matrix;
  //data members
 public:
  Matrix(std::size_t r,std::size_t c){
   row=r;
   col=c;
   matrix = new double* [r];
  for(std::size_t i=0;i<r;i++){
   matrix[i]= new double [c]();
   }//for ends
  }//construtor ends
 
//copy constructor
  Matrix(const Matrix& source){
   this->row=source.row;
   this->col=source.col;
   matrix = new double *[source.row];
  for(std::size_t i=0;i<row;i++){
   matrix[i]=new double [source.col];
   }//for ends

  for(std::size_t i=0;i<row;i++){
  for(std::size_t j=0;j<col;j++){
   matrix[i][j]=source.matrix[i][j];
  }//nested for ends
  }//for ends
  }//copy constructor ends


//assignment overload constructor
Matrix& operator=(const Matrix& source){
//self assigment check
if(this==&source){
   return *this;
}//if ends
//delete default
for(std::size_t i=0;i<row;i++){
 delete [] matrix[i];
}//for ends
 delete[]matrix;
//deletdefault ends
//copy part
this->row=source.row;
   this->col=source.col;
   matrix = new double *[source.row];
  for(std::size_t i=0;i<row;i++){
   matrix[i]=new double [source.col];
   }//for ends

  for(std::size_t i=0;i<row;i++){
  for(std::size_t j=0;j<col;j++){
   matrix[i][j]=source.matrix[i][j];
  }//nested for ends
  }//for ends
return *this;
}//assigment ends


~Matrix(){
for(std::size_t i=0;i<row;i++){
 delete [] matrix[i];
}//for ends
 delete[]matrix;
}//destructor ends
};//class ends

int main(){
}
