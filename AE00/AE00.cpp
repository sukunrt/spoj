#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  long long counter = 0;

  for(int i = 1; i <= sqrt(n); i++){
    counter += n / i - (i-1);
  }

  cout << counter << endl;
  return 0;
}
      
    
           
