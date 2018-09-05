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

ll n, k;
bool get_ans() {
  string s;
  cin >> s;
  if (s[0] == 'B') exit(11);

  return s[0] == 'Y';
}

std::random_device rd;  //Will be used to obtain a seed for the random number engine
  
void go(ll p, ll q) {
  p = max(1LL, p);
  q = min(n, q);

  ll mid = (p + q) / 2LL;

 std::mt19937_64 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

  if (q - p + 1 <= 4LL * k + 5LL) {
    auto rnd = uniform_int_distribution<ll>(p, q);
    ll x = rnd(gen);

    cout << x << " " << x << "\n";
	cout.flush();
    if (get_ans()) return;
    else return go(p - k, q + k);
  }

  cout << p << " " << mid << "\n";
  cout.flush();
  if (get_ans()) return go(p - k, mid + k);
  else return go(mid - k + 1LL, q + k);
}

int main() {
    _upgrade;
    cin >> n >> k;

    go(1LL, n);
    cout.flush();
}

