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

const int N = 110;
pair<int, int> A[N];

int main()
{
	int n;
	scanf("%d", &n);

	For (i, n)
	{
		scanf("%d", &A[i].first);
		A[i].second = i + 1;
	}

	sort(A, A + n);
	For (i, n / 2)
		printf("%d %d\n", A[i].second, A[n - i - 1].second);

	return 0;
}