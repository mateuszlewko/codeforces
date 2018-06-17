#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

#define For(i, n) for(int i = 0; i < (n); i++)

using namespace std;

const int N = 3010;
int A[N];

int f(int x)
{
    if (x <= 1)
        return x;
    
    return f(x - 2) + 4;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    For (i, n)
        scanf("%d", &A[i]);
        
    int invs = 0;
    
    For (i, n)
        for (int j = i + 1; j < n; j++)
            if (A[i] > A[j])
                invs++;
                
                
    printf("%.6lf", double(f(invs)));
}