#include<bits/stdc++.h>

using namespace std;

vector<long long> offs;

void solve(int lol){
  long long n, m ,k;
  cin>>n>>m>>k;
  long long dead=0;
  long long offset=0;
  long long mx;
  long long my;
  offs.clear();
  offs.reserve(1e8);

  while(dead<m){
    offs.push_back(offset);//cerr<<"offset "<<offset<<endl;
    long long newde=(n-dead)/k;
    if((n-dead)%k + offset >= k){
      ++newde;
    }
    long long noff=(n-dead)%k + offset;//cerr<<"noff "<<noff<<endl;
    dead+=newde;
    if(dead >= m){
      mx = (-offset+k-1)%k;
      my = newde + (m - dead) - 1;
      break;
    }
    offset=noff;
    offset%=k;
    if(newde == 0)offs.pop_back();
  }

  for(int i = (int)offs.size() -2; i>= 0; --i){
    long long deadcol= k-1 - offs[i];
    //cerr<<"dead "<<deadcol<<" ";
      //cerr<<mx<<" "<<my<<"\n";
    long long newx, newy;
    mx+=k*my;
    newx = my*k/(k - 1) + 4 + mx;
    deadcol%=k;
    while(1){
      --newx;
      long long qwe = newx;//cerr<<newx<<endl;
      if(qwe%k == deadcol)continue;
      if(qwe%k > deadcol){
        qwe-=qwe/k + 1;
      }
      else if(qwe%k < deadcol){
        qwe-=qwe/k;
      }
      if(qwe == mx)break;
    }
    mx=newx;
    my=mx/k;
    mx%=k;

  }//cerr<<mx<<" "<<my<<"\n";

  cout<<"Case #"<<lol<<": "<<mx + k*my + 1<<"\n";

  



}


int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int t;cin>>t;
  int x=1;
  while(x<=t){solve(x);++x;}



  return 0;
}