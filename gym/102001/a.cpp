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

int b[142];

void readli(string& s)
{
  while (s.empty())
    getline(cin, s);
}

int main() {
	_upgrade;

	#ifndef LOCAL
  freopen("tests.in", "r", stdin);
  freopen("tests.out", "w", stdout);
  #endif

	int n, m;
  cin >> n >> m;
  for (int i=0; i<m; i++)
  {
    cin >> b[i];
  }
  bool passed = false;
  for (int i=0; i<n; i++)
  {
    string fac;
    readli(fac);
    int score = 0;
    int te;
    cin >> te;
    vector<int> tests;
    for (int j=0; j<te; j++)
    {
      int t;
      cin >> t;
      tests.push_back(t-1);
    }
    for (int j=0; j<te; j++)
    {
      int x, y, z;
      cin >> x >> y >> z;
      if (b[tests[j]] < x)
        score += 2;
      else if (b[tests[j]] < y)
        score += 3;
      else if (b[tests[j]] < z)
        score += 4;
      else
        score += 5;
    }
    int facs;
    cin >> facs;
    for (int j=0; j<facs; j++)
    {
      string name;
      int p;

      readli(name);
      cin >> p;
      if (score >= p)
      {
        cout << fac << " " << name << "\n";
        passed = true;
      }
    }
  }
  if (!passed)
  {
    cout << "Army\n";
  }

}

