#include "A_star.h"
using namespace std;
A_star::A_star(const vector<vector<int>>& map) : map(map) {}
A_star::~A_star() {
    for (auto node : allNodes) {
        delete node;
    }
    allNodes.clear();
};
vector<A_star::Point> A_star::find_neighour(const Point& point, const vector<vector<int>> map)
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
double A_star::calculate_distance(Point& point1, Point& point2)
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
vector<A_star::Point> A_star::find_path(Point& start, Point& end, vector<vector<int>> map)
{
    vector<Node*>openlist;
    vector<Node*>closelist;
    vector<Point>path;
    double n =calculate_distance(start,end);
    Node* current=new Node(start, 0, n, n,nullptr);
    allNodes.push_back(current);
    openlist.push_back(current);
    while (!openlist.empty())
    {
        sort(openlist.begin(),openlist.end(),NodeComparison());
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
                allNodes.push_back(new Node(neigh,g,n,f,current));
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