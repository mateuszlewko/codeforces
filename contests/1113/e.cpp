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
typedef long double ld;
#pragma endregion 

const int N = 2 * 100 * 1000 + 10;  // limit for array size
int n = N;  // array size
ld t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, ld value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ld query(int l, int r) {  // sum on interval [l, r)
  ld res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

unordered_map<int, int> forw;
unordered_map<int, int> back;

typedef pair<pii, pii> four;

four qs[N];

int main() {
    _upgrade;

	int q;
	cin >> q;

	vector<int> pos;

	For (i, q) {
		int kind;
		cin >> kind;

		if (kind == 1) {
			int t, s;
			cin >> t >> s;
			qs[i] = {{1, 0}, {t, s}};
			pos.push_back(t);
		} else if (kind == 2) {
			int t;
			cin >> t;
			qs[i] = {{2, 0}, {t, 0}};
			pos.push_back(t);
		} else if (kind == 3) {
			int l, r, v;
			cin >> l >> r >> v;
			qs[i] = {{3, l}, {r, v}};
			pos.push_back(l);
			pos.push_back(r);
		} else {
			assert(false);
		}
	}

	SORT(pos);
	int curr = 0;

	For (i, (int)pos.size()) {
		if (i > 0 && pos[i] != pos[i - 1]) {
			curr++;
		}

		forw[pos[i]] = curr;
		back[curr] = pos[i];
	}

	set<pii>
}

