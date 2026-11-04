func swift_errorMessage(_ errorMessageFormat: String, _ variableArguments: CVarArg...)
{
  withVaList(variableArguments)
  {
    va_list in
    errorMessageFormat.withCString
    {
      cString in
      variableArguments_errorMessage(cString, va_list)
    } 
  }
}

swift_errorMessage("Messaggio di errore stampato con successo! %i\n", 21)
