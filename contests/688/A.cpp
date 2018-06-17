#include <iostream>
#include <cstdio>
#define For(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const int N = 110;
char data[N];

bool check(int n)
{
	For (i, n)
		if (data[i] == '0')
			return true;

	return false;
}

int main()
{
	int n, d;
	scanf("%d %d", &n, &d);

	int best = 0;
	int curr = 0;

	For (i, d)
	{
		For (j, n)
			scanf(" %c", &data[j]);

		if (check(n))
			curr++;
		else
			curr = 0;

		best = max(curr, best);
	}

	printf("%d\n", best);
}