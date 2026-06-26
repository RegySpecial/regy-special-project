#include<sql.h>
#include<sqlext.h>
#include<stdio.h>
#include<iostream>
namespace sql{
  class environment{
    public:
      SQLHANDLE sqlHandle;
      SQLRETURN sqlReturn;
      environment(){
        this->sqlReturn=SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HENV,&this->sqlHandle);
      }
      ~environment(){
        SQLFreeHandle(SQL_HANDLE_ENV,this->sqlHandle);
      }
  };
  class connection{
    public:
      SQLHANDLE sqlHandle;
      SQLRETURN sqlReturn;
      connection(sql::environment*sqlEnv){
        this->sqlReturn=SQLAllocHandle(SQL_HANDLE_STMT,sqlEnv->sqlHandle,&this->sqlHandle);
      }
      ~connection(){
        SQLFreeHandle(SQL_HANDLE_DBC,this->sqlHandle);
      }
  };
  class statement{
    public:
      SQLHANDLE sqlHandle;
      SQLRETURN sqlReturn;
      statement(sql::connection*sqlConnect){
        this->sqlReturn=SQLAllocHandle(SQL_HANDLE_STMT,sqlConnect->sqlHandle,&this->sqlHandle);
      }
      ~statement(){
        SQLFreeHandle(SQL_HANDLE_ENV,this->sqlHandle);
      }
  };
}
int main(int argc,char*argv[],char*envp[]){
  void*SQLEnvironment,
      *SQLStatement,
      *SQLConnection;
  
  signed short SQLReturn;
  char SQLuserName[40];//user name SQL result
  long indicator;

  SQLReturn=SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&SQLEnvironment);
  if(SQLReturn!=SQL_SUCCESS&&SQLReturn!=SQL_SUCCESS_WITH_INFO)
    PrintSQLDiagnosticError(SQLEnvironment,SQL_HANDLE_ENV,"Errore nell'inizializzazione dell'ambiente");
  
  SQLReturn=SQLSetEnvAttr(SQLEnvironment,SQL_ATTR_ODBC_VERSION,(void*)SQL_OV_ODBC3,0);
  if(SQLReturn!=SQL_SUCCESS&&SQLReturn!=SQL_SUCCESS_WITH_INFO)
    PrintSQLDiagnosticError(SQLEnvironment,SQL_HANDLE_ENV,"Errore nell'attribuzione della connessione");
  
  SQLReturn=SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvironment, &SQLConnection);
  if(SQLReturn!=SQL_SUCCESS&&SQLReturn!=SQL_SUCCESS_WITH_INFO)
    PrintSQLDiagnosticError(SQLEnvironment,SQL_HANDLE_ENV,"Errore nello stabilire della connessione");
  
  SQLReturn=SQLDriverConnect(SQLConnection,NULL,(SQLCHAR*)"DSN=MySQLiteDB;",SQL_NTS,NULL,0,NULL,SQL_DRIVER_COMPLETE);
  if(SQLReturn!=SQL_SUCCESS&&SQLReturn!=SQL_SUCCESS_WITH_INFO)
    PrintSQLDiagnosticError(SQLConnection,SQL_HANDLE_DBC,"Errore nella connessione al driver");
  
  SQLReturn=SQLAllocHandle(SQL_HANDLE_STMT,SQLConnection,&SQLStatement);
  if(SQLReturn!=SQL_SUCCESS&&SQLReturn!=SQL_SUCCESS_WITH_INFO)
    PrintSQLDiagnosticError(SQLConnection,SQL_HANDLE_DBC,"Errore nella dichiarazione dello statement");
  
  if(argc==1){
    SQLReturn=SQLExecDirectA(SQLStatement,(SQLCHAR*)"select distinct name from User where id=1",SQL_NTS);
    if(SQL_NO_DATA==SQLReturn)SQLReturn=SQLExecDirectA(SQLStatement,(SQLCHAR*)"insert into User select 1,\"Player 1\"",SQL_NTS);
  }else{
    SQLReturn=SQLPrepareA(SQLStatement,(SQLCHAR*)"select distinct name from User where name=?",SQL_NTS);
    SQLReturn=SQLBindParameter(SQLStatement,1,SQL_PARAM_INPUT,SQL_C_CHAR,SQL_VARCHAR,40,0,(void*)userInput,sizeof(userInput),NULL);
    SQLReturn=SQLExecute(SQLStatement);
  }
  while(SQLFetch(SQLStatement)==SQL_SUCCESS){
    SQLGetData(SQLStatement,1,SQL_C_CHAR,(void*)userInput,sizeof(userInput),&indicator);
    std::cout<<userInput<<'\n';
  }
  SQLFreeHandle(SQL_HANDLE_STMT,SQLStatement);
  SQLDisconnect(SQLConnection);
  SQLFreeHandle(SQL_HANDLE_DBC,SQLConnection);
  SQLFreeHandle(SQL_HANDLE_ENV,SQLEnvironment);
  SQLStatement=NULL;
  SQLConnection=NULL;
  SQLEnvironment=NULL;
}