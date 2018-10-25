#include <iostream>
#define For(i, n) for(int i = 0; i<(n); i++)

using namespace std;

void run(int n) {
    while (n > 1) {
        if (n % 2 == 0)
            n = n / 2;
        else n = 3 * n + 3;
    }
}

int main() {
    long long n; 
    cin >> n;

    if (__builtin_popcountll(n) != 1) cout << "NIE\n";
    else cout << "TAK\n";
}