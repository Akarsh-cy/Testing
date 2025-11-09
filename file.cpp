#include<iostream>
#include<fstream>
#include<string_view>

int main(int argc,char* argv[]){

if(argc<3){
    std::cerr<<"Insufficient arguments"
             <<"to main provided\n";
  }
else if(argc>3){
    std::cerr<<"Too many arguments to "
            <<"main provided\n";
  }
  std::string_view filename=argv[2];
  std::string_view mode=argv[1];


if(mode=="append"){
    std::ofstream output(filename,std::ios::app);
   if(output.is_open()){
     std::cout<<"Enter string to appen"
              <<"d to file:"<<filename
              <<"\n";
    std::string content;
    std::getline(std::cin,content);
    output<<content;
    output.close();
    }
   else{
    std::cerr<<"File:"<<filename
             <<"could not be opened\n";
    }
  }


  else if(mode=="write"){
    std::ofstream output(filename);
   if(output.is_open()){
     std::cout<<"Enter string to overwr"
              <<"ite to file:"<<filename
              <<"\n";
    std::string content;
    std::getline(std::cin,content);
    output<<content;
    output.close();
    }
   else{
    std::cerr<<"File:"<<filename
             <<"could not be opened\n";
    }
  }


  else if(mode=="read"){
   
    std::ifstream input(filename);

if(input){
std::string content;
std::string line;

while(std::getline(input,line)){
content+=line+"\n";
    }
    std::cout<<content;
    std::cout<<"Done succesfully!\n";
    }
else{
     std::cerr<<"Could not read file\n";
    }
  }

  else {
    std::cerr<<"the mod "<<argv[1]
             <<" provided aint vailable\n";
  }


}//main end
//comment at end