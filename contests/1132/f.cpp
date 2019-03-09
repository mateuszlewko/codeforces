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


const int N = 510;
const int INF = 1<<30;

ll dp[N][N];
char A[N];

int main() {
    _upgrade;

	int n;
	cin >> n;

	int ind = 0;
	For (i, n) {
		cin >> A[ind];
		A[ind] -= 'a';
		if (ind == 0 || A[ind] != A[ind - 1]) ind++;
	}

	For (i, ind) {
		For (p, ind) {
			if (p + i >= ind) break;
			
			if (i > 0) {
				dp[p][p + i] = INF;
				// For (k, 26) {
				ll cost = 0;
				int beg = 0;
				bool once = false;

				for (int j = 0; j <= i; j++) {
					if (A[p + j] == k) {
						once = true;
						// error(A[p+j], p, j, k);

						if (beg <= j - 1) {
							// error(p, beg, j);
							cost += dp[p + beg][p + j - 1];
						}
						beg = j + 1;
					}
				}
				
				if (beg <= i) {
					cost += dp[p + beg][p + i];
				}

				if (!once) continue;

				dp[p][p + i] = min(dp[p][p + i], cost + 1);
				// }
				// For (j, i) {
				// 	dp[p][p + i] = min(dp[p][p + i], dp[p][p + j] + dp[p + j + 1][p + i]);
				// }
				// if (i >= 2) {
				// 	dp[p][p + i] = min(dp[p][p + i], dp[p + 1][p + i - 1] + (A[p] == A[p + i] ? 1 : 2));
				// }
			} else {
				dp[p][p] = 1;
			}
		}
	}

	// For (i, n) {
	// 	For (j, n) {
	// 		write(dp[i][j]);
	// 	}
	// 	writeln();
	// }

	cout << dp[0][ind - 1] << "\n";
}

