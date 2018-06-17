#include <iostream>
#include <vector>

#define For(i, n) for(int i = 0; i < (n); i++)

using namespace std;

const int N = 300 * 1000 + 10;
vector<int> graph[N];
vector<pair<int, int>> data[N];

void dfs(int x, int pre, vector<int>& vecs)
{
	vecs.push_back(x);

	for (const auto& v : graph[x])
		if (v != pre)
			dfs(v, x, vecs);

	if (graph[x].empty())

	vecs.pop_back();
}



int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	For (i, n - 1)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	F
}