#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#if DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string>) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#else
#define error(...) do {} while (0)
#endif

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#pragma endregion 

const int N = 200;
int n;
ll dists[N][N];

void kij() {
    For (k, n + 1) 
        For (i, n + 1) {
            For(j, n + 1) {
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
}

int main() {
    // _upgrade;
    ll sum;
    cin >> sum;
    int m;
    cin >> n >> m;

    For (i, n + 1) For (j, n + 1) {
        dists[i][j] = 1<<30;
    }

    For (i, m) {
        int a, b;
        cin >> a >> b;
        dists[a][b] = dists[b][a] = 1;
    }

    kij();

    ll got = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            got += dists[i][j];
        }
    }

    if (sum != got) {
        cout << "DIFF SUM for: " << sum << ", got: " << got << "\n";
    } else cout << "OK\n";
}

