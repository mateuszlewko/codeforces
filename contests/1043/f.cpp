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

const int N = 300 * 1000 + 100;

namespace uf {

int sets[N];
int cnt[N];

int find(int a)
{
    if (sets[a] == a)
        return a;
    return sets[a] = find(sets[a]);
}

bool connect(int a, int b)
{
    int fa = find(a);
    int fb = find(b);

    if (fa == fb)
        return false;

    if (cnt[fa] <= cnt[fb])
    {
        cnt[fb] += cnt[fa];
        sets[fa] = fb;
    }
    else
    {
        cnt[fa] += cnt[fb];
        sets[fb] = fa;
    }

    return true;
}
}

int A[N];

vector<int> primes;
bool not_prime[N];
void make_primes() {
	for (int i = 2; i < N; i++) {
		if (not_prime[i]) continue; 

		for (ll j = (ll)i * i; j < N; j += i) {
			not_prime[j] = true;
		}
	}

	for (int i = 2; i * i < N; i++) {
		if (!not_prime[i]) primes.push_back(i);
	}
}

int main() {
    _upgrade;
	make_primes();
	// error(primes.size());
	// for (int p : primes) {
	// 	error(p);
	// }
	
	For (i, N) { 
		uf::sets[i] = i;
		uf::cnt[i] = 1;
	}
	
	int n;
	cin >> n;
	bool is_one = false;
	int all_gcd = -1;
	For (i, n) {
		cin >> A[i];
		if (all_gcd == -1) all_gcd = A[i];
		else all_gcd = __gcd(all_gcd, A[i]);

		if (A[i] == 1) is_one = true;
	}

	if (is_one == true) {
		cout << 1 << "\n";
		return 0;
	} else if (all_gcd != 1) {
		cout << -1 << "\n";
		return 0;
	} 

	unordered_set<int> sure_prime;
	int sp = 0;

	For (i, n) {
		int x = A[i];
		bool div_any = false;
		for (int p : primes) {
			if (x % p == 0) {
				error(x, p);
				uf::connect(x, p);
				div_any = true;
			} else if (p > x) {
				break;
			}
		}

		if (!div_any) { 
			sure_prime.insert(x);
			sp++;
		}
	}

	if (sure_prime.size() >= 2 || (sure_prime.size() == 1 && n - sp > 0)) {
		cout << 2 << "\n";
		return 0;
	}

	bool other = false;
	int curr = uf::find(A[0]);
	error(curr);
	For (i, n - 1) {
		error(A[i+1], uf::find(A[i+1]));

		if (uf::find(A[i + 1]) != curr) {
			other = true;
			break;
		}
	}

	if (other) {
		cout << "2\n";
	} else cout << "3\n";
}

