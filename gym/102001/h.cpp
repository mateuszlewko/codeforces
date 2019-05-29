#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
  #ifndef LOCAL
  freopen("amplifiers.in", "r", stdin);
  freopen("amplifiers.out", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);


  int N;
  cin >> N;

  if(N % 2 == 0)
  {
    cout << "No solution\n";
    return 0;
  }

  vector<int> ans;
  while(N != 1)
  {
    if(((N - 1) / 2) % 2 == 0)
    {
      N = (N + 1) / 2;
      ans.pb(1);
    }
    else
    {
      N = (N - 1) / 2;
      ans.pb(2);
    }
    
  }

  reverse(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for(auto& x : ans)
    cout << x << " ";
  cout << "\n";


  return 0;
}