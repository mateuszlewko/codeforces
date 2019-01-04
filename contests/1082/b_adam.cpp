#include <bits/stdc++.h>
#define FOR(i, a, b)	for (int (i)=(a); (i)<(b); (i)++)
#define PPC(x)			__builtin_popcountll((x))
#define ALL(x)			(x).begin(), (x).end()
#define pb				push_back
using namespace std;

const int maxN = 100005;

vector <int> begs, Ends;
char in[maxN];

int len(int i)
{	return Ends[i] - begs[i] + 1;	}

void ext(int a)
{
	printf("%d\n", a);
	exit(0);
}

bool nbr(int i, int j)
{
	return Ends[i] + 2 == begs[j] or Ends[j] + 2 == begs[i];
}

void remax(int& a, int b)	{   a = max(a, b);  }

int main()
{
	int n;
	scanf ("%d", &n);
	scanf ("%s", in);

	FOR(i, 0, n)
	{
		if (in[i] == 'S')
			continue;
		if (i == 0 or in[i-1] == 'S')
			begs.pb(i);
		if (i == n-1 or in[i+1] == 'S')
			Ends.pb(i);
	}
	
	if (begs.size() == 0)
		ext(0);
		
	if (begs.size() == 1)
		ext(len(0));
		
	if (begs.size() == 2)
	{
		if (nbr(0, 1))
			ext(len(0) + len(1));
		else
			ext(max(len(0), len(1)) + 1);
	}
	
	int mx = len(0), res = 0;
	
	FOR(i, 1, begs.size())
	{
		if (nbr(i-1, i))
			remax(res, len(i-1) + len(i) + 1);
		remax(mx, len(i));
	}

	remax(res, mx+1);
	printf("%d\n", res);
	return 0;
}