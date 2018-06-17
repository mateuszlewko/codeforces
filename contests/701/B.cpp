#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>

#define For(i, n) for(int i = 0; i < (n); i++)
#define ForD(i, n) for(int i = (n)-1; i >= 0; i--)

using namespace std;

const int N = 100 * 1000 + 10;
bool cols[N];
bool rows[N];

int main()
{
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	int rows_occ = 0;
	int cols_occ = 0;

	For (i, m)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;

		if (!cols[a])
			cols_occ++;
		if (!rows[b])
			rows_occ++;

		cols[a] = 1;
		rows[b] = 1;

		cout << 1LL * (n - rows_occ) * (n - cols_occ) << "\n";
	}

	return 0;
}