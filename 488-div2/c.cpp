#include <bits/stdc++.h> 

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))

using namespace std;

typedef pair<int, int> pii;
typedef array<pii, 4> square; 

square read_sq() {
    square s; 

    For (i, 4) {
        scanf("%d %d", &s[i].first, &s[i].second);
    }

    return s;
}

bool check_inside(const square &s, pii p) {
    return s[0].second <= p.second && s[1].second >= p.second
           && s[0].first <= p.first && s[2].first >= p.first;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    auto s1 = read_sq();
    auto s2 = read_sq();

    SORT(s1);
    SORT(s2);
    
    bool any = false;

    for (auto p : s2) {
        if (check_inside(s1, p)) {
            any = true;
            break;
        }
    }

    pii mid = {(s2[0].first + s2[3].first) / 2, (s2[1].second + s2[2].second) / 2};
    if (check_inside(s1, mid)) any = true;

    for (auto& p : s1) {
        int a = p.first + p.second;
        int b = p.second - p.first;
        p = {a, b};

        // printf("p: %d %d\n", a, b);
    }

    for (auto& p : s2) {
        int a = p.first + p.second;
        int b = p.second - p.first;
        p = {a, b};
        
        // printf("p: %d %d\n", a, b);
    }
    
    SORT(s1);
    SORT(s2);

    for (auto p : s1) {
        if (check_inside(s2, p)) {
            any = true;
            break;
        }
    }

    mid = {(s1[0].first + s1[3].first) / 2, (s1[1].second + s1[2].second) / 2};
    if (check_inside(s2, mid)) any = true;

    if (any) {
        puts("YES"); 
    } else puts("NO");
}

