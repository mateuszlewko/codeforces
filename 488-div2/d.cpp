#include <bits/stdc++.h> 

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)

using namespace std;

bool check(int l, int r, pair<int, int> p) {
    if (l == p.first && r != p.second) return l;
    if (l == p.second && r != p.first) return l;
    if (r == p.first && l != p.second) return r;
    if (r == p.second && l != p.first) return r;

    return 0;
}

int vis[100];

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n, m;
    scanf("%d %d", &n, &m);

    vector<pair<int, int>> ps; 
    For (i, n) {
        int a, b; 
        scanf("%d %d", &a, &b);
        ps.push_back({min(a, b), max(a, b)});
    }

    int total_cnt = 0;
    int ans = 0;

    For (i, m) {
        int a, b; 
        scanf("%d %d", &a, &b);
        int l = min(a, b);
        int r = max(a, b);

        int cnt = 0;
        For (j, n) {
            int curr = check(l, r, ps[j]);

            if (curr && vis[j] && vis[j] != curr) {
                puts("-1");
                return 0;
            }

            if (curr) {
                vis[j] = curr;
                cnt++;
                ans = curr;
            }
        }

        // printf("cnt: %d for %d %d\n", cnt, l, r);

        if (cnt == 1)
            total_cnt++;
        else if (cnt > 1) {
            puts("-1");
            return 0;
        }
    }

    if (total_cnt == 1) {
        printf("%d\n", ans);
    }
    else puts("0");
}

