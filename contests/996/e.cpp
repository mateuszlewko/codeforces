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

int get_quadrant (const pii & p)
{
    int result = 4; 

    if (p.first > 0 && p.second > 0)
        return 1;
    else if(p.first < 0 && p.second > 0)
        return 2;
    else if(p.first < 0 && p.second < 0)
        return 3;
    return result;
}

int cmp(const pii& lhs, const pii& rhs) {
	int lq = get_quadrant(lhs);
	int rq = get_quadrant(rhs);

	if (lq != rq) return lq < rq;
	return -atan2(lhs.first, -lhs.second) < -atan2(rhs.first, -rhs.second);
}

const int N = 100 * 1000 + 10;
pair<pii, int> points[N];

bool ans[N];

void print_ans(int take_plus, int start_pos, int n) {
	For (i, take_plus) 
		ans[points[(i + start_pos) % n].second] = true;

	For (i, n) 
		printf(!ans[i] ? "-1 " : "1 ");

	puts("");
}

bool try_find(int start_pos, int n) {
	ll xa = 0, ya = 0;
	ll xb = 0, yb = 0;

	For (i, n) {
		xb += points[(i + start_pos) % n].first.first;
		yb += points[(i + start_pos) % n].first.second;
	}	

	const ll MAX = 2250000000000LL; 

	if (xb * xb <= MAX - yb * yb) {
		print_ans(0, start_pos, n);
		return true;
	}

	For (i, n) {
		xa += points[(i + start_pos) % n].first.first;
		ya += points[(i + start_pos) % n].first.second;
		xb -= points[(i + start_pos) % n].first.first;
		yb -= points[(i + start_pos) % n].first.second;

		ll x = xb - xa;
		ll y = yb - ya;
		if (x * x <= MAX - y * y) {
			print_ans(i + 1, start_pos, n);
			return true;
		}
	}

	return false;
}

int main() {
    // _upgrade;
	int n;
	scanf("%d", &n);

	For (i, n) {
		scanf("%d %d", &points[i].first.first, &points[i].first.second);
		points[i].second = i;
	}

	sort(points, points + n, [](auto l, auto r) { return cmp(l.first, r.first); });

	for (int i = 0; i < 20; i++) {
		if (try_find((n / 20) * i, n))
			return 0;
	}

	return 11;
}

