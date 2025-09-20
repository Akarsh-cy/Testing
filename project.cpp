#include<iostream>
#include<vector>
#include<memory>
#include<cmath>

//base abstract class
//contains pure function
class Shape{
public:
  virtual ~Shape()=default;
  virtual double getarea() const=0;
  virtual double getperimeter() const=0;
  virtual void draw() const=0;
};//shape class ends


class Circle:public Shape{
private:
  double m_radius;
public:

  Circle(double r):m_radius{r}{}
  virtual ~Circle() override= default;

  virtual double getarea()const override  {
    return 3.14159*m_radius*m_radius;
  }

  virtual double getperimeter()const override{
return 3.14159*m_radius*2;
  }

virtual void draw()const override{
    double r=m_radius;

  if (r>0){
    double t=r/2;
    for(int i=-r;i<r;++i){
      for(int j=-r;j<r;++j){
        if(std::abs(i*i+j*j-r*r)<=t){
          std::cout<<"0";
        }//if ends
        else{
          std::cout<<" ";
        }//else ends

      }//inner for ends
    std::cout<<"\n";
    }//outer for ends
  }//big if ends
else
{
std::cout<<std::endl;
std::cout<<"invalid circle terminated";
     }
  }
};


class Rectangle: public Shape{
private:
  double length;
  double width;
public:

Rectangle(double l,double w)
  : length{l},width{w}
  {
  }
virtual ~Rectangle() override=default;

virtual double getarea()const override{
return length*width;
}

virtual double getperimeter()const override{
return 2*(length+width);
}

void draw() const override{
    for(int i=0;i<width;++i){
      for(int j=0;j<length;++j){
      std::cout<<"#";
      }
      std::cout<<std::endl;
    }
  }
};//class ends

class Triangle:public Shape{
private:
  double a;
  double b;
  double c;
  double s;

public:
Triangle(double x=1,double y=1,double z=1)
  :a{x},b{y},c{z}
  {
    s=(a+b+c)/2;
  }

virtual ~Triangle() override=default;

virtual double getarea()const override{
return sqrt(s*(s-a)*(s-b)*(s-c));
}

virtual double getperimeter()const override{
return a+b+c;
}

void draw() const override{
    //abstracted middle pyramid
    int times=static_cast<int>(a);
    auto spacegive=[](int n){
      for(int i=0;i<n;i++){
        std::cout<<" ";
      }//for ends
    };//lambda ends
    auto pattern=[](int m){
      for(int i=0;i<m;i++){
        std::cout<<"#";
      }//for ends
    };//lambda ends

    for(int i=0;i<times;++i){
      spacegive(times-i);
      pattern(2*i+1);
      std::cout<<std::endl;
    }
  }//fn ends

};
int main(){

std::vector<std::unique_ptr<Shape>>
shape;

shape.push_back(std::make_unique<Circle>(6.9));
shape.push_back(std::make_unique<Rectangle>(7,6));
shape.push_back(std::make_unique<Triangle>(6));

for(auto& item:shape){
  std::cout<<"\n-----------------------"
           <<"\n";

  std::cout<<"The area of curve is:"
           <<item->getarea()
           <<"\n";
  std::cout<<"The peri of curve is:"
           <<item->getperimeter()
           <<"\n\n\n";
  std::cout<<"The curve has shape :"
           <<std::endl<<std::endl;
           item->draw();
    std::cout<<"\n---------------------"
             <<"\n\n";

  }
return 0;
}
