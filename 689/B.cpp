#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

#define For(i, n) for(int i = 0; i < (n); i++)

using namespace std;

const int N = 200 * 1000 + 10;
vector<int> G[N];
int res[N];

void bfs(int x)
{
	queue<int> Q;
	Q.push(x);

	while (Q.size())
	{
		int u = Q.front();
		Q.pop();

		for (auto& v : G[u])
			if (res[v] > res[u] + 1)
			{
				res[v] = res[u] + 1;
				Q.push(v);
			}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	fill_n(res + 1, n, 1 << 30);

	For (i, n)
	{
		int a;
		scanf("%d", &a);

		if (a - 1 != i)
			G[i].push_back(a - 1);

		if (i > 0)
			G[i].push_back(i - 1);
		if (i != n - 1)
			G[i].push_back(i + 1);
	}

	bfs(0);

	For (i, n)
		printf("%d ", res[i]);
}