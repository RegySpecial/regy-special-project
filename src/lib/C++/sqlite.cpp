#include<stdio.h>
#include<iostream>
class SQLite{
  public:
    FILE*databaseFile;
    char version[16];
    unsigned short pageSize;
    unsigned short tableSize;
    unsigned char recordSize,
                  writeVersion,//File format write version. 1 for legacy; 2 for WAL.
                  readVersion;//File format read version. 1 for legacy; 2 for WAL.
    SQLite(char*databaseFilePath){
      this->databaseFile=fopen(databaseFilePath,"rb");
      if(this->databaseFile==NULL){
        perror("Failed to open database");
      }
      fread(this->version,16,1,this->databaseFile);

      fseek(this->databaseFile,16,SEEK_SET);
      unsigned char PageSize[2];
      fread(PageSize,2,1,this->databaseFile);
      this->pageSize=PageSize[0]<<8|PageSize[1];

      fseek(this->databaseFile,18,SEEK_SET);
      fread(&this->writeVersion,1,1,SEEK_SET);

      fseek(this->databaseFile,19,SEEK_SET);
      fread(&this->readVersion,1,1,SEEK_SET);

      fseek(this->databaseFile,103,SEEK_SET);
      unsigned char TableSize[2];
      fread(TableSize,2,1,this->databaseFile);

      this->tableSize=TableSize[0]<<8|TableSize[1];
      fseek(this->databaseFile,60164,SEEK_SET);

      fread(&this->recordSize,1,1,this->databaseFile);
    }
    void printTables(){

    }
    ~SQLite(){
      fclose(this->databaseFile);
      this->databaseFile=NULL;
    }
};
int main(int argc,char*argv[]){
  if(argc==2){
    SQLite connect(argv[1]);
    std::cout<<connect.pageSize<<'\n';
  }
  return 0;
}