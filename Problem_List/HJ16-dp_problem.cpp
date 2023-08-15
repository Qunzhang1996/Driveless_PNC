#include <algorithm>
#include <iostream>
using namespace std;

int value[63][3] = {0};
int satisf[63][3] = {0};
int f[63][3210] = {0};
int v[63], p[63], q[63];

int main() {
    int N, m;
    cin >> N >> m;
    N = N / 10;

    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> p[i] >> q[i];
        v[i] = v[i] / 10;

        if (q[i] == 0) {  // main item
            value[i][0] = v[i];
            satisf[i][0] = v[i] * p[i];
        } else if (value[q[i]][1] == 0) {  // first accessory
            value[q[i]][1] = v[i];
            satisf[q[i]][1] = v[i] * p[i];
        } else {  // second accessory
            value[q[i]][2] = v[i];
            satisf[q[i]][2] = v[i] * p[i];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= N; j++) {
            f[i][j] = f[i-1][j];  // not taking the i-th item

            // Take only the main item
            if (j >= value[i][0]) 
                f[i][j] = max(f[i][j], f[i-1][j-value[i][0]] + satisf[i][0]);

            // Take main item and first accessory
            if (j >= value[i][0] + value[i][1])
                f[i][j] = max(f[i][j], f[i-1][j-value[i][0]-value[i][1]] + satisf[i][0] + satisf[i][1]);

            // Take main item and second accessory
            if (j >= value[i][0] + value[i][2])
                f[i][j] = max(f[i][j], f[i-1][j-value[i][0]-value[i][2]] + satisf[i][0] + satisf[i][2]);

            // Take main item with both accessories
            if (j >= value[i][0] + value[i][1] + value[i][2])
                f[i][j] = max(f[i][j], f[i-1][j-value[i][0]-value[i][1]-value[i][2]] + satisf[i][0] + satisf[i][1] + satisf[i][2]);
        }
    }

    cout << f[m][N] * 10 << endl;
    return 0;
}
