#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#if DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string>) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#else
#define error(...) do {} while (0)
#endif

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#pragma endregion 

struct node;
typedef node* node_ptr;

struct node {
	int max_ones;
	int pref;
	int suf;
	int len;
	int l, r;
	
	node_ptr left, right;

	node () {}
	node (int _max_ones, int _pref, int _suf, int _len, int _l, int _r, node_ptr _left, node_ptr _right) {
		this->l = _l;
		this->r = _r;
		this->max_ones = _max_ones;
		this->pref = _pref;
		this->suf = _suf; 
		this->len = _len;
		this->left = _left; 
		this->right = _right;
	}

	void print() {
		error(max_ones, pref, suf, len, l, r, left, right);
		puts("---------");
	}
};

node_ptr init(int l, int r) {
	return new node(0, 0, 0, r - l + 1, l, r, nullptr, nullptr);
} 

node_ptr make_parent(const node_ptr lhs, const node_ptr rhs) {
	int max_ones = max(lhs->max_ones, max(rhs->max_ones, lhs->suf + rhs->pref));
	int pref = lhs->pref == lhs->len ? lhs->len + rhs->pref : lhs->pref;
	int suf = rhs->suf == rhs->len ? lhs->suf + rhs->len : rhs->suf;
	int len = lhs->len + rhs->len;
	int l = lhs->l;
	int r = rhs->r;
	return new node(max_ones, pref, suf, len, l, r, lhs, rhs);
}

vector<node_ptr> found_nodes;
vector<node_ptr> delete_these;

void query_helper(const node_ptr root, int l, int r, int p, int q) {
	if (root == nullptr) {
		auto n = init(l, r);
		delete_these.push_back(n);
		return found_nodes.push_back(n);
	} 

	if (root->l >= l && root->r <= r) {
		return found_nodes.push_back(root);
	}

	int mid = (p + q) >> 1;
	if (l <= mid) {
		query_helper(root->left, l, min(r, mid), p, mid);
	}
	
	if (r > mid) {
		query_helper(root->right, max(l, mid + 1), r, mid + 1, q);
	}
}

int query(const node_ptr root, int l, int r, int p, int q) {
	query_helper(root, l, r, p, q);

	auto res = accumulate(begin(found_nodes), end(found_nodes), init(l, r), 
	                     [&delete_these](auto l, auto r) { 
							auto p = make_parent(l, r);
							delete_these.push_back(p);
							return p;
						})->max_ones;

	for (auto n : delete_these) {
		delete n;
	}
	found_nodes.clear();
	delete_these.clear();

	return res;
}

node_ptr set_one(const node_ptr root, int l, int r, int x) {
	if (l == r && l == x) {
		return new node(1, 1, 1, 1, l, r, nullptr, nullptr); 
	} else if (l == r) {
		assert(false);
	}

	int mid = (l + r) >> 1; 
	if (x <= mid) {
		auto left = root != nullptr ? root->left : nullptr;
		auto right = root != nullptr && root->right != nullptr 
				     ? root->right : init(mid + 1, r);
		return make_parent(set_one(left, l, mid, x), right);
	} else {
		auto left = root != nullptr && root->left != nullptr 
		            ? root->left : init(l, mid);
		auto right = root != nullptr ? root->right : nullptr;
		return make_parent(left, set_one(right, mid + 1, r, x));
	}
}

void print_tree(node_ptr root) {
	if (root == nullptr) return;
	root->print();
	print_tree(root->left);
	print_tree(root->right);
}

const int N = (1<<17) - 1;
node_ptr trees[N];

int main() {
	trees[0] = init(0, N);
	int n;
	scanf("%d", &n);
	map<int, vector<int>> hs;

	For (i, n) {
		int a; 
		scanf("%d", &a);
		hs[a].push_back(i);
	}

	vector<int> single_hs;
	
	int prev = 0;
	for (auto iter = hs.rbegin(); iter != hs.rend(); ++iter) {
		auto h_vec = *iter;
		single_hs.push_back(h_vec.first);

		auto root = trees[prev++];
		auto next_root = accumulate(begin(h_vec.second), end(h_vec.second), root, 
		                            [](auto acc, auto curr) { 
										return set_one(acc, 0, N, curr); });
		trees[prev] = next_root;
	}

	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r, w;
		scanf("%d %d %d", &l, &r, &w);

		int beg = 0, end = single_hs.size();
		while (beg != end) {
			int mid = (beg + end) >> 1;
			if (query(trees[mid + 1], l - 1, r - 1, 0, N) >= w) {
				end = mid;
			} else {
				beg = mid + 1;
			}
		}

		printf("%d\n", single_hs[beg]);
	}
}

