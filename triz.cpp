#include <iostream>

using namespace std;

int main(){

  int m,n;
  cin >> n >> m;
  //cout << "n" << n << "m" << m << endl;
  int X[5][5] = {0};
  for(int i = 0 ; i < m; i++)
    for(int j = 0; j < n; j++)
      cin >> X[i][j];
  for(int i = 0; i < n-2; i++){
    for(int j = 0; j < m; j++){
      if (X[i+1][j] == X[i][j] && X[i][j] == X[i+2][j] && X[i][j] == 0){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
      
      
      
      
        
