#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int maxn = 2e5 + 5;
 
int n, m, a[maxn], b[maxn];
 
struct node {
    int l, r;
    ll sum;
 
    node() {l = r = 0;sum = 0;}
    node(int l, int r, int sum) : l(l), r(r), sum(sum) {}
    bool operator<=(const node &rhs) const { return sum * (rhs.r - rhs.l + 1) <= rhs.sum * (r - l + 1); }
    void merge(const node &rhs) {
        l = rhs.l;
        sum += rhs.sum;
    }
};
 
vector<node> segs1, segs2;
 
void merge_segr(int arr[], int len, vector<node> &tmp) {
    tmp.clear();
    tmp.emplace_back(node(1, 1, arr[1]));
    for (int i = 2; i <= len; ++i) {
        node cur = node(i, i, arr[i]);
        if (!(tmp.rbegin()->operator<=(cur))) {
            tmp.emplace_back(cur);
            continue;
        }
        while (!tmp.empty() && tmp.rbegin()->operator<=(cur)) {
            cur.merge(*tmp.rbegin());
            tmp.pop_back();
        }
        tmp.emplace_back(cur);
    }
}
 
int main() {
    int T, cs = 0;
    scanf("%d", &T);
    while (T--) {
        ++cs;
        printf("Case %d: ", cs);
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
//        a[n + 1] = 0;
        merge_segr(a, n, segs1);
//        b[m + 1] = 0;
        merge_segr(b, m, segs2);
        ll ans = 0, idx = 1;
        for (auto ai = segs1.begin(), bi = segs2.begin(); ai != segs1.end() || bi != segs2.end();) {
            if (ai == segs1.end() || bi != segs2.end() && ai->operator<=(*bi)) {
                for (int i = bi->l; i <= bi->r; ++i,++idx) ans += idx * b[i];
                ++bi;
            } else {
                for (int i = ai->l; i <= ai->r; ++i,++idx) ans += idx * a[i];
                ++ai;
            }
        }
        printf("%lld\n", ans);
    }
}
