#include <iostream>
#include <cstdio>
#include <algorithm>
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
	int n;
	string s;
	cin >> n >> s;

	For (i, (int)s.size())
		types.insert(s[i]);

	int cnt = types.size();
	int end = -1;
	int curr = 0;

	int res = 1<<30;

	For (i, (int)s.size())
	{
		while (curr < cnt and ++end < (int)s.size())
			if (++counting[s[end]] == 1)
				curr++;

		if (curr == cnt)
			res = min(res, end - i + 1);
		if (--counting[s[i]] == 0)
			curr--;
	}

	printf("%d\n", res);
	return 0;
}