#include<bits/stdc++.h>

using namespace std;

char tab[3][3];

void rot(int x, int y, int qwe){
  if(qwe==-1){
    swap(tab[x][y], tab[x+1][y]);
    swap(tab[x+1][y], tab[x+1][y+1]);
    swap(tab[x+1][y+1], tab[x][y+1]);
  }
  if(qwe==1){
    swap(tab[x][y], tab[x][y+1]);
    swap(tab[x][y+1], tab[x+1][y+1]);
    swap(tab[x+1][y+1], tab[x+1][y]);
  }
}

void solve(){
  int n;cin>>n;
  for(int i=0;i<3;++i){
    for(int j=0;j<3;++j){
      cin>>tab[j][i];
    }
  }
  for(int i=0;i<n;++i){
    char kw;cin>>kw;
    char rotate;cin>>rotate;
    if(kw=='1'){
      if(rotate=='C')rot(0,0, 1);
      else rot(0,0, -1);
    }
    if(kw=='2'){
      if(rotate=='C')rot(1,0, 1);
      else rot(1,0, -1);
    }
    if(kw=='3'){
      if(rotate=='C')rot(0,1, 1);
      else rot(0,1, -1);
    }
    if(kw=='4'){
      if(rotate=='C')rot(1,1, 1);
      else rot(1,1, -1);
    }
  }

  for(int i=0;i<3;++i){
    for(int j=0;j<3;++j){
      cout<<tab[j][i];
    }
    cout<<"\n";
  }

}

int main(){
  ios_base::sync_with_stdio(0);
  int t;cin>>t;
  while(t--)solve();

}