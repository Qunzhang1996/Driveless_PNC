#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//Dijkstra Algorithm Based on Grid Map --C++
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
    int x,y;
    Point(int x, int y):x(x),y(y){};//initialize the list
    double distance(Point p)//calculate the distance
    {
        return sqrt((x-p.x)^2+(y-p.y)^2);
    };
};

//define the nodes
struct Node
{
    Point point;//location of the point
    double g;//define the distance between the begin
    Node *parent;//parent node ptr
    Node(Point point, double g, Node *parent=nullptr):point(point),g(g),parent(parent){};//initialize the character
};
//self-defined compare func
struct  NodeCompare{
    bool operator()(Node *n1, Node *n2){
        return (n1->g)<(n2->g)//sort from low to high
    };
};

//Dijkstra path planning
vector<Point>DijkstraPathPlanning(vector<vector<int>> &gridmap, Point &start, Point &end)
{
    int row=gridmap.size();
    int col=gridmap[0].size();
    vector<Node *>openlist;
    vector<Node *>closelist;
    openlist.push_back(new Node(start, start.distance(start)));//put begin point into the openlist to initialize
    //find the path in the while
    vector<Point> path;
    while (!openlist.empty())//if the openlist is empty, it means that all nodes has been sarched!!!!
    {
        //get the minium g nodes in the openlist as current search nodes
        sort(openlist.begin(),openlist.end(), NodeCompare{});
        Node *current=*openlist.begin();//using pointer
        openlist.erase(openlist.begin());//get current and remove it from openlist
        closelist.push_back(current);//push_back using address
    };
    //if no path has been found, return empty path
    return path;
    
};


int main()
{
    vector<vector<int>> gridmap=
    {
        {0,1,0,1,0},
        {1,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0},
        {0,1,0,1,0}
    };
    return 0;
    //define the begin point and end point
    Point start(0,0);
    Point goal(4,4);
};