```mermaid
flowchart
gameArgumentsInput[/"inseriti argomenti del programma (escluso argv[0])"/]
gameArgumentsInputSelection{argomenti del programma sono vuoti}
flagSelection{seleziona flag}
helpExecution["esegui 'argv[0] --help'"]
helpCase([stampa messaggi di aiuto!])
userNameIsEmpty{il nome utente è vuoto}
emptyUserName[il nome utente è vuoto]
userIdentifierIsEmpty{l'identificatore utente è vuoto}
userNameCheckByTheDatabase{il nome utente è nella base di dati}
userIdentifierCheckByTheDatabase{il nome utente è nella base di dati}
gameArgumentsInput-->gameArgumentsInputSelection
gameArgumentsInputSelection-->|no|flagSelection
gameArgumentsInputSelection-->|sì|helpExecution
flagSelection-->|--help|helpCase
flagSelection-->|--user|userNameIsEmpty
```