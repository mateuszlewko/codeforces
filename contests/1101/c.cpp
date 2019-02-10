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

const int N = 100 * 1000 + 10;
pair<pii, int> A[N];
int ans[N];

int main() {
    _upgrade;

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		For (i, n) {
			cin >> A[i].first.first >> A[i].first.second;
			A[i].second = i;
		}

		sort(A, A + n);
		int end1 = 0;
		int end2 = 0;


		int fs_cnt = 0;
		int sd_cnt = 0;

		bool wrong = false;

		For (i, n) {
			pii seg = A[i].first;
			int ix = A[i].second;

			// error(seg.first, end1, end2, ix, seg.first<=end1);

			if (seg.first <= end1 || fs_cnt == 0) {
				if (seg.first <= end2) {
					wrong = true;
					break;
				} 

				end1 = max(end1, seg.second);
				ans[ix] = 1;
				fs_cnt++;
			} else {
				end2 = max(end2, seg.second);
				ans[ix] = 2;
				sd_cnt++;
			}

			// error(ans[ix]);
		}

		if (wrong || fs_cnt == 0 || sd_cnt == 0) {
			cout << "-1\n";
		} else {
			For (i, n) {
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
	}
}

