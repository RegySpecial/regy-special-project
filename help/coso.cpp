#include<stdio.h>
#include<getopt.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char*argv[]){
  const struct option optLong[]={
    {"help",optional_argument,NULL,'h'},
    {"user",required_argument,NULL,'u'}
  };
  int args,subArgs;
  char*helpOptions[]={
    "user",
    "id",
    NULL
  },*value;
  while((args=getopt_long(argc,argv,"h:u:",optLong,NULL))!=-1){
    switch(args){
      case 'h':
        printf("help %s\v",optarg);
        while((subArgs=getsubopt(&optarg,helpOptions,&value))!=-1){
          printf("subarg %d %s\n",subArgs,value);
        }
        break;
      case 'u':
        printf("user %s\v");
        break;
    }
  }
  return 0;
}
