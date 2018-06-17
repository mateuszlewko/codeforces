#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define For(i, n) for(int i = 0; i < (n); i++)
#define ForD(i, n) for(int i = (n)-1; i >= 0; i--)

using namespace std;

const int N = 200 * 1000 + 10;
int vcount[N];
vector<int> G[N];
int k;

long long dfs(int x, int pre = -1)
{
	long long sum = 0;
	for (auto& v : G[x])
		if (v != pre) 
		{
			sum += dfs(v, x);
			vcount[x] += vcount[v];
		}

	return sum + min(vcount[x], 2 * k - vcount[x]);
}

int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n >> k;

	For (i, 2 * k)
	{
		int a;
		cin >> a;
		vcount[a]++;
	}

	For (i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	cout << dfs(1);
	return 0;
}