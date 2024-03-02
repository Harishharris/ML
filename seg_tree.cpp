class SegmentTree {
    public:
        vector<ll> tree, a;
        SegmentTree(vector<ll> &a) {
            ll n = a.size();
            tree.resize(4 * n);
            this->a = a;
            build(0, 0, n - 1);
        }

        void build(ll ind, ll low, ll high) {
            if (low == high) {
                tree[ind] = a[low];
                return;
            }
            ll mid = (low + high) / 2;
            build(2 * ind + 1, low, mid);
            build(2 * ind + 2, mid + 1, high);
            tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
        }

        ll query(ll ind, ll low, ll high, ll left, ll right) {
            if (low >= left && high <= right) {
                return tree[ind];
            }
            if (high < left || low > right) {
                return 0;
            }
            ll mid = (low + high) / 2;
            ll leftSum = query(2 * ind + 1, low, mid, left, right);
            ll rightSum = query(2 * ind + 2, mid + 1, high, left, right);
            return rightSum + leftSum;
        }

        void pointUpdate(ll ind, ll low, ll high, ll node, ll val) {
            if (low == high) {
                tree[ind] = val;
            } else {
                ll mid = (low + high) >> 1;
                if (node >= low && node <= mid) {
                    pointUpdate(2 * ind + 1, low, mid, node, val);
                } else {
                    pointUpdate(2 * ind + 2, mid + 1, high, node, val);
                }
                tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
            }
        }
};