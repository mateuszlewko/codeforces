#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define For(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const int N = 100 * 1000 + 10;

vector<int> G[N];
bool vis[N];
bool color[N];

void dfs(int x)
{
	if (vis[x])
		return;

	vis[x] = true;
	for (auto& v : G[x])
	{
		if (color[v] == color[x] and vis[v])
		{
			puts("-1");
			exit(0);
		}

		color[v] = !color[x];
		dfs(v);
	}
}

int main()
{
	//ios::sync_with_stdio(0);

	int n, m;
	scanf("%d %d", &n, &m);

	For (i, m)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	For (i, n)
		if (!vis[i])
			dfs(i);

	vector<int> A, B;

	For (i, n)
		if (color[i])
			A.push_back(i + 1);
		else
			B.push_back(i + 1);

	printf("%d\n", (int)A.size());
	for (auto& x : A)
		printf("%d ", x);

	printf("\n%d\n", (int)B.size());
	for (auto& x : B)
		printf("%d ", x);

}