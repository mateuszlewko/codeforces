#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#ifndef JUST_CPP11
template<typename... Args>
void read(Args&... args)
{
    ((cin >> args), ...);
}

template<typename... Args>
void write(Args... args)
{
    ((cout << args << " "), ...);
}

template<typename... Args>
void writeln(Args... args)
{
    ((cout << args << " "), ...);
	cout << "\n";
}
#endif

template<typename T, typename U>
pair<T, U>& operator+=(pair<T, U> &lhs, const pair<T, U> &rhs){
	lhs.first += rhs.first;
	lhs.second += rhs.second;
	return lhs;
}

template<typename T, typename U>
pair<T, U>& operator-=(pair<T, U> &lhs, const pair<T, U> &rhs){
	lhs.first -= rhs.first;
	lhs.second -= rhs.second;
	return lhs;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &container) {
	for (auto &u : container) os << u << " ";
	return os;
}

template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds; 
using namespace std; 

template<typename T>
using pb_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

template<typename T, typename U>
pair<T, U> operator-(const pair<T, U> &l, const pair<T, U> &r) {
	return {l.first - r.first, l.second - r.second};
}
template<typename T, typename U>
pair<T, U> operator+(const pair<T, U> &l, const pair<T, U> &r) {
	return {l.first + r.first, l.second + r.second};
}

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#pragma endregion 

int convert(const string& s, int after_comma) {
	int res = 0;
	bool was_comma = false;

	For (i, s.size()) {
		if (s[i] == '.') {
			was_comma = true;
			continue;
		}

		if (was_comma) after_comma--;

		res *= 10;
		res += s[i] - '0';
	}

	while (after_comma != 0);

	return res;
}

int read_fix(int after_comma) {
	string s;
	cin >> s;

	return convert(s, after_comma);
}

int get_units(string sz) {
	if (sz[2] == '1') return 1000 * 3;
	if (sz[2] == '2') return 500 * 3;
	if (sz[2] == '3') return 1000;

	assert(false);
}

const int MX_MO = 10 * 1000 + 10;
const int MX_DR = 200 * 3 + 10;
int dp[MX_MO][MX_DR];

const int N = 10;
string names[N];
int drink_cost[N];
int drink_units[N];

void print_ans(int mo, int dr) {
	map<string, int> res;

	while (dp[mo][dr] > 0) {
		int id = dp[mo][dr];
		
		// assert(id != -1);

		string &name = names[id];
		res[name]++;

		mo -= drink_cost[id];
		dr -= drink_units[id];
	}

	if (res.empty()) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	for (auto [w, c] : res) {
		cout << w << " " << c << "\n";
	}
}

int main() {
    _upgrade;

	int money = read_fix(2);
	int drink = read_fix(1) * 3;
	int d;
	cin >> d;

	For (i, MX_MO) {
		For (j, MX_DR) dp[i][j] = -1;
	}

	dp[0][0] = 0;

	for (int i = 1; i <= d; i++) {
		int pc;
		string sz;
		int cost;

		cin >> names[i] >> pc >> sz;
		cost = read_fix(2);

		int units = get_units(sz) * pc / 100;
		
		drink_units[i] = units;
		drink_cost[i] = cost;

		For (mo, MX_MO) {
			For (un, MX_DR) {
				if (dp[mo][un] == -1) continue;
				if (mo + cost >= MX_MO || un + units >= MX_DR) continue;

				dp[mo + cost][un + units] = i;
			}
		}
	}

	if (dp[money][drink]) print_ans(money, drink);
	else cout << "IMPOSSIBLE\n";
}

