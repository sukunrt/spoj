#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << x << endl;
bool is_less(string temp, int n, string palind){
  int counter = 0;
  for(int i = 0; i < n; i++){
    if(temp[i] < palind[i])
      return true;
    if(temp[i] > palind[i])
      return false;
    counter++;
  }
  if(counter == n)
    return true;
  return false;
}

int main(){
  int t;
  cin >> t;
  string palind, temp;

  while(t--){
    cin >> palind;
    int n = palind.length();
    temp = palind;
    int j = n-1;
    for(int i = 0; i <= j; i++, j--){
      temp[i] = palind[i];
      temp[j] = palind[i];
    }
    if(is_less(temp, n ,palind)){
      if(n % 2 != 0){
        if (temp[(int)n/2] == '9'){
          temp[n/2] = '0';
          int i = n/2-1;
          while(i >=0 && temp[i] == '9'){
            temp[n-1-i] = '0';
            temp[i] = '0';
            i--;
          }
          temp[i]++;
          temp[n-1-i]++;
        }
        else{
          temp[(int)n/2]++;
        }
      }
      else{
        if(temp[(int)n/2] == '9'){
          int i = n/2 - 1;
          while(i >= 0 && temp[i] == '9'){
            temp[i] = '0';
            temp[n-1-i] = '0';
            i--;
          }
          temp[i]++;
          temp[n-1-i]++;
        }
        else{
        temp[(int)n/2]++;
        temp[(int)(n/2 - 1)]++;
        }
      }
    }
    int flag =0;
    for(int i = 0; i < n; i++)
      if(temp[i] != '0'){
        cout << temp << endl;
        flag = 1;
        break;
      }
    if(flag == 0){
      temp[n-1] = '1';
      cout << '1' + temp << endl;
    }
        
  }
  return 0;
}
    
