/*
* for more information visit "https://sqlite.org/fileformat2.html"
*/
#include<stdio.h>
#include<iostream>
class SQLite{
  public:
    FILE*databaseFile;
    struct{
      unsigned char headerString[16];
      unsigned short pageSize;
      unsigned char writeVersion:8,//File format write version. 1 for legacy; 2 for WAL.
                    readVersion:8,//File format read version. 1 for legacy; 2 for WAL.
                    unusedSpace:8,
                    maxPayload:8,//Must be 64
                    minPayload:8,//Must be 32
                    leafPayload:8;//Must be 31
      unsigned long fileChangeCounter:32,
                    inHeaderDatabaseSize:32,//in pages
                    freeListTrunkPageNumber:32,
                    freeListPages:32,
                    schemaCookie:32,
                    schemaFormat:32,
                    defaultPageCacheSize:32,
                    largetRootBTreePage:32,
                    textEncoding:32,
                    userVersion:32,
                    incrementalVacuumMode:32,
                    applicationID:32;
      unsigned char expansionSpace[20];
      unsigned long validationNumber:32,
                    versionNumber:32;
    }databaseHeader;
    struct{
      unsigned char type:8;
      unsigned short freeBlock:16,
                     cells:16,
                     cellContentArea:16;
      unsigned char freeContentArea:8;
      unsigned long pointer:32;
    }BTreePageHeader;
    struct{
    }BTreeCell;
    SQLite(char*databaseFilePath){
      this->databaseFile=fopen(databaseFilePath,"rb");
      if(this->databaseFile==NULL){
        perror("Failed to open database");
        return;
      }
      fwrite(this->databaseHeader.headerString,16,1,this->databaseFile);
      fseek(this->databaseFile,16,SEEK_CUR);
      fwrite(&(this->databaseHeader.pageSize),1,2,this->databaseFile);
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
