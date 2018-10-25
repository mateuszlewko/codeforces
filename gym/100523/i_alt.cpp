#include <bits/stdc++.h>
using namespace std;

#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define For(i, n) for(int i = 0; i<(n); i++)
typedef long long ll;

const int N = 820;
int iq_a[N];
int iq_b[N];

int a_in(int x) { return (x + 2) * 2; }
int a_out(int x) { return (x + 2) * 2 + 1; }
int b_in(int x, int n) { return 2 * n + 10 + (x + 2) * 2; }
int b_out(int x, int n) { return 2 * n + 10 + (x + 2) * 2 + 1; }
const ll INF = 1<<30;

ll cap[2 * N][2 * N];
int deg[2 * N];
int adj[2 * N][2 * N];

void initAdj(int n) {
    For (u, n) 
        For (v, n)
            if (cap[u][v] || cap[v][u])
                adj[u][deg[u]++] = v;
}

int q[2 * N];
int pre[2 * N];

ll dinic(int n, int s, int t) {
    ll flow = 0;

    while (true) {
        memset(pre, -1, sizeof(pre));
        int qf = 0, qb = 0;
        pre[q[qb++] = s] = -2;

        while(qb > qf && pre[t] == -1) {
            for (int u = q[qf++], i = 0, v; i < deg[u]; i++) {
                if (pre[v = adj[u][i]] == -1 && cap[u][v])
                    pre[q[qb++] = v] = u;
            }
        }

        if (pre[t] == -1) break;

        For (z, n) {
            if (cap[z][t] && pre[z] != -1) {
                ll bot = cap[z][t];
                for (int v = z, u = pre[v]; u >= 0; v = u, u = pre[v]) {
                    bot = min(bot, cap[u][v]);
                }

                if (!bot) continue;
                cap[z][t] -= bot;
                cap[t][z] += bot;

                for (int v = z, u = pre[v]; u >= 0; v = u, u = pre[v]) {
                    cap[u][v] -= bot;
                    cap[v][u] += bot;
                }

                flow += bot;
            }
        }
    }

    return flow;
}

vector<int> G[N];

int allow[N][N];

int main ()
{
    ios::sync_with_stdio(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    For (i, k) {
        int a, b;
        cin >> a >> b;
        allow[a][b] = true;
    }

    // s - 0, t - 1

    ll total_iq = 0;

    For (i, n) {
        cin >> iq_a[i + 1];
        total_iq += iq_a[i + 1];
    }

    For (i, m) {
        cin >> iq_b[i + 1];
        total_iq += iq_b[i + 1];
    }

    for (int i = 1; i <= n; i++) {
        cap[a_in(i)][a_out(i)] = iq_a[i];
        cap[0][a_in(i)] = INF;
        
        for (int j = 1; j <= m; j++) {
            if (!allow[i][j])
                cap[a_out(i)][b_in(j, n)] = INF;
        }
    }

    for (int i = 1; i <= m; i++) {
        cap[b_in(i, n)][b_out(i, n)] = iq_b[i];
        cap[b_out(i, n)][1] = INF;
    }

    initAdj(2 * N);
    ll f = dinic(2 * n + 2 * m + 100, 0, 1);

    vector<int> correct_a, correct_b;
    for (int i = 1; i <= n; i++) {
        if (cap[a_in(i)][a_out(i)] != 0) 
            correct_a.push_back(i);
    }

    for (int i = 1; i <= m; i++) {
        if (cap[b_out(i, n)][b_in(i, n)] != 0) 
            correct_b.push_back(i);
    }

    // cout << "flow " << f << "\n";
    cout << total_iq - f << "\n";

    // For (i, 2 * n + 12) {
    //     For (j, 2 * m + 12) {
    //         cout << cap[i][j] << "  ";
    //     }

    //     cout << endl;
    // }
    // cout << endl;

    cout << correct_a.size() << "\n";
    for (int x : correct_a) {
        cout << x << " ";
    }

    cout << "\n" << correct_b.size() << "\n";
    for (int x : correct_b) {
        cout << x << " ";
    }
}