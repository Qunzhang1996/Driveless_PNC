import numpy as np
import matplotlib.pyplot as plt
from scipy.spatial import distance
from matplotlib.patches import Rectangle

class Node:
    def __init__(self, position, parent=None, cost=0.0):
        self.position = position
        self.parent = parent
        self.cost = cost

class RRTStar:
    def __init__(self, start, goal, field_dim, obstacles, step_size=0.5, search_radius=0.5):
        self.start = Node(start)
        self.goal = Node(goal)
        self.field_dim = field_dim
        self.step_size = step_size
        self.search_radius = search_radius
        self.nodes = [self.start]
        self.obstacles = obstacles
        self.goal_reached = False

    def step(self):
        random_point = self.get_random_point()
        nearest_node = self.get_nearest_node(random_point)
        new_node = self.get_new_node(nearest_node, random_point)

        if new_node and not self.check_collision(new_node):
            near_nodes = self.get_near_nodes(new_node)
            new_node = self.choose_parent(new_node, near_nodes)
            self.nodes.append(new_node)
            self.rewire(new_node, near_nodes)

            if not self.goal_reached and distance.euclidean(new_node.position, self.goal.position) < self.step_size:
                self.goal.parent = new_node
                self.nodes.append(self.goal)
                self.goal_reached = True

            return new_node

        return None

    def get_random_point(self):
        if np.random.rand() < 0.05:  # 5% chance to sample the goal
            return self.goal.position
        return [np.random.uniform(0, self.field_dim[i]) for i in range(2)]

    def get_nearest_node(self, point):
        return min(self.nodes, key=lambda node: distance.euclidean(node.position, point))

    def get_new_node(self, nearest_node, random_point):
        direction_vector = [random_point[i] - nearest_node.position[i] for i in range(2)]
        dist = distance.euclidean(random_point, nearest_node.position)

        step_vector = [self.step_size * direction_vector[i] / dist for i in range(2)]
        new_position = [nearest_node.position[i] + step_vector[i] for i in range(2)]

        return Node(new_position, nearest_node, nearest_node.cost + self.step_size)

    def check_collision(self, node):
        for obs in self.obstacles:
            if obs[0] < node.position[0] < obs[0] + obs[2] and obs[1] < node.position[1] < obs[1] + obs[3]:
                return True

        return False

    def get_near_nodes(self, node):
        return [near_node for near_node in self.nodes if distance.euclidean(near_node.position, node.position) <= self.search_radius]

    def choose_parent(self, new_node, near_nodes):
        if not near_nodes:
            return new_node

        costs = []
        for near_node in near_nodes:
            if self.check_collision(Node(near_node.position, new_node)):
                continue
            costs.append(near_node.cost + distance.euclidean(near_node.position, new_node.position))

        if not costs:
            return new_node

        min_cost = min(costs)
        min_index = costs.index(min_cost)

        new_node.cost = min_cost
        new_node.parent = near_nodes[min_index]

        return new_node

    def rewire(self, new_node, near_nodes):
        for near_node in near_nodes:
            no_collision = not self.check_collision(Node(near_node.position, new_node))

            if new_node.cost + distance.euclidean(new_node.position, near_node.position) < near_node.cost and no_collision:
                near_node.parent = new_node
                near_node.cost = new_node.cost + distance.euclidean(new_node.position, near_node.position)

    def trace_path(self):
        node = self.goal
        path = []
        while node:
            path.append(node)
            node = node.parent
        return path

    def plot(self, ax):
        ax.clear()
        ax.set_xlim([0, self.field_dim[0]])
        ax.set_ylim([0, self.field_dim[1]])

        for obs in self.obstacles:
            ax.add_patch(Rectangle((obs[0], obs[1]), obs[2], obs[3], color='gray'))

        for node in self.nodes:
            if node.parent:
                ax.plot(*zip(*[node.parent.position, node.position]), 'ro-')

        if self.goal_reached:
            path = self.trace_path()
            for node in path:
                if node.parent:
                    ax.plot(*zip(*[node.parent.position, node.position]), 'go-')

        ax.plot(*self.start.position, 'go')
        ax.plot(*self.goal.position, 'bo')

        plt.draw()
        plt.pause(0.01)

if __name__ == "__main__":
    obstacles = [[2, 2, 2, 6], [6, 4, 4, 2]]
    rrt_star = RRTStar(start=[0, 0], goal=[9, 9], field_dim=[10, 10], obstacles=obstacles)

    fig, ax = plt.subplots()

    for _ in range(5000):
        rrt_star.step()
        rrt_star.plot(ax)

    plt.show()
