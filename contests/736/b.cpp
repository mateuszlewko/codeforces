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

vector<int> primes;

const int P = 40 * 1000 * 1000;
bool not_prime[P];

void make_primes() {
	for (int i = 2; i * i < P; i++) {
		// cout << i << "\n";
		if (not_prime[i]) continue;
		for (int j = i * i; j < P; j += i) {
			not_prime[j] = true;
		}
	}

	for (int i = 2; i < P; i++) {
		if (!not_prime[i]) primes.push_back(i);
	}
}

unordered_map<int, int> store;

int largest_div(int x) {
	if (x > 70) {
		auto it = store.find(x);
		if (it != store.end()) {
			return it->second;
		}
	}

	for (int p : primes) {
		if (p >= x) {
			store[x] = 1;
			return 1;
		}

		if (x % p == 0) {
			int ret = max(p, x / p);
			store[x] = ret;
			return ret;
		}
	}

	store[x] = 1;
	return 1;
}

int MAX_ITER = 200 * 1000 * 1000;

int get_best(int n) {
	clock_t begin = clock();
	int best = largest_div(n);

	for (int i = 2; i <= min(MAX_ITER, n / 2); i++) {
		best = min(best, largest_div(n - i) + largest_div(i));
		if (best <= 2) {
			break;
		}

		double time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
		if (time_spent > 0.9) { 
			break; 
		}
	}

	return best;
}

int main() {
    _upgrade;


	int n; 
	cin >> n;

	make_primes();

	cout << "\n";

	int best = get_best(n);
	if (n > 5) {
		best = min(best, get_best(n - 3) + 1);
	}

	if (best > 3) {
		exit(11);
	}
	cout << best << "\n";
}

