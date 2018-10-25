#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 7;
vector < int > G[N];
int SIZE[N];

bool Dfs (int v, int k)
{
    SIZE[v] = 1;

    for (int s : G[v])
    {
        if (!Dfs(s, k))
            return false;
        SIZE[v] += SIZE[s];
    }

    if (SIZE[v] > k)
        return false;
    else
    {
        if (SIZE[v] == k)
            SIZE[v] = 0;
        return true;
    }
}

int main ()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 2; i <= n; ++i)
    {
        int a;
        scanf("%d", &a);
        G[a].push_back(i);
    }

    for (int i = 1; i <= n; ++i)
        if (n % i == 0 && Dfs(1, n / i))
            printf("%d ", i);

    return 0;
}