
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100005
#define MOD 1000000007
#define INF 1e9
#define vi vector<int>
#define vl vector<ll> 
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...)
;}
 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
//int bit[MAX], p[MAX];
//void upd(int i, int v=1) {while(i < MAX){bit[i] += v; i += i&-i;}}
//int read(int i) {int s=0; while(i > 0){s += bit[i]; i -= i&-i;} return s;}
//int fs(int i) {while(i != p[i]){p[i]=p[p[i]]; i=p[i];} return i;}
//ll modexp(ll a, ll b, ll c=MOD) { ll res=1;while(b){res=b&1?(res*a)%c:res; a=(a*a)%c; b>>=1;} return res; }
// auto f = [](int a, int b) -> int { return a+b; };
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,i;
  cin>>n;
  string str;
  cin>>str;
  int cnt = 0;
  int tot;
  for(i=0;i<n;++i)
    cnt += str[i] == 'G';
  tot = cnt;

  if(cnt >= n-1 or cnt <= 2) {
    cout<<cnt<<endl;
    return 0;
  }

  vector<int> vt;
  cnt = 1;
  int mx = 0;
  for(i=1;i<n;++i) {
    if(str[i] == str[i-1]) {
      cnt++;
    } else {
      vt.pb(cnt);
      cnt = 1;
    }
  }
  vt.pb(cnt);

  int pos = str[0] == 'G';
  for(i=0;i<vt.size();++i) {
    if(i%2 != pos) {
      if(vt[i] < tot) mx = max(mx, vt[i]+1);
      else mx = max(mx, vt[i]);
    }

    if(pos == i%2 and vt[i] == 1) {
      if(i-1>=0 and i+1<vt.size()) mx = max(mx, vt[i-1]+vt[i+1]+1);
    }
  }
  mx = min(mx, tot);
  cout<<mx<<endl;

  return 0;
}