#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>

#define For(i, n) for(int i = 0; i < (n); i++)
#define ForD(i, n) for(int i = (n)-1; i >= 0; i--)

using namespace std;

const int N = 1000 + 10;
const int M = 30 * 1000 + 10;
const int INF = 1 << 30;
typedef array<int, 3> edge_t;

vector<int> G[N];
int in[N];
int pi[N];
array<edge_t, M> edges;

inline int getNeigh(const int & x, const array<int, 3> & edge)
{
	return x ^ edge[0] ^ edge[1];
}

vector<int> getPath(int x, int final)
{
	bool visited[N] = {};
	int preEdge[N] = {};
	int pre[N] = {};

	queue<int> Q;
	Q.push(x);
	visited[x] = true;

	while (Q.size())
	{
		int u = Q.front();
		Q.pop();

		for (auto& v : G[u])
		{
			auto neigh = getNeigh(u, edges[v]);

			if (!visited[neigh])
			{
				pre[neigh] = u;
				preEdge[neigh] = v;

				visited[neigh] = true;
				Q.push(neigh);
			}
		}
	}

	vector<int> edges;
	auto last = final;

	while (last != x and last != 0)
	{
		// cout << last << endl;
		edges.push_back(preEdge[last]);
		last = pre[last];
	}

	return edges;
}

int cnt = 0;
bool visEdge[M];

int best_ans;
int best_edge;

int dfs_bridge(int u, int cost, int edge)
{
	int ans = u;
	in[u] = cnt++;

	for (auto& v : G[u])
	{
		int neigh = getNeigh(u, edges[v]);

		if (neigh == u or visEdge[v]) 
			continue;

		visEdge[v] = true;

		if (in[v]==INF)
		{
			pi[v] = u;
			neigh = dfs_bridge(v, edges[v][2], v);	
		}

		if (in[ans] > in[neigh]) 
			ans = neigh;
	}

	if (ans == u and pi[u] != u and best_ans > cost)
	{
		best_ans = cost;
		best_edge = edge;
	}

	return ans;
} 

// vector<pair<int, int>> getPath(int x, int final)
// {
// 	bool visited[N] = {};
// 	pair<int, int> pre[N] = {};

// 	queue<int> Q;
// 	visited[x] = true;
// 	Q.push(x);

// 	while (Q.size())
// 	{
// 		int u = Q.front();
// 		// cout << "u: " << u << endl;
// 		Q.pop();

// 		for (size_t i = 0; i < G[u].size(); i++)
// 			if (!visited[G[u][i].first])
// 			{
// 				pre[G[u][i].first] = {u, i};
// 				visited[G[u][i].first] = true;
// 				Q.push(G[u][i].first);
// 			}
// 	}

// 	vector<pair<int, int>> path;
// 	auto last = pre[final];
// 	while (last != pair<int, int>({0, 0}))
// 	{
// 		// cout << last.first << endl;
// 		path.push_back(last);
// 		last = pre[last.first];
// 	}

// 	return path;
// }

// bool check(int x, int final, const vector<pair<int, int>>&& forbidden)
// {
// 	bool visited[N] = {};
	
// 	queue<int> Q;
// 	visited[x] = true;
// 	Q.push(x);

// 	while (Q.size())
// 	{
// 		int u = Q.front();
// 		Q.pop();

// 		for (size_t i = 0; i < G[u].size(); i++)
// 		{
// 			if (visited[G[u][i].first])
// 				continue;

// 			bool cont = false;

// 			for (auto& edge : forbidden)
// 				if (edge.first == u && edge.second == (int)i)
// 				{
// 					cont = true;
// 					break;
// 				}

// 			if (cont)
// 				continue;
			
// 			visited[G[u][i].first] = true;
// 			Q.push(G[u][i].first);
// 		}
// 	}

// 	return !visited[final];
// }

// inline pair<int, int> findReversed(const pair<int, int> & edge)
// {
// 	auto v = G[edge.first][edge.second];

// 	for (size_t i = 0; i < G[v.first].size(); i++)
// 		if (G[v.first][i] == pair<int, int>({edge.first, v.second}))
// 			return {v.first, i};

// 	return move(edge);
// }

 
// int dfs(int u)
// {
// 	int ans = u;
// 	in[u] = cnt++;
// 	for (int i=0; i<adj[u].size(); i++)
// 	{
// 		int v = adj[u][i];
// 		 // pomijaj pętle
// 		if (v==u) continue;
// 		 // pomijaj krawędź do poprzednika w drzewie DFS; UWAGA: zakładamy tutaj,
// 		 // że w grafie nie ma krawędzi wielokrotnych
// 		if (v==pi[u]) continue;
 
// 		if (in[v]==INF)
// 		{
// 			pi[v] = u;
// 			v = dfs(v);	
// 		}
// 		if (in[ans] > in[v]) ans=v;
// 	}
// 	if (ans==u && pi[u]!=u) printf("Most : %d -- %d\n", u+1, pi[u]+1);
// 	return ans;
// }


int main()
{
	fill_n(in, N, INF);

	int n, m;
	scanf("%d %d", &n, &m);

	int s, t;
	cin >> s >> t;

	if (m == 0)
	{
		cout << "0\n0";
		return 0;
	}

	For (i, m)
		For (j, 3)
			cin >> edges[i][j];

	int res = INF;
	int res0;
	int res1;

	auto&& path = getPath(s, t);
	if (path.size() == 0)
	{
		puts("0\n0");
		return 0;
	}

	for (auto e : path)
		cout << e << "\n";

	for (auto& v : path)
	{
		fill_n(visEdge, m + 1, false);
		visEdge[v] = true;
		best_ans = INF;

		dfs_bridge(s, INF, -1);
		if (best_ans < res)
		{
			res = best_ans;
			res0 = v + 1;
			res1 = best_edge + 1;
		}
	}

	if (res == INF)
		puts("-1");
	else if (res1 == -1)
		printf("%d\n1\n%d\n", res, res0);
	else
		printf("%d\n2\n%d %d\n", res, res0, res1);

	return 0;
}