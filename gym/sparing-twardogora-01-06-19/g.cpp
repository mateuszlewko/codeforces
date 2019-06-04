#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 105;

int in[maxn];

int ile[maxn][maxn];

int main()
{
  int n, K;
  cin >> n >> K;
  for(int i = 0; i < n; i++)
  {
    cin >> in[i];
  }

  for(int i = 0; i < n; i++)
  {
    int a = 0;
    for(int j = 0; j < in[i]; j++)
    {
      ile[i][a]++;
      a = (a + 1) % K;
    }
  }

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      for(int k = 0; k < n; k++)
      {
        if(abs(ile[i][k] - ile[j][k]) > 1)
        {

          cout << "NO\n";
          return 0;
        }
      }
    }
  }

  cout << "YES\n";

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < K; j++)
    {
      for(int k = 0; k < ile[i][j]; k++)
        cout << (j + 1) << " ";
    }
    cout << "\n";
  }

  return 0;
}