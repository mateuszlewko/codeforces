#include <iostream>
#include <cstdio>
#include <algorithm>

#define For(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main()
{
	ios::sync_with_stdio(0);

	string s;
	cin >> s;
	cout << s;

	if (s != "0")
	{ 
		reverse(begin(s), end(s));
		cout << s;
	}
}