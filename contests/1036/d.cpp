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

const int N = 3 * 100 * 1000 + 10;
int A[N];
int B[N];

int n, m;

int go(int ixA, int ixB, int len, ll sumA, ll sumB) {
	if (sumA == sumB && sumA > 0) 
		return go(ixA, ixB, len + 1, 0, 0);

	if (ixA >= n && ixB >= m) {
		if (sumA == 0 && sumB == 0)
			return len;
		else return -1;
	}

	if (sumA == 0 && sumB == 0 && A[ixA] == B[ixB]) {
		return go(ixA + 1, ixB + 1, len + 1, sumA, sumB);
	} else if (sumA == 0 && sumB == 0)
		return go(ixA + 1, ixB + 1, len, A[ixA], B[ixB]);
	
	if (sumA < sumB) {
		if (ixA < n)
			return go(ixA + 1, ixB, len, sumA + A[ixA], sumB);
		else return -1;
	} else if (sumA > sumB) {
		if (ixB < m)
			return go(ixA, ixB + 1, len, sumA, sumB + B[ixB]);
		else return -1;
	}	
}

int main() {
    _upgrade;
	cin >> n;
	For (i, n) cin >> A[i];
	cin >> m;
	For (i, m) cin >> B[i];

	cout << go(0, 0, 0, 0, 0);
}

