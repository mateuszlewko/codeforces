#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string dajznak(int ile)
{
  string s;
  for(int i = 0; i < ile; i++)
    s.pb('+');
  s.pb('.');
  return s;
}

int main()
{
  string s;
  cin >> s;

  vector<pair<int, int> > V;
  string temp;
  int znak = 1;
  for(int i = 0; i < s.size(); i++)
  {
    if(s[i] == '+' || s[i] == '-')
    {
      V.pb({znak, stoi(temp)});
      
      if(s[i] == '+')
        znak = 1;
      else
        znak = -1;
      temp.clear();
    }
    else
    {
      temp.pb(s[i]);
    }
  }

  V.pb({znak, stoi(temp)});

  int ile = 0;
  for(int i = 0; i < V.size(); i++)
    ile += V[i].fi * V[i].se;

  vector<string> v;
  if(ile == 0)
    v.pb(dajznak('0'));
  while(ile > 0)
  {
    v.pb(dajznak((ile % 10) + '0'));
    ile /= 10;
  }

  for(int i = v.size() - 1; i >= 0; i--)
    cout << v[i] << endl;

  return 0;
}