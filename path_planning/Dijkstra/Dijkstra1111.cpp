#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<memory>
struct Point
{
    int x, y;
    Point(int x, int y):x(x),y(y){};
    double distance(Point p){
        return sqrt(pow((x-p.x),2)+pow((y-p.y),2));
    };
};
struct Node
{
    Point point;
    double g;
    std::shared_ptr<Node> parent;
    Node(Point point, double g, std::shared_ptr<Node> parent): point(point), 
    g(g),parent(parent){};
};
struct NodeCompare
{
    bool operator()(std::shared_ptr<Node>n1, std::shared_ptr<Node>n2)
    {
        return n1->g<n2->g;
    }
};

std::vector<Point>dijkstra(std::vector<std::vector<int>>&raster_map, Point &start, Point &target)
{
    int row=raster_map.size();
    int col=raster_map[0].size();
    std::vector<std::shared_ptr<Node>> closelist;
    std::vector<std::shared_ptr<Node>> openlist;
    openlist.push_back(std::make_shared<Node>(start, start.distance(start), nullptr));
    std::vector<Point> path;

    while(!openlist.empty())
    {
        sort(openlist.begin(),openlist.end(),NodeCompare());
        std::shared_ptr<Node> current= *openlist.begin();
        openlist.erase(openlist.begin());
        closelist.push_back(current);
        if (current->point.x==target.x&&current->point.y==target.y)
        {
            while (current!=nullptr)
            {
                path.push_back(current->point);
                current=current->parent;
            }
            reverse(path.begin(),path.end());
            return path;     
        }else{
            int x=current->point.x;
            int y=current->point.y;
            std::vector<Point>neighbour_node={
                {x-1,y-1},{x-1,y},{x-1,y+1},
                {x,y-1}           ,{x,y+1},
                {x+1,y-1},{x+1,y},{x+1,y+1},

            };
            for(auto n:neighbour_node)
            {
                if(n.x >= 0 && n.x < row && n.y >= 0 && n.y < col && raster_map[n.x][n.y] == 0)
                {
                    bool incloselist=false;
                    for(auto c:closelist)
                    {
                        if(c->point.x==n.x&&c->point.y==n.y)
                        {
                            incloselist=true;
                            break;
                        }
                    }
                    if(incloselist)
                    {
                        continue;
                    }
                    bool inopenlist = false;
                    for(auto o:openlist)
                    {
                        if(o->point.x == n.x && o->point.y == n.y)
                        {
                            inopenlist=true;
                            double g = current->g + n.distance(current->point); 
                            // distance of neighbour nodes=current g+ neighbour nodes to current nodes
                            if (g < (o->g))
                            {
                                o->g = g;
                                o->parent = current;
                            };
                            break;
                        }
                        if (!inopenlist)
                        {
                            double g = current->g + n.distance(current->point); 
                            // distance of neighbour nodes=current g+ neighbour nodes to current nodes
                            openlist.push_back(std::make_shared<Node>(n, g,current));
                        };

                    }
                }
            }
        }
    }
    return path;
}

