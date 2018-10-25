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
typedef long double ld;

#pragma endregion 

const int N = 100 * 1000 + 10;
pair<ld, ld> points[N];
const ld inf = 1e18;

bool check(ld r, int n) {
    ld left = -inf;
    ld right = inf;

    for (int i = 0; i < n; i++) {
        auto dist = abs(r - points[i].second);
        auto s = r * r - dist * dist;

        // printf("left: %Lf, right: %Lf\n", left, right);

        if (s < 0.0) return false;
        auto delta = sqrt(s);
        left = max(left, points[i].first - delta);
        right = min(right, points[i].first + delta);
    }
    
    return left <= right;
}

int main() {
    int n;
    scanf("%d", &n);

    bool was_down = false; 
    bool was_up = false;

    ld beg = 0.0, end = inf;

    For (i, n) {
        cin >> points[i].first >> points[i].second;

        if (points[i].second < 0) was_down = true;
        else was_up = true;

        points[i].second = abs(points[i].second);
        beg = max(beg, points[i].second * 0.5);
    }

    if ((was_down ^ was_up) != 1) {
        cout << "-1\n";
        return 0;
    }

    For (i, 80) {
        ld mid = (beg + end) / 2;

        if (check(mid, n)) end = mid;
        else beg = mid;
    }

    printf("%.7Lf\n", beg);
}

