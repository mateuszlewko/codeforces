#include <bits/stdc++.h>
using namespace std;

const int N = 1<<19;
int pokryte[N * 2];
int suma[N * 2];
int n; 

#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define For(i, n) for(int i = 0; i<(n); i++)


void update_(int l, int r, int p, int q, int x, int diff) {
    if (l <= p && r >= q) {
        suma[x] += diff;
    } else {
        int mid = (p + q) / 2;
        if (l <= mid) {
            update_(l, r, p, mid, x * 2, diff);
        }
        if (r > mid) {
            update_(l, r, mid + 1, q, x * 2 + 1, diff);
        }
    }

    if (suma[x] > 0) {
        pokryte[x] = min(n - 1, q) - p + 1;
    } else {
        pokryte[x] = (x * 2 < 2 * N ? pokryte[x * 2] : 0)
                  + (x * 2 + 1 < 2 * N ? pokryte[x * 2 + 1] : 0);
    }

    // cout << "x: " << x << ", pokryte: " << pokryte[x] << endl;
}

void update(int l, int r, int diff) {
    update_(l, r, 0, N - 1, 1, diff);
}

vector<int> holes;

pair<int, int> bounds(int x, int l) {
    int l_pos = lower_bound(begin(holes), end(holes), x - l) - begin(holes);
    int r_pos = upper_bound(begin(holes), end(holes), x + l) - begin(holes) - 1;
    
    // cout << "lpos: " << l_pos << " rpos " << r_pos << endl;

    if (r_pos < 0 || l_pos >= holes.size() || l_pos > r_pos) return {-1, -1};
    return {l_pos, r_pos};
}

void set_cd(int x, int l, int diff) {
    auto pos = bounds(x, l);
    // cout << "ft: " << pos.first << ", snd: " << pos.second << endl;
    if (pos.first != -1)
        update(pos.first, pos.second, diff);
}

int main ()
{
    ios::sync_with_stdio(0);

    int m, d, l;
    holes.push_back(0);

    // l - zasięg, d - dni, m - liczba cd
    cin >> n >> m >> d >> l;

    For (i, n - 1) {
        int x;
        cin >> x;
        holes.push_back(x);
    }

    For (i, m) {
        int x;
        cin >> x;
        set_cd(x, l, 1);      
    }

    cout << pokryte[1] << "\n";

    For (i, d) {
        int p, r;
        cin >> p >> r;
        
        set_cd(p, l, -1);
        set_cd(r, l, 1);
        cout << pokryte[1] << "\n";
    }
}