#include <vector>
#include <iostream>

using namespace std;
bool test(vector<int> symmet, int start, int end);
int main(){
  int n;
  cin >> n;
  vector <int> symmet(n);
  for(int i = 0; i < n; i++)
    cin >> symmet[i];
  if(test(symmet,0,n-1))
    cout << "Yes";
  else
    cout << "No";
  cout << endl;
  return 0;
}

bool test(vector<int> symmet, int start, int end){
  if(start >= end)
    return true;
  else if (symmet[start] == symmet[end])
    return test(symmet, start+1, end -1);
  else
    return false;
}

      
