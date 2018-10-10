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

pii get_best(int n) {
	if (n <= 3) {
		return {n - 1, n};
	}
	else return {n - n/2, 2};
}

void go(int n, int mult) {
	if (n == 1) {
		cout << mult << " ";
		return;
	} else if (n <= 0) return;

	pii best = get_best(n);
	For (i, min(n, best.first)) {
		cout << mult << " ";
	}

	go(n - best.first, mult *= best.second);
}

int main() {
    _upgrade;
	int n;
	cin >> n;

	go(n, 1);

	// int ind = 1;
	// For (i, n) {
	// 	if (i < bestCnt) {
	// 		cout << "1 ";
	// 	} else {
	// 		cout << bestNum * ind << " ";
	// 		if (bestNum * ind > n) {
	// 			exit(11);
	// 		}
	// 		ind++;
	// 	}
	// }
}

