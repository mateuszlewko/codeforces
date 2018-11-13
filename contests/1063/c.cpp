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

bool read_col() {
	string s;
	cin >> s;
	return s[0] == 'b';
}

int M = 1000 * 1000 * 1000;

void go(int n, int my_col, int p, int q, int max_my, int min_other) {
	int mid = (p + q) / 2;

	if (n == 0) {
		cout << "0 " << max_my << " 2 " << min(M, min_other) << endl;
		return;
	}

	cout << "1 " << mid << endl;
	if (read_col() != my_col) go(n - 1, my_col, p, mid, max_my, mid);
	else go(n - 1, my_col, mid, q, mid, min_other);
}

int main() {
    // _upgrade;
	int n;
	cin >> n;

	cout << "1 0" << endl;
	go(n - 1, read_col(), 1, M, 1, M + 1);
}

