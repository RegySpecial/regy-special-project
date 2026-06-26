template<typename returnDataType>
returnDataType stringToNumber(const char*string){
  returnDataType number=0;
  for(unsigned long i=*string=='+'||*string=='-'?1:0;string[i]!=0;i++)
    if('0'<=string[i]&&string[i]<='9')
      number=(number*10)+(string[i]-'0');
  return number;
}
template<typename numberDataType=unsigned long long>
void numberToBase(char*outputBuffer,numberDataType number,unsigned char base){
  for(unsigned long long c=0;outputBuffer[c]!=0;c++)outputBuffer[c]=0;
  if(2<=base&&base<=36){
    for(unsigned char bit=0;bit<sizeof number*8;bit++){
      outputBuffer[sizeof number*8-bit-1]="0123456789abcdefghijklmnopqrstuvwxyz"[number%base];
      number/=base;
    }
  }
}