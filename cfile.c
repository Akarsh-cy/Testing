#include<stdio.h>
#include<unistd.h>

#define READ 0
#define WRITE 1
#define APPEND 2
int main(int argc,char*argv[]){

if(argc<3){
  fprintf(stderr,"Provide 2 command line  argument\n");
  return 1;
  }
else if(argc>3){
  fprintf(stderr,"More then 2 arguments   provided\n");
  }

char* command[3];
command[0]="read";
command[1]="write";
command[2]="append";

//compare c style string
int cmd_no;
int found=0;//0 if not found
for(int i=0;i<3;++i){
int j=0;
  while(command[i][j]!='\0'&& argv[1][j]!='\0'){
     if(command[i][j]!=argv[1][j]){
        break;
    }
  j++;
  }
  if(command[i][j]=='\0'&& argv[1][j]=='\0'){
    found=1;
    cmd_no=i;
}
  }

if(found==0){
fprintf(stderr,"Command not found.\n");
return 1;
  }
int ch;
FILE* path;
const char* filename=argv[2];
char buf[100];
switch(cmd_no){
  
    case READ:
      path=fopen(filename,"r");
      if(path==NULL){
      fprintf(stderr,"File not open\n");
      return 1;
      }
      while(((ch=fgetc(path))!=EOF)){
      putchar(ch);
      }
      fclose(path);
      break;

    case WRITE:
      path=fopen(argv[2],"w");
      if(path==NULL){
      fprintf(stderr,"File not open\n");
      return 1;
      }
      printf(">>");
      fgets(buf,sizeof(buf),stdin);
      fprintf(path,"%s",buf);
      fclose(path);
      break;

    case APPEND:
       path=fopen(argv[2],"a");
      if(path==NULL){
      fprintf(stderr,"File not open\n");
      return 1;
      }
      printf(">>");
      fgets(buf,sizeof(buf),stdin);
      fprintf(path,"%s",buf);
      fclose(path);
      break;

  }







return 0;
}
