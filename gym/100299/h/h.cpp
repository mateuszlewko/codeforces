#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for (int i = 0; i < n; i++) 
typedef long long ll;

typedef array<int, 3> point;
typedef pair<point, point> rect;
typedef pair<int, int> pii;

int get_axis(const rect &r) {
    For (i, 3) if (r.first[i] == r.second[i]) return i;
    assert(false);
}

rect proper_rect(const rect &r) {
    rect res;
    For (i, 3) {
        res.first[i] = min(r.first[i], r.second[i]);
        res.second[i] = max(r.first[i], r.second[i]);
    }

    return res;
}

rect read_rect() {
    rect r;
    For (i, 3) cin >> r.first[i];
    For (i, 3) cin >> r.second[i];

    return proper_rect(r);
}

vector<rect> axis_rects[3];

rect intersect_box(const vector<rect> &rects, int ax) {
    assert(rects.size());
    rect res = rects[0];
    
    for (const auto &r : rects) 
    {
        For (i, 3) {
            if (i == ax) continue;
            res.first[i] = max(res.first[i], r.first[i]);
            res.second[i] = min(res.second[i], r.second[i]);
        }

        res.first[ax] = min(res.first[ax], r.first[ax]);
        res.second[ax] = max(res.second[ax], r.second[ax]);
    } 

    return res;
}

bool intersect_2d(pii l, pii r) {
    // cout << "l: " << l.first << ", " << l.second << ", r: " << r.first << ", " << r.second << endl;

    if (l.first > r.first) swap(l, r);
    return l.first < r.first && l.second > r.first && l.second < r.second;
}

bool intersect_point_2d(pii seg, int p) {
    return p > seg.first && p < seg.second;
}

bool all_intersect(const vector<rect> &box_rects, int box_ax, const vector<rect> &rects) {
    if (box_rects.empty() || rects.empty()) 
    {
        // cout << "false empty" << endl;
        return false;
    }

    rect box = intersect_box(box_rects, box_ax);
    
    For (i, 3) {
        if (box.second[i] < box.first[i]) {
            // cout << "false size" << endl;
            // cout << "i: " << i << ", box sd: " << box.second[i] << ", box ft: " << box.first[i] << endl;
            return false;
        }
    }

    for (auto r : rects) {
        For (i, 3) {
            if (i == box_ax) continue;

            pii box_side = {box.first[i], box.second[i]};
            if (i == get_axis(r)) {
                if (!intersect_point_2d(box_side, r.first[i])) return false;
            }
            else if (!intersect_2d(box_side, {r.first[i], r.second[i]})) 
            {
                // cout << "false intersect 2d" << endl;
                return false;
            }
        }

        if (!(r.first[box_ax] < box.first[box_ax] && r.second[box_ax] > box.second[box_ax])) return false;
    }

    return true;
}

bool con[3][3];

void solve() {
    int n;
    cin >> n;

    For (i, 3) axis_rects[i].clear();

    For (i, n) {
        rect r = read_rect();
        int ax = get_axis(r);
        axis_rects[ax].push_back(r);
    }

    For (i, 3) {
        For (j, 3) {
            if (i == j) continue;

            // cout << "checking i: " << i << ", j: " << j << endl;

            con[i][j] = all_intersect(axis_rects[i], i, axis_rects[j]);
        }
    }

    // cout << "con:\n";
    // For (i, 3) {
    //     For (j, 3) {
    //         cout << con[i][j] << " ";
    //     }

    //     cout << endl;
    // }
    // cout << endl;

    for (int i = 1; i < (1 << 3) - 1; i++) {
        bool ok = true;
        // cout << "mask: " << i << endl;
        bool once = false;
        For (j, 3) {
            For (k, 3) {
                bool j_ok = (i & (1 << j)) && axis_rects[j].size();
                bool k_ok = !(i & (1 << k)) && axis_rects[k].size();

                if (j_ok && k_ok) {
                    // cout << "j: " << j << ", k: " << k << ", con: " << con[j][k] << ", con2: " 
                    //      << con[k][j] << endl;

                     if (!con[j][k] && !con[k][j]) {
                        ok = false;
                        break;
                    }

                    once = true;
                }
            } 
        }

        if (ok && once) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
}