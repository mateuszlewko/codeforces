//Dominik Kowalczyk

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld; // 'long double' is 2.2 times slower than double
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

/////// TRIPLE ////////
#define TT1T2T3 template<class T1, class T2, class T3>
#define TRT1T2T3  triple<T1, T2, T3>
TT1T2T3 struct triple { T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c) {} };
TT1T2T3 bool operator<(const TRT1T2T3&t1, const TRT1T2T3&t2) { if (t1.a != t2.a)return t1.a < t2.a; else if (t1.b != t2.b)return t1.b < t2.b; else return t1.c < t2.c; }
TT1T2T3 bool operator>(const TRT1T2T3&t1, const TRT1T2T3&t2) { if (t1.a != t2.a)return t1.a > t2.a; else if (t1.b != t2.b)return t1.b > t2.b; else return t1.c > t2.c; }
TT1T2T3 bool operator==(const TRT1T2T3&t1, const TRT1T2T3&t2) { return (t1.a == t2.a && t1.b == t2.b && t1.c == t2.c); }
TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t) { return os >> t.a >> t.b >> t.c; }
TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t) { return os << t.a << " " << t.b << " " << t.c; }
#undef TRT1T2T3
#undef TT1T2T3
typedef triple<int, int, int> tri;
typedef  triple<ll, ll, ll> trll;
/////// TRIPLE ////////

/////// PAIR MAGIC ////////
#define PT1T2 pair<T1,T2>
#define TT1T2 template<class T1, class T2>
TT1T2 inline PT1T2 operator+(const PT1T2 &p1, const PT1T2 &p2) { return PT1T2(p1.first + p2.first, p1.second + p2.second); }
TT1T2 inline PT1T2& operator+=(PT1T2 &p1, const PT1T2 &p2) { p1.first += p2.first, p1.second += p2.second; return p1; }
TT1T2 inline PT1T2 operator-(const PT1T2 &p1, const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }
TT1T2 inline PT1T2& operator-=(PT1T2 &p1, const PT1T2 &p2) { p1.first -= p2.first, p1.second -= p2.second; return p1; }
TT1T2 inline istream& operator >> (istream& os, pair<T1, T2>& p) { return os >> p.first >> p.second; }
TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p) { return os << p.first << " " << p.second; }
#undef PT1T2
#undef TT1T2
/////// PAIR MAGIC ////////

/////// VECTOR MAGIC ////////
template< class T>istream& operator>>(istream& os, vector<T> & container) { for (auto& u : container)os >> u; return os; }
template< class T>ostream& operator<<(ostream& os, const vector<T> & container) { for (auto& u : container)os << u << " "; return os; }
/////// VECTOR MAGIC ////////

/////// RANDOM ////////
thread_local std::mt19937 gen{ std::random_device{}() };
template<typename T>T random(T min, T max) { using dist = std::conditional_t<std::is_integral<T>::value, std::uniform_int_distribution<T>, std::uniform_real_distribution<T>>; return dist{ min, max }(gen); }
template<typename T>T randomINT(T min, T max) { return std::uniform_int_distribution<T>{min, max}(gen); }
/////// RANDOM ////////

/////// PRIME TESTS ////////
const int USUAL_MOD = 1e9 + 7;
template<class T> inline void normmod(T &x, T m = USUAL_MOD) { x %= m; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m) { x %= m; n %= m; ll r = x * n - ll(ld(x)*ld(n) / ld(m)) * m; while (r < 0) r += m; while (r >= m) r -= m; return r; }
inline ll powmod(ll x, ll n, ll m) { ll r = 1; normmod(x, m); while (n) { if (n & 1) r *= x; x *= x; r %= m; x %= m; n /= 2; }return r; }
inline ll powmulmod(ll x, ll n, ll m) { ll res = 1; normmod(x, m); while (n) { if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n /= 2; } return res; }
template<class T> bool isPrime(T x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3; for (T i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; }
bool millerRabin(ll n) { if (n <= 1000) return isPrime(n); ll s = n - 1; int t = 0; while (s % 2 == 0) s /= 2, ++t; for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) { if (!(a %= n)) return true; ll f = powmulmod(a, s, n); if (f == 1 || f == n - 1) continue; for (int i = 1; i < t; ++i) if ((f = mulmod(f, f, n)) == n - 1) goto nextp; return false; nextp:; } return true; }
/////// PRIME TESTS ////////

/////// BITS MAGIC ////////
template<class T> inline int sign(T x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }
inline bool isPowerOfTwo(int x) { return (x != 0 && (x&(x - 1)) == 0); }
inline int countBits(uint v) { v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int countBits(ull v) { uint t = v >> 32; uint p = (v & ((1ULL << 32) - 1)); return countBits(t) + countBits(p); }
inline int countBits(ll v) { return countBits((ull)v); }
inline int countBits(int v) { return countBits((uint)v); }
uint reverseBits(uint x) { x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
/////// BITS MAGIC ////////

template<typename T> inline void setmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void setmax(T &x, T y) { if (y > x) x = y; }

#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(), (c).end()
#define ELO exit(0)
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

#define FOR(i,a,b) for(int i = (a); i <= b; i++)
#define FORR(i,a,b) for(int i = (a); i >= b; i--)
#define INT(i) int i;cin >> i;
#define LL(i) ll i;cin >> i;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

//////////////////////////////////
///////		  CODE         ///////
//////////////////////////////////

int main()
{
	boost;

	int n;
	string s;
	cin >> n >> s;

	int res = 0;

	vpii prz;

	{
		int i = 0;
		while (i < n)
		{
			if (s[i] == 'G')
			{
				int j = i;
				while (i + 1 < n and s[i + 1] == 'G')
				{
					i++;
				}
				prz.pb({ j,i });
				setmax(res, i - j + 1);
			}
			i++;
		}
	}

	for (int i = 0; i < sz(prz) - 1; i++)
	{
		if (prz[i].second + 2 == prz[i + 1].first)
		{
			int dl = prz[i].second - prz[i].first + 1;
			dl += prz[i + 1].second - prz[i + 1].first + 1;

			if (sz(prz) > 2)dl++;

			setmax(res, dl);
		}
	}

	cout << res;
	ELO;
}