#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int MAXn = 100000 + 100;

int n, m;

int t[4*MAXn];
bool v[4*MAXn];

inline int get (int x, int &l, int &r)
{
	return v[x] ? (r-l)-t[x] : t[x];
}

void change (int x, int l, int r, int &s, int &e)
{
	if (e <= l || r <= s)
		return;
	if (s <= l && r <= e)
	{
//		cerr << l+1 << ' ' << r << " changed!" << endl;
		v[x] ^= true;
		return;
	}
	v[2*x] ^= v[x];
	v[2*x+1] ^= v[x];
	v[x] = false;
	int mid = (l + r) / 2;
	change (2*x, l, mid, s, e);
	change (2*x+1, mid, r, s, e);
	t[x] = get (2*x, l, mid) + get (2*x+1, mid, r);
//	cerr << "t[" << l+1 << ", " << r << "] = " << get (2*x, l, mid) << " + " << get (2*x+1, mid, r) << " = " << t[x] << endl;
}

int query (int x, int l, int r, int &s, int &e)
{
	if (e <= l || r <= s)
		return 0;
	if (s <= l && r <= e)
	{
//		cerr << "from " << l+1 << " to " << r << ", " << get (x, l, r) << " !" << endl;
		return get (x, l, r);
	}
	v[2*x] ^= v[x];
	v[2*x+1] ^= v[x];
	v[x] = false;
	int mid = (l + r) / 2;
	t[x] = get (2*x, l, mid) + get (2*x+1, mid, r);
	return query (2*x, l, mid, s, e) + query (2*x+1, mid, r, s, e);
}

int main()
{
	ios::sync_with_stdio (false);
	cin >> n >> m;
	while (m--)
	{
		int op, s, e;
		cin >> op >> s >> e;
		s--;
		if (op == 0)
			change (1, 0, n, s, e);
		else
			cout << query (1, 0, n, s, e) << endl;
	}
	{ int _; cin >> _; }
}
