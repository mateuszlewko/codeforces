#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#if DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string>) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#else
#define error(...) do {} while (0)
#endif

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#pragma endregion 

const int N = 200 * 1000 + 10;
int sum_pref1[30][N];
int sum_pref2[30][N];

bool eq(const string& s1, pii p1, const string& s2, pii p2) {
	int n = p1.second - p1.first;
	if (n > 30) {
		For (i, 26) {
			int c1 = sum_pref1[i][p1.second] - sum_pref1[i][p1.first];
			if (c1 != sum_pref2[i][p2.second] - sum_pref2[i][p2.first])
				return false;
		}
	}

	For (i, n) {
		if (s1[p1.first + i] != s2[p2.first + i])
			return false;
	}

	return true;
}

bool equiv(const string& s1, pii p1, const string& s2, pii p2) {
	// printf("p1: %d %d | p2: %d %d\n", p1.first, p1.second, p2.first, p2.second);

	int n = p1.second - p1.first;
	if (n != p2.second - p2.first)
		return false;

	if (n == 0) exit(11);

	if (eq(s1, p1, s2, p2))
		return true;

	if (n % 2 == 1) return false;

	return (equiv(s1, {p1.first, p1.first + n / 2}, s2, {p2.first + n / 2, p2.second})
		&& equiv(s1, {p1.first + n / 2, p1.second}, s2, {p2.first, p2.first + n / 2}))
		|| (equiv(s1, {p1.first, p1.first + n / 2}, s2, {p2.first, p2.first + n / 2})
			&& equiv(s1, {p1.first + n / 2, p1.second}, s2, {p2.first + n / 2, p2.second}));
}

int main() {
    _upgrade;
	string s1, s2;
	cin >> s1 >> s2;  

	For (i, s1.size()) {
		For (j, 30)
			sum_pref1[j][i + 1] = sum_pref1[j][i];

		sum_pref1[s1[i] - 'a'][i + 1] = sum_pref1[s1[i] - 'a'][i] + 1;

	}

	For (i, s2.size()) {
		For (j, 30)
			sum_pref2[j][i + 1] = sum_pref2[j][i];

		sum_pref2[s2[i] - 'a'][i + 1] = sum_pref2[s2[i] - 'a'][i] + 1;
	}

	if (equiv(s1, {0, s1.size()}, s2, {0, s2.size()}))
		puts("YES");
	else puts("NO");
}

