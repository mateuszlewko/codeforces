#include <iostream>
#include <cstdio>
#include <vector>

#define For(i, n) for(int i = 0; i < (n); i++)
#define ForD(i, n) for(int i = (n) - 1; i >= 0; i--)

using namespace std;

struct tree
{
	static const int N = 1 << 17;
	pair<int, int> data[N << 1];

	tree() { }

	void build(vector<int> v)
	{
		for (size_t i = 0; i < v.size(); i++)
			data[i + N] = {v[i], i};

		ForD (i, N)
			data[i] = max(data[i * 2], data[i * 2 + 1]);
	}

	pair<int, int> query(int p, int q)
	{
		return query(p, q, 0, N - 1, 1);
	}

	pair<int, int> query(int p, int q, int l, int r, int x)
	{
		if (p <= l and q >= r)
			return data[x];

		int mid = (l + r) >> 1;
		pair<int, int> lres, rres = {0, 0};
		lres = rres;

		if (p <= mid)
			lres = query(p, q, l, mid, x * 2);
		if (q > mid)
			rres = query(p, q, mid + 1, r, x * 2 + 1);

		return max(lres, rres);
	}
};

long long solution(vector<int> v)
{
	long long res = 0;
	int n = v.size();

	vector<long long> dp(n);

	tree S;
	S.build(v);
	dp.back() = 0;

	ForD (i, n - 1)
	{
		auto farthest = S.query(i + 1, v[i]);
		res += dp[i] = n - i - 1 + dp[farthest.second] - (v[i] - farthest.second);
	}

	return res;
}

int main()
{
	int n;

	scanf("%d", &n);
	vector<int> v(n);
	v[n - 1] = n - 1;

	For (i, n - 1)
	{
		scanf("%d", &v[i]);
		v[i]--;
	}

	printf("%I64d\n", solution(v));
}