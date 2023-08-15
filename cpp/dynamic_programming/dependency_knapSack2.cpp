#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int weight[60][3] = {0}; // Stores prices of main items and their attachments
int value[60][3] = {0};  // Stores value (importance multiplied by price) for the items
int f[60][3200] = {0};   // Memoization table to store maximum value for each item with remaining budget

// DFS function to compute maximum value we can get by purchasing items starting from index 'idx' with 'remaining_budget'
int dfs(int idx, int remaining_budget) {
    // Base case: if all items are processed or no budget left, return 0
    if(idx > M || remaining_budget <= 0) return 0;

    // If this state is already computed, return it
    if(f[idx][remaining_budget] != 0) return f[idx][remaining_budget];

    // Scenario 1: Not buying current item and moving to next
    int result_without_buying = dfs(idx + 1, remaining_budget);

    // Scenario 2: Buying only the main item and moving to next
    int result_with_main = 0;
    if(remaining_budget >= weight[idx][0]) {
        result_with_main = value[idx][0] + dfs(idx + 1, remaining_budget - weight[idx][0]);
    }

    // Scenario 3: Buying main item and its first attachment and moving to next
    int result_with_main_and_1 = 0;
    if(remaining_budget >= weight[idx][0] + weight[idx][1]) {
        result_with_main_and_1 = value[idx][0] + value[idx][1] + dfs(idx + 1, remaining_budget - weight[idx][0] - weight[idx][1]);
    }

    // Scenario 4: Buying main item and its second attachment and moving to next
    int result_with_main_and_2 = 0;
    if(remaining_budget >= weight[idx][0] + weight[idx][2]) {
        result_with_main_and_2 = value[idx][0] + value[idx][2] + dfs(idx + 1, remaining_budget - weight[idx][0] - weight[idx][2]);
    }

    // Scenario 5: Buying main item and both its attachments and moving to next
    int result_with_all = 0;
    if(remaining_budget >= weight[idx][0] + weight[idx][1] + weight[idx][2]) {
        result_with_all = value[idx][0] + value[idx][1] + value[idx][2] + dfs(idx + 1, remaining_budget - weight[idx][0] - weight[idx][1] - weight[idx][2]);
    }

    // Store the maximum of all scenarios in memoization table
    f[idx][remaining_budget] = max({result_without_buying, result_with_main, result_with_main_and_1, result_with_main_and_2, result_with_all});

    return f[idx][remaining_budget];
}

int main() {
    cin >> N >> M; // N = Total Budget, M = Number of items
    N /= 10; // Normalize budget since prices are in multiples of 10A

    // Reading item details
    for(int i = 1; i <= M; i++) {
        int v, p, q;
        cin >> v >> p >> q;
        v /= 10; // Normalize item price

        // If q=0, it means the item is a main item
        if(q == 0) {
            weight[i][0] = v;
            value[i][0] = v * p;
        } else {
            // If the item is an attachment, check which attachment spot (first or second) is empty for the main item
            if(weight[q][1] == 0) {
                weight[q][1] = v;
                value[q][1] = v * p;
            } else {
                weight[q][2] = v;
                value[q][2] = v * p;
            }
        }
    }

    // Start DFS from first item with full budget
    cout << dfs(1, N) * 10 << endl;

    return 0;
}
