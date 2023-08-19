#ifndef A_STAR_H
#define A_STAR_H
#include<vector>
#include<cmath>
#include<algorithm>
class A_star{
public:
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
        // friend class NodeComparison;
    };
    class NodeComparison
    {
    public:
        bool operator()(const Node* Point1, const Node* Point2){
            return Point1->f > Point2->f;
        }
    };
private:
    std::vector<Node*>allNodes;
    std::vector<std::vector<int>> map;
    std::vector<Point>find_neighour(const Point& point, const std::vector<std::vector<int>> map);
    double calculate_distance(Point& point1, Point& point2);
public:
    A_star(const std::vector<std::vector<int>>& map);
    ~A_star(); // Destructor declaration
    std::vector<Point> find_path(Point& start, Point& end, std::vector<std::vector<int>> map);
};
#endif