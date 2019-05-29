#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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

int di[1000042];
vector<int> p1[1000042];
int dp[1000042];

void init()
{
  for (int i=2; i<1000042; i++)
  {
    if (p1[i].empty())
    {
      for (int j=i; j<1000042; j+=i)
      {
        p1[j].push_back(i);
      }
    }

    di[i] = 1;
    for (int k : p1[i])
    {
      di[i] *= k;
    }
    
  }
}

int main() {
	_upgrade;

	#ifndef DEBUG
  freopen("rifleman.in", "r", stdin);
  freopen("rifleman.out", "w", stdout);
  #endif

  init();

  int n,m;
  cin >> n >> m;
  if (n == 1 || m == 1)
  {
    cout << (n*m > 1 ? 1 : 0) << "\n";
    return 0;
  }
  ll ans = n-1;
  dp[1] = n-1;
  for (int i=2; i<m; i++)
  {
    if (di[i] != i)
    {
      dp[i] = dp[di[i]];
    }
    else
    {
      dp[i] = n-1;

      vector<int> divs;
      divs.push_back(p1[i][0]);
      for (int k=1; k<p1[i].size(); k++)
      {
        vector<int> new_divs;
        for (auto p2 : divs)
        {
          new_divs.push_back(p2*p1[i][k]);
        }
        for (auto p2 : new_divs)
          divs.push_back(p2);

        divs.push_back(p1[i][k]);
      }

      for (int d : divs)
      {
        if (p1[d].size()%2)
          dp[i] -= (n-1) / d;
        else
          dp[i] += (n-1) / d;
        
      }
    }
    ans += dp[i];
    //cout << i << " " << dp[i] << "\n";
    
  }
  cout << ans+2 << "\n";

	

}

