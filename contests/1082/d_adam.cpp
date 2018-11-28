#include <bits/stdc++.h>
#define FOR(i, a, b)	for (int (i)=(a); (i)<(b); (i)++)
#define PPC(x)			__builtin_popcountll((x))
#define ALL(x)			(x).begin(), (x).end()
#define pb				push_back
using namespace std;

const int maxN = 505;

int n, mdeg[maxN];
vector <int> G[maxN];

void conn(int a, int b)
{	G[a].pb(b); G[b].pb(a);	}

int path(int a, int b)
{
	int prev = a, res = 1;
	
	FOR(i, 1, n+1)
	{
		if (mdeg[i] == 1 or i == a or i == b)
			continue;
		res++;
		conn(prev, i);
		prev = i;
	}
	
	conn(prev, b);
	return res;
}

vector <int> lfs;

void ext(int res)
{
	printf("YES %d\n", res);
	int m = 0;
	FOR(i, 1, n+1)
		m += G[i].size();
	m /= 2;
	printf("%d\n", m);
	FOR(i, 1, n+1)
		for (int j : G[i])
			if (i < j)
				printf("%d %d\n", i, j);
	exit(0);
}

void fail()
{
	printf("NO\n");
	exit(0);
}

int main()
{
	scanf ("%d", &n);
	
	FOR(i, 1, n+1)
	{
		scanf ("%d", mdeg+i);
		if (mdeg[i] == 1)
			lfs.pb(i);
	}
	
	int a = 1, b = 2;
	
	if (lfs.size() == 1)
	{
		if (a != lfs[0] and b != lfs[0])
			a = lfs[0];
	}
		
	if (lfs.size() >= 2)
		a = lfs[0], b = lfs[1];
		
	int res = path(a, b);
	
	if (lfs.size() <= 2)
		ext(res);
	
	int i = 1;
		
	FOR(j, 2, lfs.size())
	{
		while (i <= n and mdeg[i] < 3)
			i++;
			
		if (i == n+1)
			fail();
			
		conn(i, lfs[j]);
		mdeg[i]--;
	}
	
	ext(res);
	return 0;
}