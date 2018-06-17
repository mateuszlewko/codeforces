#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <unordered_set>

#define For(i, n) for(int i = 0; i < (n); i++)
#define ForD(i, n) for(int i = (n)-1; i >= 0; i--)

using namespace std;

const int N = 100 * 1000 + 10;
bool cols[N];
bool rows[N];

unordered_set<char> types;
unordered_map<char, int> counting;

int main()
{
	ios::sync_with_stdio(0);
	int n, l, v1, v2, k;
	cin >> n >> l >> v1 >> v2 >> k;

	double res = .0;
	double currPos = .0;

	while (n > 0)
	{
		n -= min(k, n);
		double t = (l - currPos) / v2;
		res += t;
		
		currpos | people | time
		0 | 3 | 0
		3 | 2 | 3
		4.5 | 1 | 4.5
		

		currPos += v1 *  t;
		if (currPos >= l)
			break;
	}

	printf("%.6lf\n", res);
	return 0;
}