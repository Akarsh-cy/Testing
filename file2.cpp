#include<iostream>
#include<fstream>
#include<vector>
#include<string_view>
#include<algorithm>
int main(int argc,char* argv[]){

  if(argc>3){
    std::cerr<<"Function takes 2 args"
             <<" but "
             <<argc<<" were provided\n";
  }//if end brace
  else if(argc<3){
    std::cerr<<"Function takes 2 args"
             <<" but "
             <<argc<<" were provided\n";

  }

std::vector<std::string_view> commands;
  commands ={"read","write","append","open"};
  int index;
  std::string_view cmd=argv[1];
  std::string_view filepath=argv[2];

//checks if command exist of not
//if it does it provides index
//in future maybe enum will be provided.
auto item=std::find(commands.begin(),commands.end(),cmd);

if(item==commands.end()){
    std::cerr<<"command '"<<cmd
             <<"' not found";
  }
else{
index=std::distance(commands.begin(),item);
  }

//command check ends
 std::string content;
 std::string line;
 std::ofstream output;
 std::ifstream input;

//main block add case and make ur cmd
//make sure to push_back() to commands


switch(index){

   case 0://read
      input.open(filepath);
      if(input){
        while(std::getline(input,line)){
        content+=line +"\n";
        }
       std::cout<<content;
      }//if end brace
      else{
      std::cerr<<"File with path"
               <<filepath
               <<" couldnt open.\n";
      }
    break;


    case 1://write
      output.open(filepath);
      if(output.is_open()){
      std::cout<<">>";
      std::getline(std::cin,content);
      output<<content;
      output.close();
      }//if end brace
      else{
      std::cerr<<"File with path "
               <<filepath
               <<" didnt open.\n";
      }
    break;


    case 2://append
    output.open(filepath,std::ios::app);
      if(output.is_open()){
      std::cout<<">>";
      std::getline(std::cin,content);
      output<<content;
      output.close();
      }//if end brace
      else{
      std::cerr<<"File with path "
               <<filepath
               <<" didnt open.\n";
      }

  }//main switch case end brace


return 0;

}//main end brace
