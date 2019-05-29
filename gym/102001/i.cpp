#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1005;

pii zawod[maxn];

int konie[2][maxn];

const ll stala = 20000000;

ll czasy[maxn];

bool mniej(pair<pair<ll, int>, int> p1, pair<pair<ll, int>, int> p2)
{
  if(p1.fi.fi != p2.fi.fi)
    return p1.fi.fi < p2.fi.fi;
  
  return p1.fi.se > p2.fi.se;
}

int kolej[maxn];
ll konik[maxn];

int main()
{
  #ifndef DEBUG
  freopen("competitions.in", "r", stdin);
  freopen("competitions.out", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);

  int N, K;
  cin >> N >> K;
  for(int i = 0; i < N; i++)
    cin >> czasy[i] >> zawod[i].fi >> zawod[i].se;
  
  for(int i = 0; i < K; i++)
    cin >> konie[0][i];
  for(int i = 0; i < N; i++)
    cin >> konie[1][i];

  for(int i = 0; i < N; i++)
    czasy[i] = stala - czasy[i];
  
  vector<pair<pair<ll, int> , int> > V;
  for(int i = 0; i < N; i++)
    V.pb({{czasy[i], zawod[i].se}, i});

  sort(V.begin(), V.end(), mniej);

  //for(int i = 0; i < N; i++)
   // cout << V[i].fi.fi << " " << V[i].fi.se << " " << (V[i].se + 1) << " ";

  //cout << "\n";


  for(int i = 0; i < K; i++)
  {
    for(int j = 0; j < N; j++)
    {
      kolej[V[j].se] = j;
    }

    for(int j = 0; j < N; j++)
    {
      konik[j] = 3LL * konie[0][i] * konie[0][i] + 5LL * konie[0][i] * konie[1][j] + 2LL * konie[1][j] * konie[1][j];
    }

    sort(konik, konik + N);

    for(int j = 0; j < N; j++)
    {
      czasy[j] += stala - zawod[j].fi - konik[N - kolej[j] - 1];
    }

    V.clear();
    for(int j = 0; j < N; j++)
      V.pb({{czasy[j], zawod[j].se}, j}); 
    sort(V.begin(), V.end(), mniej);
  }

  for(int i = 0; i < N; i++)
    cout << (V[i].se + 1) << " ";

  cout << "\n";
  return 0;
}