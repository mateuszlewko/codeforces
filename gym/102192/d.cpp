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

char tab[202][202];

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  while(t--){
    int n, m;
    std::cin >> n >> m;
    if(n % 2 == 1 && m % 2 == 1){
      FOR(i, n) {
        FOR(j, m) std::cout << '(';
        std::cout << "\n";
      }
    }else if(n % 2 == 1){
      FOR(i, n){
        FOR(j, m){
          std::cout << (j%2 == 0 ? '(' : ')');
        }
        std::cout << "\n";
      }
    }else if(m % 2 == 1){
      FOR(i, n){
        FOR(j, m){
          std::cout << (i%2 == 0 ? '(' : ')');
        }
        std::cout << "\n";
      }
    }else if(n+m-4 < std::max(n, m) + std::min(n, m)/2 - 1){
      bool swp = false;
      if(n < m) std::swap(n, m), swp = true;
      FOR(i, n){
        if(i%2 == 0){
          FOR(j, m) tab[i][j] = (j%2 == 0 ? '(' : ')');
        }else{
          tab[i][0] = '(';
          FOR(j, m-2) tab[i][j+1] = (j%2 == 0 ? '(' : ')');
          tab[i][m-1] = ')';
        }
      }
      if(swp){
        FOR(i, m){
          FOR(j, n){
            std::cout << tab[j][i];
          }
          std::cout << "\n";
        }
      }else{
        FOR(i, n){
          FOR(j, m){
            std::cout << tab[i][j];
          }
          std::cout << "\n";
        }
      }
    }else{
      FOR(i, n){
        FOR(j, m){
          if(i == 0) std::cout << '(';
          else if(j == 0) std::cout << '(';
          else if(i == n-1) std::cout << ')';
          else if(j == m-1) std::cout << ')';
          else std::cout << ((i+j)%2 == 0 ? '(' : ')');
        }
        std::cout << "\n";
      }
    }
  }
  
  return 0;
}