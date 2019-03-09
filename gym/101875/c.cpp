#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

const int MP = 1000 * 1000 + 10;
bool not_prime[MP];

vector<ll> get_primes() {
	vector<ll> res; 
	
	for (ll i = 2; i < MP; i++) {
		if (not_prime[i]) continue;

		res.push_back(i);

		for (ll j = i * i; j < MP; j += i) {
			not_prime[j] = true;
		}
	}

	return res;
}

void add_fac(map<ll, ll> &fac_cnt, ll x, const vector<ll> &ps) {
	int ind = 0;

	while (ind < (int)ps.size() && ps[ind] <= x) {
		ll f = ps[ind];
		while (x % f == 0) {
			fac_cnt[f]++;
			x /= f;
		}

		ind++;
	}

	if (x != 1) {
		fac_cnt[x]++;
	}
}

const int B = 1010;
const ll M = 1000 * 1000 * 1000 + 7;
ll dp[B * 10];

int main() {
    _upgrade;

	int b, n;
	read(b, n);

	auto ps = get_primes();
	SORT(ps);

	map<ll, ll> fac_cnt;

	For (i, n) {
		ll v;
		read(v);
		add_fac(fac_cnt, v, ps);
	}

	dp[1] = 1;

	for (auto [p, p_cnt] : fac_cnt) {
		ForD (i, B / 2) {
			if (dp[i] == 0) continue;
			for (ll j = 2; j <= p_cnt + 1; j++) {
				if (i * j > b) break;

				dp[i * j] = (dp[i * j] + dp[i]) % M;
			}
		}
	}

	writeln(dp[b]);
}

