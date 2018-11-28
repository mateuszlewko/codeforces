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

unordered_map<int, int> get_factors(int x, const vector<int>& ps) {
	unordered_map<int, int> factors;
	int ind = 0;
	while (x && ind < ps.size()) {
		if (x % ps[ind] == 0) {
			factors[ps[ind]]++;
			x /= ps[ind];
		} else {
			ind++;
		}
	}

	if (x > 1) {
		factors[x]++;
	}

	return factors;
}

pair<int, bool> upper_log(int x) {
	// error(x);
	int cnt = 0;
	int one_cnt = 0;
	while (x) {
		if (x & 1) one_cnt++;
		
		cnt++;
		x >>= 1;
	}

	// error(one_cnt, cnt);

	if (one_cnt > 1) {
		return {cnt + 1, true};
	}

	return {cnt - 1, false};

	// error(cnt, one_cnt);
}

int main() {
    _upgrade;

	int n;
	cin >> n;

	if (n == 1) {
		cout << "1 0\n";
		return 0;
	}

	auto ps = primes(2 * 1000 * 1000);
	auto fs = get_factors(n, ps);

	int largest = 0;
	int result = 1;


	for (auto it : fs) {
		result *= it.first;
		largest = max(largest, it.second);
	}

	bool any_smaller = false;
	for (auto it : fs) {
		if (it.second < largest) {
			// error(it.first, it.second, largest);
			any_smaller = true;
			break;
		}
	}

	auto ops = upper_log(largest);
	if (!ops.second && any_smaller) ops.first++;

	cout << result << " " << ops.first << "\n";
}

