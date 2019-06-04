#include<bits/stdc++.h>

using namespace std;

double w;


double spr(double x1, double y1, double x2, double y2, double x3, double y3){
  double ret =1000000;
  x2-=x1;y2-=y1;
  x3-=x1;y3-=y1;
  x1=0;y1=0;
  double wx=x2;
  double wy=y2;
  double wscal=sqrt(wx*wx + wy*wy);
  wx/=wscal;
  wy/=wscal;
  double qx;//cerr
  double qy;
  double qscal;
  if(wy == 0){
    qx=0;
    qy=1;
  }
  else{
    qx=1;
    qy=wx/wy;
    qscal=sqrt(qx*qx + qy*qy);
    qx/=qscal;
    qy/=qscal;
  }

  double xxx2, yyy2, xxx3, yyy3;
  yyy2=0;
  xxx2=wscal;
  xxx3=wx*x3 + wy*y3;
  yyy3=qx*x3 + qy*y3;
  if(yyy3<0)yyy3=-yyy3;
  //cout<<xxx2<<" "<<yyy2<<"  "<<xxx3<<" "<<yyy3<<endl;

  if(xxx3<=w && xxx2 <=w && xxx3 >=0 && xxx2 >= 0){
    ret = min(ret, max(yyy2, yyy3));//cout<<ret<<endl;
  }
  if(xxx3 >=0){
    double roty2 = xxx2*xxx2 -w*w;
    if(roty2 >=0){
      roty2=sqrt(roty2);
      double cosa = w/xxx2;
      double sina = roty2/xxx2;
      double roty3 = sina*xxx3 + cosa*yyy3;
      double rotx3 = cosa*xxx3 - sina*yyy3;
      if(rotx3 <= w && rotx3>=0){
        ret = min(ret, max(max(roty2, roty3), 0.0) - min(min(roty3, 0.0), roty2));//cout<<ret<<endl;cerr<<1<<endl;
      }
    }
    double roty3 = xxx3*xxx3 + yyy3*yyy3 - w*w;
    if(roty3 >=0){
      roty3=sqrt(roty3);
      double cosa = sqrt(roty3*yyy3 + xxx3*w)/sqrt(xxx3*xxx3 + yyy3*yyy3);
      double sina = sqrt((xxx3*xxx3 + yyy3*yyy3)-(roty3*yyy3 + xxx3*w))/sqrt(xxx3*xxx3 + yyy3*yyy3);
      roty2 = sina*xxx2 + cosa*yyy2;
      double rotx2 = cosa*xxx2 - sina*yyy2;
      if(rotx2 <= w && rotx2 >=0){//cout<<rotx2<<" "<<roty2<<endl;
        ret = min(ret, max(max(roty2, roty3), 0.0) - min(min(roty3, 0.0), roty2));//cout<<ret<<endl;cerr<<2<<endl;
      }
    }

    yyy3=-yyy3;

    roty2 = xxx2*xxx2 -w*w;
    if(roty2 >=0){
      roty2=sqrt(roty2);
      double cosa = w/xxx2;
      double sina = roty2/xxx2;
      roty3 = sina*xxx3 + cosa*yyy3;
      double rotx3 = cosa*xxx3 - sina*yyy3;
      if(rotx3 <= w && rotx3>=0){
        ret = min(ret, max(max(roty2, roty3), 0.0) - min(min(roty3, 0.0), roty2));//cout<<ret<<endl;cerr<<3<<endl;
      }
    }
    roty3 = xxx3*xxx3 + yyy3*yyy3 - w*w;
    if(roty3 >=0){
      roty3=-sqrt(roty3);
      double cosa = sqrt(roty3*yyy3 + xxx3*w)/sqrt(xxx3*xxx3 + yyy3*yyy3);
      double sina = sqrt((xxx3*xxx3 + yyy3*yyy3)-(roty3*yyy3 + xxx3*w))/sqrt(xxx3*xxx3 + yyy3*yyy3);
      roty2 = sina*xxx2 + cosa*yyy2;
      double rotx2 = cosa*xxx2 - sina*yyy2;
      if(rotx2 <= w && rotx2 >=0){
        ret = min(ret, max(max(roty2, roty3), 0.0) - min(min(roty3, 0.0), roty2));//cout<<ret<<endl;cerr<<4<<endl;
      }
    }

  }
  else{
      double roty2 = xxx2*xxx2 -w*w;
    if(roty2 >=0){
      roty2=-sqrt(roty2);
      double cosa = w/xxx2;
      double sina = roty2/xxx2;
      double roty3 = sina*xxx3 + cosa*yyy3;
      double rotx3 = cosa*xxx3 - sina*yyy3;
      if(rotx3 <= w && rotx3>=0){
        ret = min(ret, max(max(roty2, roty3), 0.0) - min(min(roty3, 0.0), roty2));//cout<<ret<<endl;cerr<<5<<endl;
      }
    }
    double rot3y = sqrt(xxx3*xxx3 + yyy3*yyy3);
    double rot3x = 0;
    double cosa = -yyy3/rot3y;
    double sina = -xxx3/rot3y;
    roty2 = sina*xxx2 + cosa*yyy2;
    double rotx2 = cosa*xxx2 - sina*yyy2;
    if(rotx2 <= w && rotx2>=0){
        ret = min(ret, max(max(roty2, rot3y), 0.0) - min(min(rot3y, 0.0), roty2));//cout<<ret<<endl;cerr<<6<<endl;
      }

  }


//cout<<ret<<endl<<endl;
  return ret;
}



void solve(){
  double x1, y1, x2, y2, x3, y3;
  cin>>x1>>y1>>x2>>y2>>x3>>y3>>w;
  double wyn = 1000000;
  wyn=min(wyn, spr(x1, y1, x2, y2, x3, y3));
  wyn=min(wyn, spr(x1, y1, x3, y3, x2, y2));
  wyn=min(wyn, spr(x2, y2, x1, y1, x3, y3));
  wyn=min(wyn, spr(x2, y2, x3, y3, x1, y1));
  wyn=min(wyn, spr(x3, y3, x1, y1, x2, y2));
  wyn=min(wyn, spr(x3, y3, x2, y2, x1, y1));
  if(wyn ==1000000)cout<<"impossible\n";
  else cout<<wyn<<"\n";
}


int main(){
  ios_base::sync_with_stdio(0);
  int t;cin>>t;
  cout<<fixed<<setprecision(12);
  while(t--)solve();
}