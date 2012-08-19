#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
bool tree[4*100005];
int t[4*100005];
inline int get(int x, int l, int r){
  return tree[x] ? (r-l) - t[x] : t[x];
}

void change(int node, int start, int end, int i, int j){
  if (j <= start || end <= i)
    return;
  if(start >= i && end <= j){
    tree[node] ^= true;
    return;
  }

  int mid = (start + end)/2;
  tree[2*node] ^= tree[node];
  tree[2*node+1] ^= tree[node];
  tree[node] = false;
  change(2*node,start, mid, i, j);
  change(2*node+1, mid, end, i, j);
  t[node] = get(2*node, start, mid) + get(2*node+1, mid, end);
  return;
}

int query(int x, int l, int r, int s, int e){
  if (s >= r || e <= l)
    return 0;
  else if( s <= l && r <= e)
    return get(x,l,r);

  tree[2*x] ^= tree[x];
  tree[2*x +1] ^= tree[x];

  tree[x] = false;
  int mid = (l+r)/2;
  t[x] = get(2*x, l ,mid) + get(2*x + 1, mid, r);
  return query(2*x, l, mid, s, e)+ query(2*x+1, mid, r, s,e);
}


int main(){
  int n, m;
  cin >> n >> m;
  while(m--){
    int op, s,e;
    scanf("%d %d %d", &op, &s, &e);
    
    if(op == 0)
      change(1,0, n-1, s, e);
    else
      printf("%d\n",query(1,0,n-1,s,e));
  }

}

   
  

  
    
    
  
  
  
