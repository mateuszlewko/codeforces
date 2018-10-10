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

vector<int> int2num(int x) {
	vector<int> num;
	
	while (x) {
		num.push_back((x % 11));
		x /= 11;
	}

	return num;
}

unordered_map<char, int> char2num;
char num2char[20];

vector<int> str2num(const string& s) {
	vector<int> num;
	
	ForD (i, s.size()) {
		num.push_back(char2num[s[i]]);
	}

	return num;
}

vector<int> add(vector<int> l, vector<int> r) {
	vector<int> res;
	int carry = 0;

	if (l.size() < r.size()) {
		vector<int> tt = l;
		l = r;
		r = tt;
	}

	// while (l.size() > r.size()) {
	// 	r.push_back(0);
	// }

	For (i, r.size()) {
		int s = l[i] + r[i] + carry;
		if (s > 11) {
			carry = 1;
		} else carry = 0;

		// error(i, l[i], r[i], carry, s);

		res.push_back((s - 1) % 11 + 1);
	}

	// for (int i = l.size() - 1; i > r.size(); i--) {
	// 	if (l[i] > 0 && l[i - 1] == 0) {
	// 		l[i] -= 1;
	// 		l[i - 1] += 11;

	// 		cout << "adding to: " << i - 1 << "\n";
	// 	}
	// }

	while (l.size() && l.back() == 0) l.pop_back();

	for (int i = r.size(); i < l.size(); i++) {
		int s = l[i] + carry;
		if (s > 11) {
			carry = 1;
		} else carry = 0;

		if (s <= 0) {
			// error(s, i);
			// for (int x : l) {
			// 	cout << x << " ";
			// }
			// cout << " <== l\n";

			s += 11;

			if (l.size() == i + 1) break;

			l[i + 1] -= 1;
		}

		// error(i, l[i], carry, s);
		res.push_back((s - 1) % 11 + 1);
	}

	if (carry) res.push_back(1);
	return res;
}

string solve(int k, string s) {
	auto adder = int2num(k);
	auto curr = str2num(s);

	// for (int x : adder) {
	// 	cout << x << " ";
	// }
	// cout << " <== adder\n";

	// for (int x : curr) {
	// 	cout << x << " ";
	// }
	// cout << " <== curr\n";
	
	auto sum = add(curr, adder);
	
	// for (int x : sum) {
	// 	cout << x << " ";
	// }
	// cout << " <== sum\n";

	string res;
	res.resize(sum.size(), 'a');
	
	For (i, sum.size()) {
		res[res.size() - i - 1] = num2char[sum[i]];
		// cout << "adding char: " << num2char[sum[i]] << "|\n";
	}

	return res;
}

void test() {
	int N = 100000;
	vector<string> curr;

	For (i, N) {
		curr.push_back(solve(i + 1, "A"));
	}

	vector<string> sorted;
	for (auto x : curr) sorted.push_back(x);
	sort(sorted.begin(), sorted.end(), [](auto l, auto r) {
		if (l.size() != r.size()) 
			return l.size() < r.size();
		return l < r;
	});

	For (i, N) {
		if (sorted[i] != curr[i]) {
			error(sorted[i], curr[i], i);
			break;
		}
	}
	
	For (i, 200) {
		cout << i << ". " << curr[i] << "\n";
	}

	const int M = 10000;
	For (i, M) {
		For (j, 30) {
			int mult = 1;
 			auto next = solve(j * mult, curr[i]);
			 if (next != curr[i + j * mult]) {
				 cout << "WRONG ADD\n";
				 error(curr[i], j, i+j*mult, curr[i+j*mult], i, j*mult, next);
				 return;
			 }
		}
	}

}

int main() {
    _upgrade;

	string temp = "AHIMOTUVWXY";
	For (i, temp.size()) {
		char2num[temp[i]] = i + 1;
		num2char[i + 1] = temp[i];
	}

	// test();

	int t;
	cin >> t;

	while (t--) {
		int k;
		string s;
		cin >> k >> s;

		cout << solve(k, s) << "\n";
	}
}

