#include <bits/stdc++.h>
using namespace std;


#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define For(i, n) for(int i = 0; i<(n); i++)


int main ()
{
    ios::sync_with_stdio(0);
    int n, k; cin>>n>>k;
    vector<int> d(n), la(k);
    For(i,n) cin>>d[i];
    For(i,k)cin>>la[i];
    sort(d.begin(), d.end());
    //sort(la.begin(), la.end());
    multiset<int> s;
    int res=0;
    for(auto x:la) s.insert(x);
    ForD(i,n) {
        int x=d[i];
        auto it = s.lower_bound(5*x);
        if(it!=s.end()){
            s.erase(it);
            res++;
        } else {
            it = s.lower_bound(3*x);
            if(it==s.end()){
                        cout<<"NIE\n"; return 0;
            }
            s.erase(it);
            it = s.lower_bound(2*x);
            if(it==s.end()){
                        cout<<"NIE\n"; return 0;
            }
            s.erase(it);
            res+=2;
        }
    }
    cout<<res<<"\n";
 
}