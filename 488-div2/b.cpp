#include <bits/stdc++.h> 

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)

#define SORT(x) sort(begin(x), end(x))

using namespace std;

const int N = 100 * 1000 + 10;

typedef long long ll;

int pows[N];
int coins[N];

ll ans[N];

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    int n, k;
    scanf("%d %d", &n, &k);

    vector<pair<pair<int, int>, int>> vs; 

    For (i, n) scanf("%d", &pows[i]);
    For (i, n) scanf("%d", &coins[i]);

    For (i, n)
        vs.push_back({{pows[i], coins[i]}, i});

    SORT(vs);
    priority_queue<int> PQ;
    
    ll sum = 0;

    For (i, n) {
        ll curr = (ll)vs[i].first.second;
        ans[vs[i].second] = curr + sum;
        
        PQ.push(-curr);
        sum += curr;

        while ((int)PQ.size() > k) {
            sum -= -PQ.top();
            PQ.pop();
        }
    }

    For (i, n)
        printf("%lld ", ans[i]);
}

