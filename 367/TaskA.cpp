#include <iostream>
#include <cstdio>
#include <algorithm>
#define For(i, n) for (size_t i = 0; i < size_t(n); i++)
using namespace std;

const int N = 100 * 1000 + 10;
int sumPref[3][N];

int main()
{
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;

	For (i, s.size()) 
	{
		For (j, 3)
			sumPref[j][i + 1] = sumPref[j][i]; 
		sumPref[s[i] - 'x'][i + 1]++;
	}

	int m;
	cin >> m;
	For (i, m)
	{
		int a, b;
		cin >> a >> b;
		if (b - a + 1 < 3)
			cout << "YES\n";
		else
		{
			sort(sumPref, sumPref + 20);
			int arr[] = {	sumPref[0][b] - sumPref[0][a - 1],
							sumPref[1][b] - sumPref[1][a - 1],
							sumPref[2][b] - sumPref[2][a - 1]
						};
			sort(arr, arr + 3);
			//cout << arr[0] << "  " << arr[1] << " " << arr[2] << "\n";
			if ((arr[2] == arr[1] and arr[1] == arr[0]) or (arr[2] == arr[1] + 1 and arr[1] == arr[0]) or (arr[2] == arr[1] and arr[1] == arr[0] + 1))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}