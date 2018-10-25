#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define rep(i,n) for(int i=0; i<(n); ++i)

const int maxn = 3005;
int in[maxn][maxn];
bool v[maxn][maxn], h[maxn][maxn];
int hplus[maxn][maxn], hminus[maxn][maxn];

int heigth(int i, int j) {
    if(j==0) return 0;
    int len = hplus[i][j-1];
    if(len==j+1) return len;
    if(!v[i][j] && !h[i][j]) return len+1;
    if(h[i][j-1-len]) return len+1;
    return len;
}

void solve() {
    int n, m; cin>>n>>m;
    rep(i,n) rep(j,m) cin>>in[i][j];
    rep(i,n) for(int j=1; j<m-1; ++j) h[i][j]=(in[i][j]-in[i][j-1]) == (in[i][j+1]-in[i][j]);
    for(int i=1; i<n-1; ++i) rep(j,m) v[i][j]=(in[i][j]-in[i-1][j]) == (in[i+1][j]-in[i][j]);
    rep(j,m) {
        int lenplus=0, lenminus=0;
        rep(i,n) {
            if(!v[i][j] || !h[i][j]) lenplus=0; else ++lenplus;
            if(!h[i][j]) lenminus=0; else lenminus++;
        }
        hplus[i][j]=lenplus;
        hminus[i][j]=lenminus;
    }
    rep(i,n){
        vector<int> v;
        rep(j,m) {
            if(!h[i][j]) {
                v.clear();
                v.push_back(j);
            } else {
                while(!v.empty() && heigth(i,v.back()) >= heigth(i,j)) v.pop_back();
                v.push_back(j);
            }

        }
    }
}


int main ()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}