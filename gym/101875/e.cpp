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

ll get_sum(ll n) {
	return n * (n + 1) / 2;
}

ll next_cut_cost(ll len, ll cuts) {
	cuts += 1;
	ll parts = cuts + 1;
	ll new_len = len - cuts;
	
	ll smaller_parts = parts - (new_len % parts);
	ll bigger_parts = new_len % parts;

	ll smaller_size = new_len / parts;
	ll bigger_size = (new_len + parts - 1) / parts;

	ll s = smaller_parts * get_sum(smaller_size) + bigger_parts * get_sum(bigger_size);

	return s;
}

int main() {
    _upgrade;

	int n;
	ll k;

	read(n, k);

	string ss;
	read(ss);

	priority_queue<pair<ll, pll>> lens;
	ll pay = 0;

	ss.push_back('0');
	ll curr = 0;

	For (i, (int)ss.size()) {
		if (ss[i] == '0') {
			ll s = get_sum(curr);
			pay += s;
			lens.push({s - next_cut_cost(curr, 0), {curr, 0}});
			curr = 0;
		} else {
			curr++;
		}
	}

	int res = 0;
	while (pay > k) {
		auto top = lens.top();
		auto [diff, data] = top;
		auto [len, cuts] = data;
		lens.pop();

		ll prev = next_cut_cost(len, cuts - 1);
		pay -= prev;

		ll s = next_cut_cost(len, cuts);

		pay += s;

		cuts += 1;
		lens.push({next_cut_cost(len, cuts) - s, {len, cuts}});

		res++;
	}

	writeln(res);
}

