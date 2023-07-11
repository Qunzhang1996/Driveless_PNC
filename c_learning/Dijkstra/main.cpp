#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// Dijkstra Algorithm Based on Grid Map --C++
/*
    function Dijkstra(Graph, source):
    create empty set Q
    create empty dist array
    create empty prev array

    // Initialization
    for each vertex v in Graph:
    dist[v] = INFINITY // Initialize all distances to infinity
    prev[v] = undefined // Set the previous node of v to undefined
    add v to Q // Add v to the set Q

    dist[source] = 0 // Distance from source to source is 0

    // Main loop
    while Q is not empty:
    u = vertex in Q with the minimum distance

    remove u from Q

    // Update distances of neighbors
    for each neighbor v of u:
    alt = dist[u] + distance between u and v
    if alt < dist[v]:
    dist[v] = alt
    prev[v] = u

    return dist, prev

*/
struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y){}; // initialize the list
    double distance(Point p)            // calculate the distance
    {
        return sqrt((x - p.x)* (x - p.x)+ (y - p.y)*(y - p.y));
    };
};

// define the nodes
struct Node
{
    Point point;                                                                                // location of the point
    double g;                                                                                   // define the distance between the begin
    Node *parent;                                                                               // parent node ptr
    Node(Point point, double g, Node *parent = nullptr) : point(point), g(g), parent(parent){}; // initialize the character
};
// self-defined compare func
struct NodeCompare
{
    bool operator()(Node *n1, Node *n2){
        return (n1->g) < (n2->g); // sort from low to high
    };
};

// Dijkstra path planning
vector<Point> DijkstraPathPlanning(vector<vector<int>> &gridmap, Point &start, Point &goal)
{
    int row = gridmap.size();
    int col = gridmap[0].size();
    vector<Node *> openlist;
    vector<Node *> closelist;
    openlist.push_back(new Node(start, start.distance(start))); // put begin point into the openlist to initialize
    // find the path in the while
    vector<Point> path;
    while (!openlist.empty()) // if the openlist is empty, it means that all nodes has been sarched!!!!
    {
        // get the minium g nodes in the openlist as current search nodes
        sort(openlist.begin(), openlist.end(), NodeCompare{});
        Node *current = *openlist.begin(); // using pointer
        openlist.erase(openlist.begin());  // get current and remove it from openlist
        closelist.push_back(current);      // push_back using ptr
        // if current is the goal, get the path from the end
        if (current->point.x == goal.x && current->point.y == goal.y)
        {
            while (current != nullptr)
            {
                path.push_back(current->point);
                current = current->parent;
            };
            reverse(path.begin(), path.end());
            return path;
        }
        else // if the current is not the end, expand the neighbour nodes
        {
            int x = current->point.x;
            int y = current->point.y;
            vector<Point> neighbors =
                {
                    {x - 1, y - 1}, {x - 1, y}, {x - 1, y + 1}, {x, y - 1}, {x, y + 1}, {x + 1, y - 1}, {x + 1, y}, {x + 1, y + 1}};
            // iterate the neighbour nodes
            for (auto n : neighbors)
            {
                // iterate condition, neighbour nodes inside the map and !=obstacle
                if (n.x >= 0 && n.x < row && n.y >= 0 && n.y < col && gridmap[n.x][n.y] == 0)
                {
                    // 2.1 if inside the closelist, skip
                    bool incloselist = false;
                    for (auto c : closelist)
                    {
                        if (c->point.x == n.x && c->point.y == n.y)
                        {
                            incloselist = true;
                            break;
                        };
                    }
                    if (incloselist)
                    {
                        continue;
                    };
                    // 2.2 if inside the openlist
                    bool inopenlist = false;
                    for (auto o : openlist)
                    {
                        if (o->point.x == n.x && o->point.y == n.y){
                            inopenlist = true;
                            // update the g and parent nodes
                            double g = current->g + n.distance(current->point); // distance of neighbour nodes=current g+ neighbour nodes to current nodes
                            if (g < (o->g))
                            {
                                o->g = g;
                                o->parent = current;
                            };
                            break;
                        }
                    }
                    if (!inopenlist)
                    {
                        double g = current->g + n.distance(current->point); // distance of neighbour nodes=current g+ neighbour nodes to current nodes
                        openlist.push_back(new Node(n, g,current));
                    };
                };
            };
        };
    };
    // if no path has been found, return empty path
    for(auto o:openlist)
    {
        delete o;
    };
    for (auto c:closelist)
    {
        delete c;
    };
    
    return path;
}

int main()
{
    vector<vector<int>> gridmap =
        {
            {0, 1, 0, 1, 0},
            {1, 0, 1, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 1, 0, 1, 0}};
    // define the begin point and end point
    Point start(0, 0);
    Point goal(4, 4);
    vector<Point> path =DijkstraPathPlanning(gridmap, start, goal);
    cout<<"+++++++++++++"<<endl;
    cout<<path.size()<<endl;
    cout<<"path:  ";
    for(auto p:path)
    {
        if(p.x==goal.x &&p.y==goal.y)
        {
            cout<<"("<<p.x<<" , "<<p.y<<")"<<endl;
        }else
        {
            cout<<"("<<p.x<<" , "<<p.y<<")"<<"->";
        };
    }
    return 0;
};