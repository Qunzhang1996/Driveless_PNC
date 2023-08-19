#include "A_star.h"
#include<iostream>
using namespace std;
int main() {
    vector<vector<int>> map = {
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    A_star::Point start(0, 0);
    A_star::Point end(2, 4);
    A_star astar(map);
    vector<A_star::Point> path = astar.find_path(start, end, map);

    if(path.empty()) {
        cout << "No path found!" << endl;
    } else {
        for (const auto& point : path) {
            cout << "(" << point.x << ", " << point.y << ") -> ";
        }
        cout << "END" << endl;
    }

    return 0;
}