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

const ll M = 1000 * 1000 * 1000 + 7;
typedef vector<vector<ll>> mat;

mat mult(const mat &x, const mat &y, int n) {
	mat res;
	res.resize(n);
	For (i, n) res[i].resize(n, 0);

	For (i, n) {
		For (j, n) {
			ll sum = 0;
			For (k, n) {
				sum += x[i][k] * y[k][j];
				sum %= M;
			}

			res[i][j] = sum;
		}
	}

	return res;
}

mat unit;

mat pow(mat x, ll n, int size) {
	if (n == 0) {
		return unit;
	}

	if (n % 2 == 0) {
		auto m = pow(x, n / 2, size);
		return mult(m, m, size);
	} else {
		auto m = pow(x, n - 1, size);
		return mult(m, x, size);
	}
}

void print(mat m, int size) {
	For (i, size) {
		For (j, size) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void init_unit(int n) {
	unit.resize(n);
	For (i, n) {
		unit[i].resize(n);
	}

	For (i, n) {
		For (j, n) {
			if (i == j) unit[i][i] = 1;
			else unit[i][j] = 0;
		}
	}
}

int main() {
    _upgrade;

	ll n;
	int m;
	cin >> n >> m;

	init_unit(m);
	// print(unit, m);

	mat x;
	x.resize(m);
	For (i, m) x[i].resize(m, 0);

	x[0][0] = 1;
	x[0][m - 1] = 1;

	for (int i = 1; i < m; i++) {
		x[i][i - 1] = 1;
	}

	auto res = pow(x, n, m);
	// For (i, m) {
	// 	For (j, m) {
	// 		cout << res[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << res[0][0] << "\n";
}

