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
const ll INF = 1LL<<60;

const int LAST = -1;

vector<int> G[N * 2];
int visited[N * 2];
int parent[N * 2];
ll cap[N * 2][N * 2];
int cnt;

bool FindPath(const int &s, const int &t)
{
    queue<int> Q;
    Q.push(s);
    visited[s] = cnt;

    while (Q.size())
    {
        int u = Q.front();
        Q.pop();

        for (int v : G[u])
        {
            if (cap[u][v] > 0 and visited[v] < cnt)
            {
                visited[v] = cnt;
                parent[v] = u;

                if (v == t)
                    return true;
                Q.push(v);
            }
        }
    }

    return visited[t] == cnt;
}

ll FindMinOnPath(int x)
{
    ll res = INF;
    while (parent[x] != LAST)
    {
        res = min(cap[parent[x]][x], res);
        x = parent[x];
    }

    return res;
}

void CorrectPath(int x, const ll &val)
{
    while (parent[x] != LAST)
    {
        cap[parent[x]][x] -= val;
        cap[x][parent[x]] += val;
        x = parent[x];
    }
}

ll MaxFlow(int s, int t)
{
    ll res = 0;
    cnt = 1;
    parent[s] = LAST;

    while (FindPath(s, t))
    {
        ll Min = FindMinOnPath(t);
        res += Min;
        CorrectPath(t, Min);
        cnt++;
    }

    return res;
}

int allow[N][N];
int final_allow[N];

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
        
        G[a_in(i)].push_back(a_out(i));
        G[a_out(i)].push_back(a_in(i));
      
        G[a_in(i)].push_back(0);
        G[0].push_back(a_in(i));

        cap[0][a_in(i)] = INF;
        
        for (int j = 1; j <= m; j++) {
            if (!allow[i][j]) {
                cap[a_out(i)][b_in(j, n)] = INF;
                
                G[a_out(i)].push_back(b_in(j, n));
                G[b_in(j, n)].push_back(a_out(i));
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        cap[b_in(i, n)][b_out(i, n)] = iq_b[i];
        
        G[b_in(i, n)].push_back(b_out(i, n));
        G[b_out(i, n)].push_back(b_in(i, n));

        cap[b_out(i, n)][1] = INF;
        
        G[b_out(i, n)].push_back(1);
        G[1].push_back(b_out(i, n));
    }

    ll f = MaxFlow(0, 1);

    vector<int> correct_a, correct_b;
    for (int i = 1; i <= n; i++) {
        if (visited[a_out(i)] == cnt) {
            correct_a.push_back(i);
        }
    }

    for (int i = 1; i <= m; i++) {
        final_allow[i] = true; 
    }

    for (int x : correct_a) {
        for (int i = 1; i <= m; i++) {
            final_allow[i] &= allow[x][i];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        if (final_allow[i]) correct_b.push_back(i);
    }

    cout << total_iq - f << "\n";

    cout << correct_a.size() << "\n";
    for (int x : correct_a) {
        cout << x << " ";
    }

    cout << "\n" << correct_b.size() << "\n";
    for (int x : correct_b) {
        cout << x << " ";
    }
}