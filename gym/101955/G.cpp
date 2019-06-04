#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[6006][6006], u, n, m, x, y, W, k, last_ans;
vector <pair <ll, ll> > points, K[10000002];
vector <ll> dirs = {1, 1, -1, 1, 1, -1, -1, -1};

void solve(){

  last_ans = 0;
  while (!points.empty()){
      w[points.back().first][points.back().second] = 0;
      points.pop_back();
  }

  cin >> n >> m;
  for (int i = 0; i < n; i ++){
    cin >> x >> y >> W;
    w[x][y] = W;
    points.push_back({x, y});
  }

  for (int i = 0; i < m; i ++){
      cin >> u >> x >> y;
    //  cout << u << " " << x << " " << y << endl;
      x += last_ans; y += last_ans;
      x %= 6000;     y %= 6000;
      x ++;          y ++;


      if (u == 1){
        cin >> W;
        w[x][y] = W;
        points.push_back({x, y});
      }

      if (u == 2){
        w[x][y] = 0;
      }

      if (u == 3){
        cin >> k >> W;
        set <pair <ll, ll> > S; 
        for (auto e : K[k])
          for (int j = 0; j < dirs.size(); j += 2){
            ll new_x = x + dirs[j] * e.first;
            ll new_y = y + dirs[j + 1] * e.second;
            if (!(min(new_x, new_y) >= 0 and max(new_x, new_y) <= 6000) ) continue;
            if (S.count({new_x, new_y})) continue;
            if (w[new_x][new_y] > 0LL)
              w[new_x][new_y] += W;
            S.insert({new_x, new_y});
          }
      }

      if (u == 4){
  //      cout << x << " " << y << " " << k << endl;
        cin >> k;
        ll res = 0;
        set <pair <ll, ll> > S;
        for (auto e : K[k])
          for (int j = 0; j < dirs.size(); j += 2){
            ll new_x = x + dirs[j] * e.first;
            ll new_y = y + dirs[j + 1] * e.second;
            if (!(min(new_x, new_y) >= 0 and max(new_x, new_y) <= 6000) ) continue;
            if (S.count({new_x, new_y})) continue;
     //       cout << "! " << new_x << ", " << new_y << endl;
            res += w[new_x][new_y];
            S.insert({new_x, new_y});
          }
        cout << (last_ans = res) << "\n";
      }
  }
}

int main(){

  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  for (ll i = 0; i <= 10000000LL; i ++)
    for (ll j = i; j * j + i * i <= 10000000LL; j ++){
      K[j * j + i * i].push_back({i, j});
      if (i != j)
        K[j * j + i * i].push_back({j, i});
    }
      


  int t; cin >> t;
  for (int i = 1; i <= t; i ++){
      cout << "Case #" << i << ":\n";
      solve();
  }
  return 0;
}