#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 105;

int N;
ll C, P, T;
int A[maxn];
int pref[maxn];


bool check(int x)
{
  int ostatnie = 0;
  for(int i = 1; i <= N; i++)
  {
    ostatnie = i;
    if(pref[i] >= x)
      break;
  }

  //cout << ostatnie << "\n";

  ll suma = 0;
  int extra = 0;
  for(int i = ostatnie - 1; i  >= 0; i--)
  {
    int ile = x - pref[i];
    if(ile < 0)
      continue;
    //cout << i << ": " << ile << "\n";
    int tem = ile / C;

    if(tem * C != ile)
      tem++;
    
    suma += 1LL * tem * 2 * (i + 1) * P;
    x -= tem * C;
  }

  return suma <= T;
}

int main()
{
  #ifndef DEBUG
  freopen("elevator.in", "r", stdin);
  freopen("elevator.out", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);

  cin >> N >> C >> P >> T;
  for(int i = 0; i < N; i++)
    cin >> A[i];

  for(int i = 0; i < N; i++)
    pref[i + 1] = pref[i] + A[i];

  if(!check(1))
  {
    cout << 0 << "\n";
    return 0;
  }

  int l = 0;
  int r = 1e9 + 5;

  while(l + 1 < r)
  {
    int mid = (l + r) / 2;
    if(check(mid))
      l = mid;
    else
      r = mid;
    
  }

  cout << min(l, pref[N]) << "\n";

  //for(int i = 0; i < 15; i++)
  //  cout << i << ": " << check(i) << "\n";

  return 0;
}