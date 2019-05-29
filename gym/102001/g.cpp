#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 33;

ll powsa[maxn];
ll powsb[maxn];

ll silnia[maxn];

ll licz(ll x, ll y)
{
  return silnia[x] / (silnia[y] * silnia[x - y]);
}

int main()
{
  #ifndef LOCAL
  freopen("vasya.in", "r", stdin);
  freopen("vasya.out", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);

  int a, b, k;
  cin >> a >> b >> k;

  powsa[0] = 1LL;
  powsb[0] = 1LL;
  silnia[0] = 1LL;

  for(int i = 1; i <= k; i++)
  {
    powsa[i] = powsa[i - 1] * a;
    powsb[i] = powsb[i - 1] * b;
    silnia[i] = silnia[i - 1] * i;
  }

  ll ans = 0;
  for(int i = 0; i <= k; i++)
  {
    ans += licz(k, i) * powsa[i] * powsb[k - i];
  }

  cout << ans << endl;
  


  return 0;
}