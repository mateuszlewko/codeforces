#include <bits/stdc++.h> 

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)

using namespace std;

bool present[20];
int nums[20];

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    int n, m; 
    scanf("%d %d", &n, &m);

    For (i, n) scanf("%d", &nums[i]);
    For (i, m) {
        int a;
        scanf("%d", &a);
        present[a] = true;
    }

    For (i, n)
        if (present[nums[i]])
            printf("%d ", nums[i]);

    puts("");
}

