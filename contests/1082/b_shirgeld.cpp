#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	int col = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == 'G') col++;
	}
	if (col == 0 ){
		cout << 0;
		return 0;
	}
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == 'G'){
			cnt++;
		} else{
			if (cnt == 0) continue;
			if (cnt == col){
				cout << cnt;
				return 0;
			}
			cnt++;
			for (int j = i + 1; j < n; j++){
				if (s[j] == 'G') cnt++;
				else break;
			}
			cnt = min(cnt, col);
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	ans = max(ans, min(cnt + 1, col));
	cout << ans;

	return 0;
}