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


vector<int> primes(int N) {
    bool prime[N+1]; 
    memset(prime, true, sizeof(prime)); 
	vector<int> res;
  
    for (int p=2; p*p<=N; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*2; i<=N; i += p) 
                prime[i] = false; 
        } 
    }

	for (int i = 2; i < N; i++) 
		if (prime[i]) res.push_back(i);

	return res;
}

int main() {
    _upgrade;
	ll n;
	cin >> n;

	auto ps = primes(1 * 1000 * 1000);
	for (int p : ps) {
		if (n % (ll)p == 0) {
			if (p % 2 == 1) {
				cout << (n - (ll)p) / 2LL + 1LL << "\n";
			}
			else {
				cout << n / (ll)p << "\n";
			}

			return 0;
		}
	}

	cout << "1\n";
}

