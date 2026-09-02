int factorial(unsigned int x){
  return !x ? 1 : x * factorial(--x);
}

template<typename domainArgument=long double>
long double pow(domainArgument x, domainArgument y)
{
  long double result = 1;
  if (!y)
    return 1;
  for (domainArgument i = 0; i < y; i++)
    result *= x;
  return result;
}

double sum(double numbers[],unsigned long long left,unsigned long long right){
  double value=0;
  for(;left<right;left++)value+=numbers[left];
  return value;
}
double average(double numbers[],unsigned long long left,unsigned long long right){
  return sum(numbers,left,right)/(right-left);
}
double ythRootOfX(double x,double y){
  double result = 1;
  for (unsigned char i = 0; i < 100; i++)
    result = result - (pow(result, y) - x) / (y * pow(result, y - 1));
  return result;
}
template<typename domainArgument>
long double sin(domainArgument theta){
  long double result = 0;
  for (unsigned char i = 0; i < 100; i++)
    result = theta
}
