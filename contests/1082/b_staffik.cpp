
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double ld;

#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define rep(i,n) for(int i=0; i<(n); ++i)
#define per(i,n) for(int i=(n-1); i>=0; --i)
#define forn(i,n) for(int i=1; i<=(n); ++i)
#define ford(i,n) for(int i=(n); i>=1; --i)

const int maxn = 1000;

void solve()
{
	int n; cin>>n;
	vi v(n); rep(i,n) {char x;cin>>x; if(x=='G') v[i]=1; else v[i]=0;}
	vector<pii> w;
	int cur=v[0], len=1;
	for(int i=1; i<n; ++i) {
		if(v[i]==cur) ++len;
		else {w.pb(mp(cur,len)); cur^=1; len=1;}
	}
	w.pb(mp(cur,len));
	int best=0;
	rep(i,w.size()) if(w[i].st==1) best=max(best,w[i].nd);
	int cnt=0;
	rep(i,w.size()) if(w[i].st==1) ++cnt;
	for(int i=2; i<w.size(); ++i) {
		if(w[i].st==1 && w[i-1].nd==1) {
			if(cnt>2) best=max(best,w[i-2].nd+1+w[i].nd);
			else best=max(best,w[i-2].nd+w[i].nd);

		}
	}
	cout<<best<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}