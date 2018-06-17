#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

#define For(i, n) for(int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

ll count(ll x, ll m)
{
	ll sum = 0;
	ll k = 2;
	while (k * k * k <= x)
	{
		sum += x / (k * k * k);
		// printf("sum: %lld, k: %lld, x: %lld \n", sum, k, x); 

		if (sum > m)
			return sum;
		k++;
	}

	return sum;	
}

bool check(ll x, ll m)
{
	return count(x, m) >= m;
}

ll solve(ll m)
{
	ll beg = 0, end = 1LL << 62;

	while (beg != end - 1)
	{
		ll mid = (beg + end) / 2;
		// printf("mid: %lld\n", mid);

		if (check(mid, m))
			end = mid;
		else
			beg = mid + 1;
	}

	For (i, 4)
		if (count(beg + i, m) == m)
			return beg + i;

	return -1;
}

int main()
{
	ll m;
	scanf("%I64d d", &m);	
	printf("%I64d \n", solve(m));
}