#include<bits/stdc++.h>
#define For(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool taken[100][100];

int main() {
	ios::sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;

  For (i, k) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    taken[x][y] = true;
  }

  For (i, n) {
    For (j, m) cout << (taken[i][j] ? "#" : ".");
    cout << endl;
  }
}
