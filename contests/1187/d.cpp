#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

template<typename T, typename U>
pair<T, U>& operator+=(pair<T, U> &lhs, const pair<T, U> &rhs){
	lhs.first += rhs.first;
	lhs.second += rhs.second;
	return lhs;
}

template<typename T, typename U>
pair<T, U>& operator-=(pair<T, U> &lhs, const pair<T, U> &rhs){
	lhs.first -= rhs.first;
	lhs.second -= rhs.second;
	return lhs;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &container) {
	for (auto &u : container) os << u << " ";
	return os;
}

template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds; 
using namespace std; 

template<typename T>
using pb_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

template<typename T, typename U>
pair<T, U> operator-(const pair<T, U> &l, const pair<T, U> &r) {
	return {l.first - r.first, l.second - r.second};
}
template<typename T, typename U>
pair<T, U> operator+(const pair<T, U> &l, const pair<T, U> &r) {
	return {l.first + r.first, l.second + r.second};
}

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 3 * 100 * 1000 + 10;
int A[N];
int B[N];

vector<int> posA[N];
vector<int> posB[N];

int main() {
	_upgrade;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		For (i, n) {
			cin >> A[i];
			posA[A[i]].push_back(i);
		}

		For (i, n) {
			cin >> B[i];
			posB[B[i]].push_back(i);
		}

		int beg = 0;

		for (int i = 1; i < n; i++) {
			if (B[i] < B[i - 1]) {
				sort(A + beg, A + i);
				beg = i;
			}
		}

		sort(A + beg, A + n);

		bool wrong = false;
		For (i, n) {
			if (A[i] != B[i]) {
				wrong = true;
				break;
			}
		}

		if (wrong) {
			cout << "NO\n";
		} else cout << "YES\n";
		
		// For (i, n) {
		// 	if (A[i] == B[i]) {
		// 		if (next_sort_pos != -1) {
		// 			sort(A + prev_sort_pos, A + next_sort_pos + 1);
		// 			next_sort_pos = prev_sort_pos = -1;
		// 		}
		// 		continue;
		// 	}

		// 	// if (i < next_sort_pos) {
		// 	// 	cout << "NO\n";
		// 	// 	wrong = true;
		// 	// 	break;
		// 	// }

		// 	int pos_in_a_ix = lower_bound(begin(posA[B[i]]), end(posA[B[i]]), i) - posA[B[i]].begin();
		// 	if (pos_in_a_ix >= (int)posA[B[i]].size()) {
		// 		cout << "NO\n";
		// 		wrong = true;
		// 		break;
		// 	}

		// 	int pos_in_a = posA[B[i]][pos_in_a_ix];

		// 	int pos_in_b_ix = lower_bound(begin(posB[A[i]]), end(posB[A[i]]), i) - posB[A[i]].begin();
		// 	if (pos_in_b_ix >= (int)posB[A[i]].size()) {
		// 		cout << "NO\n";
		// 		wrong = true;
		// 		break;
		// 	}

		// 	int pos_in_b = posB[A[i]][pos_in_b_ix];

		// 	int sort_pos = max(pos_in_a, pos_in_b);
		// 	if (prev_sort_pos == -1) {
		// 		prev_sort_pos = i;
		// 	}
		// 	// sort(A + i, A + sort_pos + 1);
		// 	next_sort_pos = max(next_sort_pos, sort_pos);
		// }

		// if (next_sort_pos != -1) {
		// 	sort(A + prev_sort_pos, A + next_sort_pos + 1);
		// 	next_sort_pos = prev_sort_pos = -1;
		// }

		// For (i, n) {
		// 	if (A[i] != B[i]) {
		// 		if (!wrong) cout << "NO\n";
		// 		wrong = true;
		// 		break;
		// 	}
		// }

		// if (!wrong) cout << "YES\n";
	}
}

