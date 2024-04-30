#include <bits/stdc++.h>
#include <windows.h>

typedef long long ll;
using namespace std;

void initialize() { srand(GetTickCount()); }

int rand_int() { return (rand() << 16) + (rand() << 1) + (rand() & 1); }

int rand_int(int l, int r) { return l + rand_int() % (r - l + 1); }

ll rand_ll() { return ((ll)rand_int() << 32) + rand_int(); }

ll rand_ll(ll l, ll r) { return l + rand_ll() % (r - l + 1); }

vector<int> rand_vector(int n, int l, int r) { // 生成长度为n的随机数组，元素范围为[l, r]
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rand_int(l, r);
    }
    return a;
}

vector<int> rand_permutation (int n) { // 生成长度为n的随机排列
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    random_shuffle(a.begin(), a.end());
    return a;
}

vector<int> rand_vector_sum (int n, int sum, int dn = 0) { 
    vector<int> res(n);
    for (auto &x : res)
        x = dn, sum -= dn;
    while (sum--)
        res[rand_int(0, n - 1)]++;
    return res;
}
