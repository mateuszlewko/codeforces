#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>

#define For(i, n) for(int i = 0; i < (n); i++)
#define ForD(i, n) for(int i = (n)-1; i >= 0; i--)

typedef long long ll;

using namespace std;

const int N = 200 * 1000 + 10;
int A[N];
int B[N];

struct tree
{
	static const int N = 1 << 18;
	int data[N << 1];
	function<int(const int&, const int&)> func;
	int inf;

	tree(function<int(int, int)> func, int* list, int n, int inf) : func{func}, inf{inf}
	{
		For (i, N)
			data[i + N] = i < n ? list[i] : inf;
		ForD (i, N)
			data[i] = func(data[i * 2], data[i * 2 + 1]);
	}

	int query(int p, int q) const
	{
		return query(0, N - 1, 1, p, q);
	}

	int query(int l, int r, int x, int p, int q) const
	{
		// printf("%d, %d, %d, %d\n", l, r, p, q);

		if (l >= p and r <= q)
			return data[x];

		int mid = (l + r) / 2;
		
		if (p <= mid and q > mid)
			return func(query(l, mid, x * 2, p, q), query(mid + 1, r, x * 2 + 1, p, q));
		if (p <= mid)
			return query(l, mid, x * 2, p, q);

		return query(mid + 1, r, x * 2 + 1, p, q);
	}
};


bool fcp_check(int start, int x, const tree& Atree, const tree& Btree)
{
	return Atree.query(start, start + x) >= Btree.query(start, start + x);
}

int find_common_pos(int start, int n, const tree& Atree, const tree& Btree)
{
	int beg = 0, end = n - start;

	while (beg < end)
	{
		int mid = (beg + end) / 2;
		// printf("fcp, beg: %d, end: %d\n", beg, end);

		if (fcp_check(start, mid, Atree, Btree))
			end = mid;
		else
			beg = mid + 1;
	}

	return beg;
}

int get_res(int pos, int n, const tree& Atree, const tree& Btree)
{
	int first = find_common_pos(pos, n, Atree, Btree);
	int beg = 0, end = n - first - pos;

	if (Atree.query(pos, pos + first) != Btree.query(pos, pos + first))
		return 0;
	if (first > 0 and Atree.query(pos, pos + first - 1) == Btree.query(pos, pos + first - 1))
		first--;

	while (beg < end)
	{
		int mid = (beg + end) / 2;
		// printf("gr: %d, %d\n", beg, end);

		if (Atree.query(pos + first, pos + first + mid) == Btree.query(pos + first, pos + first + mid))
			beg = mid + 1;
		else 
			end = mid;
	}

	if (Atree.query(pos + first, pos + first + beg) == Btree.query(pos + first, pos + first + beg))
		return beg + 1;
	return beg;
}

int main()
{
	int n;
	scanf("%d", &n);

	For (i, n)
		scanf("%d", &A[i]);
	For (i, n)
		scanf("%d", &B[i]);

	auto Atree = tree([](const int& lhs, const int& rhs) { return max(lhs, rhs); }, A, n, -(1<<30));
	auto Btree = tree([](const int& lhs, const int& rhs) { return min(lhs, rhs); }, B, n, (1<<30));

	ll sum = 0;
	For (i, n) {
		int r = get_res(i, n, Atree, Btree);
		// printf("gr res: %d\n", r);
		sum += r;
	}

	printf("%I64d\n", sum);
}