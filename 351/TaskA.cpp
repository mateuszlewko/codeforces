#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

#define For(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int ones = 0;
    int zeros = 0;
    
    double sum = 0;
    double ceilSum = 0;
    
    For (i, 2 * n)
    {
        double a;
        scanf("%lf", &a);
        
        if (a - floor(a) < .00001)
            zeros++;
        else
            ones++;
            
        sum += a;
        ceilSum += ceil(a);
    }
    
    double possibleRes = min(ceil(ceilSum - sum) - (ceilSum - sum), ceilSum - sum - floor(ceilSum - sum));
    int ind = n;
    
    while (ones > 0 and fabs(ceilSum - sum) > possibleRes and ind-- > 0)
    {
        ceilSum -= 1.0;
        ones--;
    }
    
    while (zeros > 0 and ind-- > 0)
        zeros--;
    
    while (ind-- > 0)
        ceilSum -= 1.0;
    
    printf("%.3lf\n", fabs(ceilSum - sum));
}