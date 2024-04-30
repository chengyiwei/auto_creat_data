#include "file/make.h"

struct Line {
    int u, v, col;
};

typedef pair<int, int> pii;
map<pii, int> mp;

int main() {
    initialize();
    int n = 10;
    int num_c = rand_int(1, 5);
    for (int i = 1; i <= n; i++)
        mp[{i, i}] = 1;
    vector<int> du(n + 1, 0);
    vector<int> num_m = rand_vector_sum(num_c, 40, 1);
    vector<Line> lines;
    for (int k = 0; k < num_c; k++) {
        int x = num_m[k];
        int u = rand_int(1, n);
        for (int i = 0; i < x; i++) {
            int v = rand_int(1, n);
            while (mp.count({u, v}) || mp.count({v, u})) 
                v = rand_int(1, n);
            mp[{u, v}] = mp[{v, u}] = 1;
            if (rand_int(0, 1) == 0)
                lines.push_back({u, v, k + 1});
            else
                lines.push_back({v, u, k + 1});
            u = v;
        }
    }
    int s = rand_int(1, n), t = rand_int(1, n);
    printf("%d %d\n", n, (int)lines.size());
    random_shuffle(lines.begin(), lines.end());
    random_shuffle(lines.begin(), lines.end());
    random_shuffle(lines.begin(), lines.end());
    for (auto &line : lines) {
        printf("%d %d %d\n", line.u, line.v, line.col);
    }
    printf("%d %d\n", s, t);
    return 0;
}