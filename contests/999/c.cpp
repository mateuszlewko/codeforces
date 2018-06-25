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

vector<int> pos[30]; 
const int N = 4 * 100 * 1000 + 10;
bool invalid[N];

void go(int letter, int curr_pos, int left) {
	if (left == 0) return;
	if (pos[letter].size() == curr_pos)
		return go(letter + 1, 0, left);
	
	invalid[pos[letter][curr_pos]] = true;
	return go(letter, curr_pos + 1, left - 1);
}

int main() {
    _upgrade;

	int n, k; 
	string s; 
	cin >> n >> k >> s;


	For (i, n) 
		pos[s[i] - 'a'].push_back(i);

	go(0, 0, k);
	For (i, n) {
		if (!invalid[i])
			cout << s[i];
	}

	cout << "\n";
}

