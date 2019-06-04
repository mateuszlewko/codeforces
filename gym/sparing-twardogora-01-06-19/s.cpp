#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100005;

int A[maxn];
int B[maxn];

int main()
{
  int n, l, r;
  cin >> n >> l >> r;

  for(int i = 0; i < n; i++)
    cin >> A[i];
  for(int i = 0; i < n; i++)
    cin >> B[i];

  
  int dl = r - l + 1;
  l--;
  r--;

  sort(B + l, B + r + 1);
  sort(A + l, A + r + 1);

  for(int i = 0; i < n; i++)
  {
    if(A[i] != B[i])
    {
      cout << "LIE\n";
      return 0;
    }
  }

  cout << "TRUTH\n";

  return 0;
}