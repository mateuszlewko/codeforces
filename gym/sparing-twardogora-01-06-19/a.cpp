#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 505;

map<int, int> M;

int main()
{
  int n;
  cin >> n;

  for(int i = 0; i < n * n; i++)
  {
    int a;
    cin >> a;
    M[a]++;
  }

  vector<int> V;
  for(auto& p : M)
    V.pb(p.fi);
  
  reverse(V.begin(), V.end());

  vector<int> res;

  int ind = 0;
  while(true)
  {

    if(ind >= V.size()|| res.size() == n)
      break;

    int cur = V[ind];

    if(M[cur] == 0)
    {
      ind++;
      continue;
    }

    int ile = 0;
    for(int i = 0; i < res.size(); i++)
    {
      if(res[i] % cur == 0)
        ile++;
    }

    if(M[cur] == 0)
    {
      ind++;
      continue;
    }

    int krot = 1;
    while(krot * krot + 2 * ile * krot < M[cur])
      krot++;

    for(int i = 0; i < res.size(); i++)
    {
      M[__gcd(cur, res[i])] -= 2 * krot;
    }
    
    for(int i = 0; i < krot; i++)
      res.pb(cur);
    
    M[cur] = 0;

    ind++;
  }

  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << "\n";

  return 0;
}