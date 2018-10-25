#include <bits/stdc++.h>
using namespace std;

#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define For(i, n) for(int i = 0; i<(n); i++)

typedef long long ll;

const int N = 100 * 1000 + 10;
int H[N];
int M[N];

int main ()
{
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    ForD (i, s.size() - 1) {
        if (s[i] == 'H') {
            H[s.size() - i - 2]++;
        } else M[s.size() - i - 2]++;
    }

    int sum_h = 0;
    int sum_m = 0;
    ForD (i, s.size()) {
        sum_h += H[i];
        H[i] = sum_h;
        sum_m += M[i];
        M[i] = sum_m;
    }

    For (i, s.size()) {
        // cout << H[i] << " " << M[i] << "\n";

        if (H[i] != M[i]) {
            cout << (H[i] > M[i] ? "H\n" : "M\n");
            return 0;
        }
    }

    cout << "HM\n";
}