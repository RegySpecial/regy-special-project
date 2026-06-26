double sum(double numbers[],unsigned long long left,unsigned long long right){
  double value=0;
  for(;left<right;left++)value+=numbers[left];
  return value;
}
inline double average(double numbers[],unsigned long long left,unsigned long long right){
  return sum(numbers,left,right)/(right-left);
}
double ythRootOfX(double x,double y){
  
}