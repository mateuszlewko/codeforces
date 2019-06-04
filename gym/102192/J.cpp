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

struct Tree{
  int BOTTOM;
  VI t;
  void build(VI ar){
    BOTTOM = 1;
    while(BOTTOM < SZ(ar)) BOTTOM *= 2;
    t.resize(BOTTOM*2);
    FOR(i, SZ(ar)) t[i+BOTTOM] = ar[i];
    for(int i = BOTTOM-1; i >= 1; --i){
      t[i] = std::max(t[i<<1], t[(i<<1)+1]);
    }
  }
  int query(int a, int b){
    a += BOTTOM;
    b += BOTTOM+1;
    int mx = 0;
    while(a < b){
      if(a&1) mx = std::max(mx, t[a++]);
      if(b&1) mx = std::max(mx, t[--b]);
      a >>= 1; b >>= 1;
    }
    return mx;
  }
  void update(int a, int v){
    a += BOTTOM;
    t[a] = v;
    while(a > 1){
      a >>= 1;
      t[a] = std::max(t[a<<1], t[(a<<1)+1]);
    }
  }
};

int find_bigger(Tree &t, int a, int b, int q){
  if(a > b) return -1;
  while(a < b){
    int mid = (a+b)/2;
    if(t.query(a, mid) <= q) a = mid+1;
    else b = mid;
  }
  if(t.query(a, b) <= q) return -1;
  return a;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  while(t--){
    int n, m;
    std::cin >> n >> m;
    VI A(n);
    FOR(i, n) std::cin >> A[i];
    VI next(n, -1);
    std::set<PII> waiting;
    FOR(i, n){
      while(!waiting.empty() && waiting.begin()->X < A[i]) next[waiting.begin()->Y] = i, waiting.erase(waiting.begin());
      waiting.insert(MP(A[i], i));
    }
    VI wyn(n);
    std::vector<bool> path(n);
    path[0] = true;
    VI prev(n, -1);
    int last = -1;
    FOR(i, n){
      prev[i] = last;
      if(path[i]){
        last = i;
        if(next[i] != -1) path[next[i]] = true;
      }
    }
    for(int i = n-1; i >= 0; --i){
      if(next[i] != -1) wyn[i] = wyn[next[i]]+1;
      else wyn[i] = 1;
    }
    Tree tree;
    tree.build(A);
    FOR(_, m){
      int p, q;
      std::cin >> p >> q;
      p--;
      if(q <= A[p]){
        if(!path[p]){
          std::cout << wyn[0] << "\n";
        }else if(p == 0){
          int nxt = find_bigger(tree, 1, n-1, q);
          if(nxt == -1) std::cout << 1 << "\n";
          else std::cout << wyn[nxt] + 1 << "\n";
        }else{
          int pr = prev[p];
          if(A[pr] < q){
            int curwyn = wyn[0]-wyn[p]+1;
            int nxt = find_bigger(tree, p+1, n-1, q);
            if(nxt == -1) std::cout << curwyn << "\n";
            else std::cout << curwyn + wyn[nxt] << "\n";
          }else{
            int curwyn = wyn[0]-wyn[pr]+1;
            tree.update(p, q);
            int nxt = find_bigger(tree, pr+1, n-1, A[pr]);
            tree.update(p, A[p]);
            if(nxt == -1) std::cout << curwyn << "\n";
            else std::cout << curwyn + wyn[nxt] << "\n";
          }
        }
      }else{
        if(path[p]){
          int curwyn = wyn[0] - wyn[p] + 1;
          int nxt = find_bigger(tree, p+1, n-1, q);
          if(nxt == -1) std::cout << curwyn << "\n";
          else std::cout << curwyn + wyn[nxt] << "\n";
        }else{
          int pr = prev[p];
          if(A[pr] < q){
            int curwyn = wyn[0]-wyn[pr]+2;
            int nxt = find_bigger(tree, p+1, n-1, q);
            if(nxt == -1) std::cout << curwyn << "\n";
            else std::cout << curwyn + wyn[nxt] << "\n";
          }else{
            std::cout << wyn[0] << "\n";
          }
        }
      }
    }
  } 
  
  return 0;
}