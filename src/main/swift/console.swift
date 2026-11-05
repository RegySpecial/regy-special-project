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

func swift_successMessage(_ successMessageFormat: String, _ variableArguments: CVarArg...)
{
  withVaList(variableArguments)
  {
    va_list in
    successMessageFormat.withCString
    {
      cString in
      variableArguments_successMessage(cString, va_list)
    } 
  }
}

func swift_warningMessage(_ warningMessageFormat: String, _ variableArguments: CVarArg...)
{
  withVaList(variableArguments)
  {
    va_list in
    warningMessageFormat.withCString
    {
      cString in
      variableArguments_warningMessage(cString, va_list)
    } 
  }
}

func swift_informationMessage(_ informationMessageFormat: String, _ variableArguments: CVarArg...)
{
  withVaList(variableArguments)
  {
    va_list in
    informationMessageFormat.withCString
    {
      cString in
      variableArguments_informationMessage(cString, va_list)
    } 
  }
}