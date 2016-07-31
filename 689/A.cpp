#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> pii;

inline pii operator+(const pii& lhs, const pii& rhs)
{
	return {lhs.first + rhs.first, lhs.second + rhs.second};
}

inline pii operator-(const pii& x)
{
	return {-x.first, -x.second};
}

pii get_vec(int from, int to)
{
	return {to / 3 - from / 3, to % 3 - from % 3};
}

bool out_bounds(const pii& pos)
{
	if (pos.first == 3 and pos.second == 1)
		return false;

	return pos.first < 0 or pos.second >= 3 or pos.second < 0 or pos .first >= 3;
}

bool test(const vector<pii>& v, int x)
{
	pii curr;
	if (x != 0)
	{
		x--;
		curr = {x / 3, x % 3};
	}
	else
		curr = {3, 1};

	for (auto& m : v)
	{
		curr = curr + m;
		if (out_bounds(curr))
			return false;
	}

	return true;
}

void transform (char& c)
{
	if (c != '0')
		c -= '1';	
	else
		c = 10;
}

int main()
{
	//ios::sync_with_stdio(0);

	int n;
	scanf("%d", &n);

	char c;
	scanf(" %c", &c);

	int first = c - '0';
	transform(c);

	vector<pii> v;
	For (i, n - 1)
	{
		char d;
		scanf(" %c", &d);
		
		transform(d);
		v.push_back(get_vec(c, d));
		// printf("vec: %d, %d\n", get_vec(c, d).first, get_vec(c, d).second);
		c = d;
	}

	For (i, 10)
		if (i != first and test(v, i))
		{
			// printf("i: %d\n", i);
			puts("NO");
			return 0;
		}

	puts("YES");
}