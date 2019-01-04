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

const int N = 2 * 100 * 1000 + 100; 
map<pair<int, ll>, int> jumps;
map<pair<int, int>, ll> can_jump;
vector<pair<int, int>> jump_by[N]; 

void init_jumps() {
	for (ll i = 1; i < 5 * 1000 * 1000; i++) {
		for (ll j = 1; j < N; j++) {
			ll diff = j * j + 2 * i * j;
			if (diff >= N) break;
			jumps[{i, diff}] = (int)j;
			jump_by[diff].push_back({i, j});
			can_jump[{i, j}] = diff;
		}
	}
}

int A[N];

bool find_solution(int start, int n) {
	vector<ll> res_base;
	res_base.push_back((ll)start * start);

	For (i, n / 2) {
		error(start, A[i]);

		auto it = jumps.find({start, A[i]});
		if (it == jumps.end()) return false;

		error(it->second);

		res_base.push_back(A[i]);
		start += it->second;
		
		if (i < n / 2 - 1) {
			bool found = false;
			for (auto conn : jump_by[A[i + 1]]) {
				int y = conn.first;
				error(start, y, conn.second);
				auto next_it = can_jump.find({start, y - start});

				if (next_it != can_jump.end()) {
					res_base.push_back(next_it->second);
					error(next_it->second);
					start = y;
					found = true;
					break;
				}
			}

			if (!found) return false;
		}
	}

	cout << "Yes\n";
	for (auto e : res_base) {
		cout << e << " ";
	}

	return true;
}

int main() {
    _upgrade;

	init_jumps();
	
	int n;
	cin >> n;
	For (i, n / 2) {
		cin >> A[i];
	}

	for (auto p : jump_by[A[0]]) {
		if (find_solution(p.first, n)) {
			return 0;
		}
	}

	cout << "No\n";
	return 0;
}

