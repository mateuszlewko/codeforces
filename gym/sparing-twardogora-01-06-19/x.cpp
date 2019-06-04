#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 205;
const int inf = 1e9;

int in[maxn];

int N;
int tab[maxn * maxn];
int LIS[maxn * maxn];

int ile[maxn][400];

void licz()
{
  for(int i = 0; i < maxn * maxn; i++)
  {
    LIS[i] = inf;
  }
  LIS[0] = 0;

  for(int i = 0; i < N; i++)
  {
    int ind = upper_bound(LIS, LIS + N + 10, tab[i]) - LIS;
    LIS[ind] = tab[i];
  }
}

int main()
{
  int n, T;
  cin >> n >> T;
  for(int i = 0; i < n; i++)
    cin >> in[i];

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 305; j++)
      ile[i + 1][j] = ile[i][j];
    
    ile[i + 1][in[i]]++;
    //cout << (i + 1) << ": " << tab[i] << " " << ile[i + 1][tab[i]] << "\n";
  }

  if(T <= 105)
  {
    N = n * T;
    for(int i = 0; i < N; i++)
    {
      tab[i] = in[i % n];
    }    
    licz();
    int ans = 0;
    for(int i = 0; i < N + 1; i++)
    {
     // cout << LIS[i] << "\n";
      if(LIS[i] != inf)
        ans = i;
    }
    cout << ans << "\n";
    return 0;
  }

  N = n * 106;
  int ans = T;
  for(int i = 0; i < N; i++)
  {
    tab[i] = in[i % n];
  }
  
  for(int i = 0; i < maxn * maxn; i++)
  {
    LIS[i] = inf;
  }
  LIS[0] = 0;

 // cout << ile[n][1] << "\n";

  for(int i = 0; i < N; i++)
  {
    int ind = upper_bound(LIS, LIS + N + 10, tab[i]) - LIS;
    LIS[ind] = tab[i];
    int costam1 = i / n;
    int costam = T - costam1 - 1;
    int temp = costam * ile[n][tab[i]] + ile[n][tab[i]] - ile[(i % n) + 1][tab[i]];
    ans = max(ans, ind + temp);
  }

  cout << ans << "\n";

  return 0;
}