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

const int N = 100 * 1000 + 10;
int A[N];
int B[N];


int main() {
    _upgrade;

	int n;
	cin >> n;
	
	vector<int> divsA, divsB;
	For (i, n) {
		cin >> A[i];
		if (i > 0) divsA.push_back(A[i] - A[i - 1]);
	}

	For (i, n) {
		cin >> B[i];
		if (i > 0) divsB.push_back(B[i] - B[i - 1]);
	}

	SORT(divsA);
	SORT(divsB);

	bool all_same = true;
	For (i, n - 1) {
		if (divsA[i] != divsB[i]) {
			all_same = false;
			break;
		}
	}

	if (A[0] == B[0] && all_same) cout << "Yes\n";
	else cout << "No\n";
}

