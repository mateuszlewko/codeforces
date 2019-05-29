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

bool taken[100042];

int main() {
	_upgrade;

	#ifndef DEBUG
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  #endif

  int n, m;
  cin >> n >> m;
  int org_n = n;
  if (n < 3 || m < n)
  {
    cout << "No solution\n";
    return 0;
  }
  vector<int> circles;
  while (n >= 5 && n != m)
  {
    n -= 2;
    m -= 3;
    circles.push_back(3);
  }
  if (n != m)
  {
    cout << "No solution\n";
    return 0;
  }

  circles.push_back(n);
  int to_add = max(0, n - 10);
    int fre = 0;

  if (to_add > 0)
  {
    circles[circles.size()-1] -= to_add;
    for (int i=0; i<circles.size(); i++)
    {
      int ad = min(10 - circles[i], to_add);
      to_add -= ad;
      circles[i] += ad;
    }
    for (int x : circles)
      fre += x;
    fre -= (int)circles.size() - 1;

    if (fre < to_add)
    {
      cout << "No solution\n";
      return 0;
    }

  /*
    if (circles.size() == 1)
      fre = 10;
    else
    {
      for (int i=0; i<circles.size(); i++)
      {
        fre += (i == 0 || i+1 == circles.size() ? 9 : 8);
      }
    }
      if (fre < to_add)
      {
        cout << "No solution\n";
        return 0;
      }
    */
    

  }

  cout << circles.size() << "\n";
  int w = 1;
  for (int vs : circles)
  {
    cout << vs;
    for (int i=0; i<vs-1; i++)
      cout << " " << w++;
    cout << " " << w << "\n";
    //taken[w] = 1;
  }
  //taken[w] = 0;

  cout << to_add << "\n";
  if (to_add == 0)
    return 0;
  int fr = 1;
  for (int i=fre+1; i<=org_n; i++)
  {
    
    cout << fr << " " << i << "\n";
    fr++;
  }
  return 0;

  
	

}

