#include<iostream>
#include<string>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;
int DP[2001][2001];
int path[11][2001];
int D[11];
int main(){
  int n;
  scanf("%d", &n);
  string temp;
  getline(cin, temp);
  while(n--){
  int i = 0;
  while(1){    
  string input;  
  getline(cin, input);
  if (input[0] == '0')
    break;
  //  cout << input << endl;
  stringstream ss(input);
  int k;
  int j = 0;
  while(ss >> path[i][j++]);
  D[i] = j;
  i++;
  }
  int count = i;
  //  cout << count;
  int maxi = 0;
  //  cout << path[0][0] << " " << path[0][1] << " " << path[0][2] <<   endl;
  for(int k = 1; k < count; k++){
    for(i = 1; i < D[0]+1; i++){
    for(int j = 1; j < D[k]+1; j++){
      //  cout << "here" << endl;
      if (path[0][i-1] == path[k][j-1]){
        //cout << "here" << endl;
        DP[i][j] = 1+DP[i-1][j-1];
      }
      else
        DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
    }
  }
  if (DP[D[0]][D[k]] > maxi)
    maxi = DP[D[0]][D[k]];
  }

  cout << maxi-2 << endl;
  memset(DP, 0, sizeof(DP));
  memset(path, 0, sizeof(path));
  }
  return 0;
}
      
      
    

  

  
  
  
  
  
