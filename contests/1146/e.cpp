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

const int N = 100 * 1000 + 10;
int A[N];

bool marked[2 * N + 10];

void apply(int n, vector<pii> &intervs) {

	for (auto ii : intervs) {
		for (int i = ii.first; i <= ii.second; i++) marked[i + N] = true;
	}	

	For (i, n) {
		int x = A[i];
		if (marked[x + N]) A[i] = -A[i];
	}

	for (auto ii : intervs) {
		for (int i = ii.first; i <= ii.second; i++) marked[i + N] = false;
	}	
}

int main() {
    _upgrade;

	int n, q;
	cin >> n >> q;

	int m = max(n, q);
	int sq = int(sqrt(m));
	error(sq);

	For (i, n) cin >> A[i];

	vector<pii> intervs;
	
	For (i, q) {
		char c;
		int x;
		cin >> c >> x; 

		// pii iv = c == '<' ? make_pair(-N, x - 1) : make_pair(x + 1, N);

		if (int(intervs.size()) >= sq) apply(n, intervs);

		vector<pii> intervs2;

		// vector<pii> inter;
		// vector<pii> not_inter;
		SORT(intervs);

		int last_interv_end = c == '<' ? -N : N;
		bool added = false;

		// if (intervs.empty()) {
		// 	intervs2.push_back(iv);
		// }

		if (c == '<') {
			For (j, intervs.size()) {
				if (intervs[j].second < x) {
					pii ii = {last_interv_end, intervs[j].first - 1};
					if (ii.second >= ii.first) intervs2.push_back(ii);

					last_interv_end = intervs[j].second + 1;
				} else {
					if (!added) {
						added = true;

						if (last_interv_end <= x - 1) {
							intervs2.push_back({last_interv_end, x - 1});
						}
					}

					intervs2.push_back(intervs[j]);
				}
			}
			
			if (!added) {
				added = true;

				if (last_interv_end <= x - 1) {
					intervs2.push_back({last_interv_end, x - 1});
				}
			}
		} else {
			ForD (j, intervs.size()) {
				if (intervs[j].first > x) {
					pii ii = {intervs[j].second + 1, last_interv_end};
					error(ii);
					if (ii.second >= ii.first) intervs2.push_back(ii);

					last_interv_end = intervs[j].first - 1;
				} else {
					if (!added) {
						added = true;

						if (x + 1 <= last_interv_end) {
							intervs2.push_back({x + 1, last_interv_end});
						}
					}

					intervs2.push_back(intervs[j]);
				}
			}
			
			if (!added) {
				added = true;

				if (x + 1 <= last_interv_end) {
					intervs2.push_back({x + 1, last_interv_end});
				}
			}
		}

		error(intervs2);
		intervs = intervs2;
	}

	apply(n, intervs);

	For (i, n) cout << A[i] << " ";
}

