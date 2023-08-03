#include "path_planning.h"

std::vector<Point> AStar(std::vector<std::vector<int>>& raster_map, Point& start, Point& target)
{
    int row = raster_map.size();
    int col = raster_map[0].size();
    std::vector<std::shared_ptr<Node>> closelist;
    std::vector<std::shared_ptr<Node>> openlist;
    openlist.push_back(std::make_shared<Node>(start, 0, nullptr, 0, start.distance(target)));
    std::vector<Point> path;

    while (!openlist.empty())
    {
        std::sort(openlist.begin(), openlist.end(), NodeCompare());
        std::shared_ptr<Node> current = *openlist.begin();
        openlist.erase(openlist.begin());
        closelist.push_back(current);

        if (current->point.x == target.x && current->point.y == target.y)
        {
            while (current != nullptr)
            {
                path.push_back(current->point);
                current = current->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }
        else
        {
            int x = current->point.x;
            int y = current->point.y;
            std::vector<Point> neighbour_node = {
                {x - 1, y - 1}, {x - 1, y}, {x - 1, y + 1},
                {x, y - 1},                 {x, y + 1},
                {x + 1, y - 1}, {x + 1, y}, {x + 1, y + 1}};

            for (auto n : neighbour_node)
            {
                if (n.x >= 0 && n.x < row && n.y >= 0 && n.y < col && raster_map[n.x][n.y] == 0)
                {
                    bool incloselist = false;
                    for (auto c : closelist)
                    {
                        if (c->point.x == n.x && c->point.y == n.y)
                        {
                            incloselist = true;
                            break;
                        }
                    }
                    if (incloselist)
                    {
                        continue;
                    }
                    double g = current->g + n.distance(current->point);
                    // distance of neighbour nodes = current g + neighbour nodes to current nodes
                    double h = n.distance(target); // heuristic cost from the neighbour node to the target node
                    double f = g + h; // total cost
                    bool inopenlist = false;
                    for (auto o : openlist)
                    {
                        if (o->point.x == n.x && o->point.y == n.y)
                        {
                            inopenlist = true;
                            if (f < o->f)
                            {
                                o->f = f;
                                o->g = g;
                                o->h = h;
                                o->parent = current;
                            }
                            break;
                        }
                    }
                    if (!inopenlist)
                    {
                        openlist.push_back(std::make_shared<Node>(n, f, current, g, h));
                    }
                }
            }
        }
    }
    return path;
}
