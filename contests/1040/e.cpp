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


const int N = 500 * 1000 + 10;
ll nums[N];
const int MOD = 1000 * 1000 * 1000 + 7; 

ll pow2(ll x, ll n) {
  if (n == 1) return x;
  ll rr = pow2(x, n / 2);

  return (rr * rr * (n % 2 == 0 ? 1LL : x)) % MOD;
}

int main() {
  _upgrade;
	ll n, m, k;
	cin >> n >> m >> k;
	 
	For (i, n) cin >> nums[i];

	map<ll, set<ll>> cnt; 


	For (i, m) {
		int a, b;
		cin >> a >> b;
	  cnt[nums[a] ^ nums[b]].insert(a);
	  cnt[nums[a] ^ nums[b]].insert(b);
  }

  ll wrong = 0;

  for (auto elem : cnt) {
    wrong += pow2(2LL, elem.second.size());
  }

	cout << pow2(2LL, k) << " " << pow2(2LL, n) << "\n";
  ll aaa = (pow2(2LL, k) * pow2(2LL, n)) % MOD;
  error(aaa);
  error(wrong);
  if (aaa < wrong)
  	cout << (aaa + MOD - wrong) % MOD << "\n";
	  else cout << aaa - wrong << "\n";
}

