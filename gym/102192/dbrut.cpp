#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int N = 6;
const int M = 8;

int tab[N][M];

int ile(){
  int ans = 0;
  FOR(i, N){
    int have = 0;
    bool bad = false;
    FOR(j, M){
      have += tab[i][j];
      if(have < 0){
        bad = true;
        break;
      }
    }
    if(!bad && have == 0) ans++;
  }
  FOR(j, M){
    int have = 0;
    bool bad = false;
    FOR(i, N){
      have += tab[i][j];
      if(have < 0){
        bad = true;
        break;
      }
    }
    if(!bad && have == 0) ans++;
  }
  return ans;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int best = 0;

  FOR(i, N) tab[i][M-1] = -1;
  FOR(i, M) tab[N-1][i] = -1;
  FOR(i, N) tab[i][0] = 1;
  FOR(i, M) tab[0][i] = 1;

  for(ll mask = 0; mask < (1ll<<(1ll*(N-2)*(M-2))); mask++){
    FOR(i, (N-2)*(M-2)) tab[1+i/M][1+i%M] = ((mask & (1ll<<i)) ? 1 : -1);
    int xd = ile();
    if(xd > best){
      std::cout << xd << std::endl;
      best = xd;
    }

    if(xd == 6){
      std::cout << "\n\n";
      FOR(i, N){
        FOR(j, M){
          std::cout << (tab[i][j] == 1 ? '+' : '-');
        }
        std::cout << "\n";
      }
    }

  }
  std::cout << best;
  
  return 0;
}