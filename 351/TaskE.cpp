#include <cstdio>
#include <iostream>
#include <vector>

#define For(i, n) for (int i = 0; i < (n); i++)

using namespace std;
const int N = 2010;
const int MAXP = 100 * 1000 + 10;

int A[N];
vector<int> Pos[MAXP];

int dp[N];

pair<int, int> getInvs(int pos, int n)
{
	int l = 0;
	int r = 0;

	For (i, n)
		if (i < pos and A[i] < A[pos])
			l++;
		else if (i > pos and A[i] < A[pos])
			r++;

	return make_pair(l, r);
}

int main()
{
	int n;
	scanf("%d", &n);

	For (i, n)
	{
		scanf("%d", &A[i]);
		Pos[A[i]].push_back(i);
	}

	int res = 0;
	For (i, n)
	{
		For (j, Pos[A[i]].size())
		{
			int pos = Pos[A[i]][j];
			auto invs = getInvs(pos, n);

			int tmpDp[N];

			For (k, j)
			{
				tmpDp[k] = dp[k] + invs.second;
				tmpDp[k + 1] = dp[k] + invs.second + j - k;
			}		
		}
	}
	return 0;
}