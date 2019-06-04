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
char S[105],P[105];
int n;
int funkcja()
{
		int maks=0;
		int ile=0;
		for(int i=1;i<=n;i++)
		{
				if(P[i]=='N')
					ile++;
				else
				{
					maks=max(maks,ile);
					ile=0;
				}
				

		}
		maks=max(maks,ile);
		return maks;
		
}
int main() {
	int k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf(" %c",&S[i]);
	for(int i=1;i<=n-k+1;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(S[j]!='?')
				P[j]=S[j];
			else
			{
					P[j]='Y';
			}
			
		}
		for(int j=i;j<i+k;j++)
		{
						if(S[j]!='?')
				P[j]=S[j];
			else
			{
					P[j]='N';
			}
		}
		for(int j=i+k;j<=n;j++)
		{
			if(S[j]!='?')
				P[j]=S[j];
			else
			{
					P[j]='Y';
			}
		}
		int x=funkcja();
		if(x==k)
		{
			printf("YES");
			return 0;
		}
			
	}
	printf("NO");
	return 0;
}

