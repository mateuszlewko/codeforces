#include<bits/stdc++.h>
#define For(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 100 * 1000  + 10;
vector<int> row[N];
vector<int> col[N];

ll walked = 1;

set<int> done_col, done_row;
int n, m;

int get_end(int pos, set<int> &done, vector<int> &bl, bool grt) {
	if (grt) {
		int res = *done.upper_bound(pos);
		return min(res, *upper_bound(bl.begin(), bl.end(), pos)) - 1;
	} else {
		int res = *prev(done.lower_bound(pos));
		
		// cout << "pos: " << pos << ", res: " << res << endl;

		return max(res, *prev(lower_bound(bl.begin(), bl.end(), pos))) + 1;
	}
}

set<pii> vis;

void go(int x, int y, int dir) {
	// cout << "x: " << x << ", y: " << y << ", dir: " << dir << ", w: " << walked << endl;

	pii p = {x, y};
	if (vis.count(p) && !(x == 1 && y == 1 && dir == 1)) return;
	vis.insert(p);

	if (dir == 0) {
		int end_pos = get_end(y, done_col, row[x], true);
		// cout << "w: " << end_pos - y << endl;
		walked += end_pos - y;
		done_row.insert(x);

		return go(x, end_pos, 1);
	} else if (dir == 1) {
		int end_pos = get_end(x, done_row, col[y], true);
		walked += end_pos - x;
		// cout << "w: " << end_pos - x << endl;
		done_col.insert(y);

		return go(end_pos, y, 2);
	} else if (dir == 2) {
		int end_pos = get_end(y, done_col, row[x], false);
		walked += y - end_pos;
		// cout << "w: " << y - end_pos << endl;
		done_row.insert(x);

		return go(x, end_pos, 3);
	} else {
		int end_pos = get_end(x, done_row, col[y], false);
		walked += x - end_pos;
		// cout << "w: " << x - end_pos << endl;

		done_col.insert(y);

		return go(end_pos, y, 0);
	}
}

int main() {
	ios::sync_with_stdio(0);

	int k;
	cin >> n >> m >> k;

	For (i, k) {
		int x, y;
		cin >> x >> y;
		row[x].push_back(y);
		col[y].push_back(x);
	}

	For (i, n + 2) {
		row[i].push_back(0);
		row[i].push_back(m + 1);
	} 

	For (i, m + 2) {
		col[i].push_back(0);
		col[i].push_back(n + 1);
	} 

	done_col.insert(0);
	done_col.insert(m + 1);
	done_row.insert(0);
	done_row.insert(n + 1);

	For (i, N) {
		sort(row[i].begin(), row[i].end());
		sort(col[i].begin(), col[i].end());
	}

	go(1, 1, 0);

	// cout << "walked: " << walked << endl;

	if (walked < (ll)n * m - (ll)k) cout << "No\n";
	else cout << "Yes\n";
}
