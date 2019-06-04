#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;

#define M_PI       3.14159265358979323846

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	dd dist() const { return sqrt((dd)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	dd angle() const { 
    if (y >= 0.0) return atan2(y, x) + M_PI;
    return atan2(y, x) ; 
  }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(dd a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    void show(){
        cout << "x: " << x << " y: " << y << endl;
    }
};

typedef Point<dd> P;
bool circleInter(P a,P b,dd r1,dd r2,pair<P, P>* out) {
	if (a == b) { assert(r1 != r2); return false; }
	P vec = b - a;
	dd d2 = vec.dist2(), sum = r1+r2, dif = r1-r2,
	       p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
	if (sum*sum < d2 || dif*dif > d2) return false;
	P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
	*out = {mid + per, mid - per};
	return true;
}

bool foo(P A, P B){

    return A.angle() < B.angle();
}

dd dist(P A, P B){

  //  cout << sqrt(
  //    (A.x - B.x) * (A.x - B.x) +
 //     (A.y - B.y) * (A.y - B.y)
 //   ) << " dist res\n";
    return sqrt(
      (A.x - B.x) * (A.x - B.x) +
      (A.y - B.y) * (A.y - B.y)
    );
}

void solve(){

    int n;
    dd x, y, r, R, ans;
    vector <P> X;
    cin >> n >> R;
    set <pair <P, P> > S;
    for (int i = 0; i < n; i ++){
      cin >> x >> y >> r;
      pair <P, P> res;
      circleInter(P(x, y), P(0, 0), r, R, &res);

      S.insert({min(res.first, res.second), max(res.first, res.second)});

      X.push_back(res.first);
      X.push_back(res.second);
    }
  sort(X.begin(), X.end(), foo);
  
  vector <pair <P, P> > H;

  for (int i = 0; i < X.size(); i ++){
      P poc = X[i];
      P kon = X[(i + 1) % X.size()];
  //    poc.show();
  //    kon.show();
      if (!S.count({min(poc, kon), max(poc, kon)}))
        H.push_back({poc, kon});
  }
  
 // for (auto e : H){
 //   cout << "luk\n";
 //   e.first.show(); e.second.show();  
 // }
  ans = 0.0;
  for (int i = 0; i < H.size(); i ++)
    for (int j = i + 1; j < H.size(); j ++){
      
      ans = max(ans, dist(H[i].first,  H[j].first));
      ans = max(ans, dist(H[i].first,  H[j].second));
      ans = max(ans, dist(H[i].second, H[j].second));
      ans = max(ans, dist(H[i].second, H[j].first));
      ans = max(ans, dist(H[i].first,  H[i].second));
      ans = max(ans, dist(H[j].first,  H[j].second));
      vector <P> P1 = {H[i].first, H[i].second}, P2 = {H[j].first, H[j].second};
  //    cout << ans << "!\n";
   //   continue; 
      dd min_diff = 1000000.0;
      dd max_diff = -10000000.0;
      for (int o = 0; o < 2; o ++)
        for (int u = 0; u < 2; u ++){
          // P1[o].show();
          // cout << P1[o].angle() << " anlgle\n";
          // P2[u].show();
          // cout << P2[u].angle() << " anlgle\n";
          dd diff = P1[o].angle() - P2[u].angle();
          min_diff = min(min_diff, diff);
          max_diff = max(max_diff, diff);
        }
      // cout << min_diff << " " << max_diff << endl;
      if (min_diff <= M_PI and M_PI <= max_diff)
        ans = 2 * R;
    }
  cout << ans << "\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cout << setprecision(15) << fixed;

  int t;
  cin >> t;
  for (int o = 1; o <= t; o ++){
      cout << "Case #" << o << ": ";
      solve();
  }
  return 0;
}