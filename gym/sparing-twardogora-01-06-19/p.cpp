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

const int mod=1000000007;
int tab[100005],T[100005];
ll P[100005];
void sito(int n)
{
    for(int i=2;i*i<=n;i++)
      if(!tab[i])
        for(int j=i*i;j<=n;j+=i)
          tab[j]=1;
}
int M=0;
vector<int> L;
ll wynik=0;
void funkcja(int ile,ll x,int w)
{
  if(x>M)
    return;
  if(ile==L.size())
    {
      if(x==1)
        return;
      int pom=0;
      for(int j=x;j<=M;j+=x)
      {
          pom+=T[j];
      }
      int y=P[pom];
    //  printf("%lld %d %ḍ\n",x,pom,y);
      y--;
      y+=mod;
      y%=mod;
      if(w&1)
        wynik+=y;
      else
        wynik-=y;
      wynik+=mod;
      wynik%=mod;
      return;
    }
  funkcja(ile+1,x*L[ile],w+1);
  funkcja(ile+1,x,w);
}
int main() {
  int n;
  scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      int a;
      scanf("%d",&a);
      M=max(M,a);
      T[a]++;
    }
  sito(M+2);
  P[0]=1;
  for(int i=1;i<=n;i++)
  {
    P[i]=P[i-1]*2;
    P[i]%=mod;
  }

    for(int i=M;i>=2;i--)
      if(!tab[i])
        L.push_back(i);
    funkcja(0,1,0);
    ll odp=P[n]-1;
  //  printf("%lld %lld\n",odp,wynik);
    odp-=wynik;
    odp+=mod;
    odp+=mod;
    odp%=mod;
    printf("%lld",odp);
}
