#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Point
{
    LL x, y, z;

    Point () {}
    Point (LL x_, LL y_, LL z_) : x(x_), y(y_), z(z_) {}
};

const int N = 1e5 + 7;
Point P[N];
int n;

bool collinear(Point l, Point r) {
    return l.x*r.y==l.y*r.x && l.y*r.z==l.z*r.y && l.x*r.z==l.z*r.x;
}

bool collinear(Point p0, Point p1, Point p2) {
    return (p0.x*p1.y*p2.z+p1.x*p2.y*p0.z+p2.x*p0.y*p1.z -
    (p2.x*p1.y*p0.z+p0.x*p2.y*p1.z+p1.x*p0.y*p2.z)) == 0;
}

bool Check ()
{
    if (n == 1) 
        return true;

    Point p = P[0];

    for (int i = 1; i < n; ++i)
        P[i] = Point(P[i].x - p.x, P[i].y - p.y, P[i].z - p.z);
    
    Point v1 = P[1];
    int i=2;
    while(i<n && collinear(v1,P[i])) ++i;
    if(i==n) return true;
    Point v2 = P[i++];
    while(i<n && collinear(v1,v2,P[i]))++i;   
    return i==n;
}

int main ()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%lld %lld %lld", &P[i].x, &P[i].y, &P[i].z);

    if (Check())
        printf("TAK");
    else
        printf("NIE");

    return 0;
}