import numpy as np
from scipy.spatial import distance
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import time

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

            if distance.euclidean(new_node.position, self.goal.position) < self.step_size:
                potential_goal_cost = new_node.cost + distance.euclidean(new_node.position, self.goal.position)
                if not self.goal_reached or potential_goal_cost < self.goal.cost:
                    self.goal.parent = new_node
                    self.goal.cost = potential_goal_cost
                    self.goal_reached = True

            return new_node

        return None



    def get_random_point(self):
        if np.random.rand() < 0.05:
            return self.goal.position
        return [np.random.uniform(0, self.field_dim[i]) for i in range(2)]

    def get_nearest_node(self, point):
        return min(self.nodes, key=lambda node: distance.euclidean(node.position, point))

    def get_new_node(self, nearest_node, random_point):
        direction_vector = [random_point[i] - nearest_node.position[i] for i in range(2)]
        dist = distance.euclidean(random_point, nearest_node.position)
        
        if dist == 0:
            return None

        step_vector = [self.step_size * direction_vector[i] / dist for i in range(2)]
        new_position = [nearest_node.position[i] + step_vector[i] for i in range(2)]
        return Node(new_position, nearest_node, nearest_node.cost + self.step_size)


    def check_collision(self, node):
        for obs in self.obstacles:
            if obs[0] < node.position[0] < obs[0] + obs[2] and obs[1] < node.position[1] < obs[1] + obs[3]:
                return True
        return False

    def get_near_nodes(self, new_node):
        return [node for node in self.nodes if distance.euclidean(node.position, new_node.position) < self.search_radius]

    def choose_parent(self, new_node, near_nodes):
        if not near_nodes:
            return new_node

        cheapest_node = min(near_nodes, key=lambda node: node.cost + distance.euclidean(node.position, new_node.position))
        new_node.cost = cheapest_node.cost + distance.euclidean(cheapest_node.position, new_node.position)
        new_node.parent = cheapest_node

        return new_node

    def rewire(self, new_node, near_nodes):
        for node in near_nodes:
            if new_node.cost + distance.euclidean(new_node.position, node.position) < node.cost:
                node.parent = new_node
                node.cost = new_node.cost + distance.euclidean(new_node.position, node.position)

    def plot(self, ax):
        ax.clear()

        for node in self.nodes:
            if node.parent:
                ax.plot([node.position[0], node.parent.position[0]], [node.position[1], node.parent.position[1]], 'b-', lw=0.5)

        for obs in self.obstacles:
            ax.add_patch(patches.Rectangle((obs[0], obs[1]), obs[2], obs[3], edgecolor='r', facecolor='r'))

        if self.goal_reached:
            node = self.goal
            while node.parent is not None:
                ax.plot([node.position[0], node.parent.position[0]], [node.position[1], node.parent.position[1]], 'g-', lw=2.0)
                node = node.parent

        ax.plot(self.start.position[0], self.start.position[1], 'go', markersize=10)
        ax.plot(self.goal.position[0], self.goal.position[1], 'ro', markersize=10)
        plt.xlim(0, self.field_dim[0])
        plt.ylim(0, self.field_dim[1])
        plt.grid(True)
        plt.pause(0.01)

if __name__ == "__main__":
    obstacles = [[2, 2, 2, 6], [6, 4, 4, 2]]
    rrt_star = RRTStar(start=[0, 0], goal=[9, 9], field_dim=[10, 10], obstacles=obstacles)

    fig, ax = plt.subplots()

    start_time = time.time()
    max_duration = 100  # maximum duration in seconds

    while time.time() - start_time < max_duration:
        rrt_star.step()
        rrt_star.plot(ax)

    plt.show()
