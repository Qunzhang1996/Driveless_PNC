#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct Point
{
    int x,y;
    Point(int x, int y):x(x),y(y){};
};
struct Node
{
    Point point;
    double g;
    double n;
    double f;
    Node* parent;
    Node(Point& point, double g, double n, double f, Node* parent=nullptr):point(point),g(g),n(n),f(f),parent(parent){};
};
struct Nodecomparison
{
    bool operator()(Node* Point1, Node* Point2)
    {
        return Point1->f>Point2->f;
    }
};
vector<Point>find_neighour(const Point& point, const vector<vector<int>> map)
{
    int x=point.x;
    int y=point.y;
    vector<Point>neighbour_nodes;

    for (int i=x-1;i<=x+1;i++)
    {
        for(int j=y-1;j<=y+1;j++)
        {
            if(i==x&&j==y) continue;
            if(i >= 0 && j >= 0 && i < map.size() && j < map[0].size() && map[i][j] == 0)
            {
                neighbour_nodes.push_back({i,j});
            }
        }
    }
    return neighbour_nodes;
};
double calculate_distance(Point& point1, Point& point2)
{
    double distance = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
    const double DIAGONAL_BIAS = 0.001;

    // Check if the movement is diagonal
    if (abs(point1.x - point2.x) == 1 && abs(point1.y - point2.y) == 1) 
    {
        distance += DIAGONAL_BIAS;
    }
    return distance;
}
vector<Point> A_Star(Point& start, Point& end, vector<vector<int>> map)
{
    vector<Node*>openlist;
    vector<Node*>closelist;
    vector<Point>path;
    double n =calculate_distance(start,end);
    Node* current=new Node(start, 0, n, n,nullptr);
    openlist.push_back(current);
    while (!openlist.empty())
    {
        sort(openlist.begin(),openlist.end(),Nodecomparison());
        current=*openlist.begin();
        openlist.erase(openlist.begin());
        closelist.push_back(current);
        if(current->point.x==end.x&&current->point.y==end.y)
        {
            Node* terminal=current;
            while(terminal->parent!=nullptr)
            {
                path.push_back(terminal->point);
                terminal=terminal->parent;
            };
            path.push_back(start);
            reverse(path.begin(),path.end());
            return path;
        };
        vector<Point>neighbour_nodes=find_neighour(current->point, map);
        for(auto neigh:neighbour_nodes)
        {
            bool incloselist = false;
            for(auto c:closelist)
            {
                if(c->point.x==neigh.x&&c->point.y==neigh.y) 
                {
                    incloselist=true;
                    break;
                }
            };
            if(incloselist) continue;

            bool inopenlist = false;
            for(auto o:openlist)
            {
                if(o->point.x==neigh.x&&o->point.y==neigh.y)
                {
                    inopenlist=true;
                    double g=current->g+calculate_distance(neigh,current->point);
                    double n=calculate_distance(neigh,end);
                    double f=g+n;
                    if(f<o->f)
                    {
                        o->g=g;
                        o->f=f;
                        o->parent=current;
                    }
                }
            };
            if(!inopenlist)
            {
                double g=current->g+calculate_distance(neigh,current->point);
                double n=calculate_distance(neigh,end);
                double f=g+n;
                openlist.push_back(new Node(neigh,g,n,f,current));
            };
        }
    }
    
    for(auto o:openlist) delete o;
    for(auto c:closelist) delete c;
    openlist.clear();
    closelist.clear();
    delete current;
    return {};
    
};

int main() {
    vector<vector<int>> map = {
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    Point start(0, 0);
    Point end(2, 4);

    vector<Point> path = A_Star(start, end, map);

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
