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

int n, m;
const int N = 2010;
const int inf = 1<<30;
int dist[N][N];
bool allow[N][N];

struct qCmp
{
    inline bool operator()(const pii &lhs, const pii &rhs) const
    {
        if (dist[lhs.first][lhs.second] != dist[rhs.first][rhs.second])
            return dist[lhs.first][lhs.second] < dist[rhs.first][rhs.second];
        return lhs < rhs;
    }
};

void dijkstra(int p, int q)
{
	For (i, N) For (j, N) dist[i][j] = inf;
    set<pii, qCmp> Q;
    dist[p][q] = 0;
    Q.insert({p, q});

    while (Q.size())
    {
        auto u = *Q.begin();
        Q.erase(Q.begin());

		int dx[] = {-1, 1, 0, 0};
		int dy[] = {0, 0, -1, 1};

        For (i, 4)
        {	
			int x = u.first + dx[i];
			int y = u.second + dy[i];
			int c = dy[i] != 0 ? 1 : 0;

			if (x < 0 || x >= n || y < 0 || y >= m || !allow[x][y]) continue;

            if (dist[x][y] > dist[u.first][u.second] + c)
            {
                auto it = Q.find({x, y});
                if (it != Q.end())
                    Q.erase(it);

                dist[x][y] = dist[u.first][u.second] + c;
                Q.insert({x, y});
            }
        }
    }
}


int main() {
    _upgrade;

	int p, q;
	cin >> n >> m >> p >> q;
	p--, q--;
	int mx, my;
	cin >> mx >> my;

	For (i, n) {
		string s;
		cin >> s;
		For (j, s.size()) {
			allow[i][j] = (s[j] == '.');
		}
	}

	dijkstra(p, q);
	int cnt = 0;
	For (i, n) {
		For (j, m) {
			if (dist[i][j] >= inf) continue;

			int cl = 0;
			int cr = 0;
			if (j < q) {
				cl += q - j;
			} else {
				cr += j - q;
			}

			int c = dist[i][j];
			c -= cl + cr;
			
			// error(i, j, dist[i][j], c, cl, cr);
			assert(c % 2 == 0);
			
			cl += c / 2;
			cr += c / 2;
			if (cl <= mx && cr <= my) cnt++;
		}
	}

	cout << cnt << "\n";
}

