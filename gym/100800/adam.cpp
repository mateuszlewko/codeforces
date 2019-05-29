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

#define PI 3.14159265359

int n;
std::vector<PII> A;
std::vector<ld> left, right;

ld lf(PII l, PII r){
	return (2.0*std::atan(((ld)(r.X-l.X))/(l.Y-r.Y)))/PI;
}
ld rg(PII l, PII r){
	return (2.0*std::atan(((ld)(r.X-l.X))/(r.Y-l.Y)))/PI;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		A.push_back(MP(a, b));
	}
	std::vector<PII> stack;
	left.resize(n);
	right.resize(n);
	FOR(i, n){
		while(!stack.empty() && A[i].Y >= stack.back().Y) stack.pop_back();
		while(SZ(stack) > 1 && lf(stack[SZ(stack)-2], A[i]) < lf(stack.back(), A[i])){
			stack.pop_back();
		}
		if(stack.empty()){
			left[i] = 1.0;
		}else{
			left[i] = lf(stack.back(), A[i]);
		}
		stack.push_back(A[i]);
	}
	stack.clear();
	for(int i = n-1; i >= 0; --i){
		while(!stack.empty() && A[i].Y >= stack.back().Y) stack.pop_back();
		while(SZ(stack) > 1 && rg(stack[SZ(stack)-2], A[i]) < rg(stack.back(), A[i])){
			stack.pop_back();
		}
		if(stack.empty()){
			right[i] = 1.0;
		}else{
			right[i] = rg(stack.back(), A[i]);
		}
		stack.push_back(A[i]);
	}
	FOR(i, n) std::cout << std::setprecision(6) << std::fixed << 6.0*(left[i]+right[i]) << "\n";
	return 0;
}