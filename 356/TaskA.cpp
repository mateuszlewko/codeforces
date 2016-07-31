#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

#define For(i, n) for(int i = 0; i < (n); i++)

using namespace std;

const int N = 3 * 100 * 1000 + 10;
int Res[N];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	set<int> s;
	for (int i = 1; i <= n; i++)
		s.insert(i);

	For (i, m)
	{
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		
		auto it = s.lower_bound(l);
		vector<int> toErase;

		while (it != s.end() and *it <= r)
		{
			if (*it != x) 
			{
				Res[*it] = x;
				toErase.push_back(*it);
			}
			it++;
		}

		for (int v : toErase)
			s.erase(v);
	}

	For (i, n)
		printf("%d ", Res[i + 1]);
}