#include <iostream>
#include <cstdio>
#include <algorithm>

#define For(i, n) for(int i = 0; i < (n); i++)

using namespace std;

const int N = 100 * 1000 + 10;
int A[N];

int main()
{
	int n, l, r, ql, qr;
	scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);

	For (i, n)
		scanf("%d", &A[i]);

	if (l > r) {
		reverse(A, A+n);
		swap(l, r);
		swap(ql, qr);
	}

	int res = (n - 1) * ql;
	int sum = 0;
	int cnt = 0;
	for (int i = n - 1; i >= (n + 1) / 2; i--)
	{
		cnt++;
		sum += A[i];
		// printf("sum: %d, res: %d\n", sum, res);
		// printf("p1: %d, p2: %d\n", sum * (r - l), ql * (n - 2 * cnt - 1));
		res = min(res, sum * (r - l) + ql * (n / 2 - cnt));
	}

	// printf("res: %d\n", res);

	For (i, n)
		res += A[i] * l;


	printf("%d\n", res);
	return 0;
}