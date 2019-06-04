#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


bool licz(bool a, bool b, bool c, bool d)
{
  bool x = a xor b;
  bool y = c or d;
  bool z = b and c;
  bool t = a xor d;

  bool f = x and y;
  bool g = z or t;

  return f xor g;
}

int main()
{
  int a, b, c, d;

  cin >> a >> b >> c >> d;

  cout << licz(a, b, c, d) << "\n";;
  return 0;
}