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

#define PI 3.14159265359
const ld INF = 2000000000000000000.0;

/*
   Return the angle between two vectors on a plane
   The angle is from vector 1 to vector 2, positive anticlockwise
   The result is between -pi -> pi
*/
ld Angle2D(ld x1, ld y1, ld x2, ld y2)
{
   ld dtheta,theta1,theta2;

   theta1 = atan2(y1,x1);
   theta2 = atan2(y2,x2);
   dtheta = theta2 - theta1;
   while (dtheta > PI)
      dtheta -= TWOPI;
   while (dtheta < -PI)
      dtheta += TWOPI;

   return(dtheta);
}

bool InsidePolygon(std::vector<PLD> polygon,PLD p)
{
   ld angle=0;
   PLD p1,p2;
   int n = SZ(polygon);

   for (int i=0;i<n;i++) {
      p1.X = polygon[i].X - p.X;
      p1.Y = polygon[i].Y - p.Y;
      p2.X = polygon[(i+1)%n].X - p.X;
      p2.Y = polygon[(i+1)%n].Y - p.Y;
      angle += Angle2D(p1.X,p1.Y,p2.X,p2.Y);
   }

   if (std::abs(angle) < PI)
      return false;
   else
      return true;
}



PLD operator -(const PLD &a, const PLD &b){
	return MP(a.X-b.X, a.Y-b.Y);
}
PLD operator +(const PLD &a, const PLD &b){
	return MP(a.X+b.X, a.Y+b.Y);
}
PLD operator *(const ld &a, const PLD &b){
	return MP(a*b.X, a*b.Y);
}

ld closest(PLD a, PLD b, PLD p){
	auto AB = b-a;
	auto AP = p - a;
	ld lengthSqrAB = AB.X * AB.X + AB.Y * AB.Y;
	ld t = (AP.X * AB.X + AP.Y * AB.Y) / lengthSqrAB;
	PLD pnt = (((1.0-t)*A) + (t*B))-p;
	return std::sqrt(pnt.X*pnt.X + pnt.Y*pnt.Y);
}

ld dist3d

ld ans = INF;
int n;
std::vector<PR<PII, std::vector<PLD> > > A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	ld mxy = -INF;
	int mxpoly = 0;
	FOR(i, n){
		int a, b;
		A.emplace_back();
		std::cin >> a >> b;
		A.back().X = MP(a, b);
		int m;
		std::cin >> m;
		FOR(j, 2*m){
			int x, y;
			std::cin >> x >> y;
			if((ld)y > mxy){
				mxy = y;
				mxpoly = i;
			}
			A.back().Y.push_back(MP((ld)x, (ld)y));
		}
	}
	int inside = 0;
	FOR(i, n){
		if(InsidePolygon(A[i].Y, MP(0, 0))){
			inside++;
			ans = std::min(ans, )
		}
	}
	std::cout << std::setprecision(12) << std::fixed << ans << "\n";
	return 0;
}