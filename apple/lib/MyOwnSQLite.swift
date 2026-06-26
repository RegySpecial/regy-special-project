import Foundation
import Darwin
/*
class SQLite{
  public:
    FILE*databaseFile;
    char version[16];
    unsigned short pageSize;
    unsigned short tableSize;
    unsigned char recordSize;
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
      fseek(this->databaseFile,103,SEEK_SET);
      unsigned char TableSize[2];
      fread(TableSize,2,1,this->databaseFile);
      this->tableSize=TableSize[0]<<8|TableSize[1];
      fseek(this->databaseFile,60164,SEEK_SET);
      fread(&this->recordSize,1,1,this->databaseFile);
    }
    unsigned char query(char*SQLquery){
      
    }
    ~SQLite(){
      fclose(this->databaseFile);
      this->databaseFile=NULL;
    }
};
*/
class SQLite{
  var version:String
  var pageSize:UInt16
  var tableSize:UInt16
  var recordSize:UInt8
  var databaseFile:UnsafeMutablePointer<FILE>
  func init(_ databaseFilePath:String){
    self.databaseFile=fopen(databaseFilePath,"rb")
    if(self.databaseFile==nil){
      print("Failed to open database")
      return
    }
    fread(self.version,16,1,self.databaseFile)
    fseek(self.databaseFile,16,SEEK_SET)
    var PageSize:[UInt8]
    fread(PageSize,2,1,self.databaseFile)
    self.pageSize=PageSize[0]<<8|PageSize[1]
    fseek(self.databaseFile,103,SEEK_SET)
    var TableSize:[UInt8]
    fread(TableSize,2,1,self.databaseFile)
    self.tableSize=TableSize[0]<<8|TableSize[1]
    fseek(self.databaseFile,60164,SEEK_SET)
    fread(&self.recordSize,1,1,self.databaseFile)
  }
  deinit{
    fclose(self.databaseFile)
    self.databaseFile=nil
  }
}