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

const int N = 210;
int nums[N];

int swaps(int curr, int from, int to) 
{
	if (from == to) return curr;
	swap(nums[from - 1], nums[from]);
	return swaps(curr + 1, from - 1, to);
}

int main() {
    // _upgrade;
	int n; 
	scanf("%d", &n);

	For (i, 2 * n) {
		scanf("%d", &nums[i]);
	}

	int res = 0;
	For (i, n) {
		if (nums[2 * i] != nums[2 * i + 1]) {
			int pos = find(nums + 2 * i + 1, nums + 2 * n, nums[2*i]) - nums;
			res += swaps(0, pos, 2 * i + 1);
		}
	}

	printf("%d\n", res);
}

