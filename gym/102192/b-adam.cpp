#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
typedef long double ld;
typedef std::pair<ld, ld> PLD;

ld dist(PLD a, PLD b){
  return std::sqrt((b.X-a.X)*(b.X-a.X) + (b.Y-a.Y)*(b.Y-a.Y));
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

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
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

typedef Point<ld> P;

bool circleInter(P a,P b,double r1,double r2,pair<P, P>* out) {
	if (a == b) { assert(r1 != r2); return false; }
	P vec = b - a;
	double d2 = vec.dist2(), sum = r1+r2, dif = r1-r2,
	       p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
	if (sum*sum < d2 || dif*dif > d2) return false;
	P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
	*out = {mid + per, mid - per};
	return true;
}

const ld EPS = 0.000000001;

bool check(ld h, ld w, std::vector<ld> pts){
  std::sort(pts.begin(), pts.end());
  bool good = false;
  do{
    ld a = pts[0];
    ld b = pts[1];
    ld c = pts[2];
    ld y = std::min(h, a);
    ld x;
    if(h > a) x = 0;
    else x = std::sqrt(a*a - h*h);
    if(x > w+EPS) continue;
    PR<P, P> out;
    circleInter(P(0, 0), P(x, y), c, b, &out);
    PLD x1 = MP(out.X.x, out.X.y);
    PLD x2 = MP(out.Y.x, out.Y.y);
    if(x1.X < 0 || x1.X > w+EPS || x1.Y < 0 || x1.Y > h+EPS){

    }else good = true;
    if(x2.X < 0 || x2.X > w+EPS || x2.Y < 0 || x2.Y > h+EPS){

    }else good = true;
    

  }while(std::next_permutation(pts.begin(), pts.end()));
  return good;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  std::cout << std::setprecision(9)  << std::fixed;
  while(t--){
    std::vector<PLD> pts(3);
    FOR(i, 3) std::cin >> pts[i].X >> pts[i].Y;
    ld w;
    std::cin >> w;
    std::vector<ld> dls;
    FOR(i, 3) dls.push_back(dist(pts[i], pts[(i+1)%3]));
    ld left = 0.0;
    ld right = 10000000.0;
    while(right - left > 0.00000001){
      ld mid = (left+right)*0.5;
      if(check(mid, w, dls)) right = mid;
      else left = mid;
    }
    if(left > 100000){
      std::cout << "impossible\n";
    }else std::cout << left << "\n";
  }
  
  return 0;
}