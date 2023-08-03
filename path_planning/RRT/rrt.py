import matplotlib.pyplot as plt
import random
import time
import numpy as np
from scipy.spatial import distance
from matplotlib.patches import Rectangle

class Node:
    def __init__(self, position, parent=None):
        self.position = position
        self.parent = parent

class RRT:
    def __init__(self, start, goal, field_dim, obstacles, step_size=1.0):
        self.start = Node(start)
        self.goal = Node(goal)
        self.field_dim = field_dim
        self.step_size = step_size
        self.nodes = [self.start]
        self.obstacles = obstacles

    def step(self):
        random_point = self.get_random_point()
        nearest_node = self.get_nearest_node(random_point)
        new_node = self.get_new_node(nearest_node, random_point)

        if new_node and not self.check_collision(new_node):
            self.nodes.append(new_node)
            return new_node

        return None

    def get_random_point(self):
        return [random.uniform(0, self.field_dim[i]) for i in range(2)]

    def get_nearest_node(self, point):
        return min(self.nodes, key=lambda node: distance.euclidean(node.position, point))

    def get_new_node(self, nearest_node, random_point):
        direction_vector = [random_point[i] - nearest_node.position[i] for i in range(2)]
        dist = distance.euclidean(random_point, nearest_node.position)

        step_vector = [self.step_size * direction_vector[i] / dist for i in range(2)]
        new_position = [nearest_node.position[i] + step_vector[i] for i in range(2)]

        return Node(new_position, nearest_node)

    def check_collision(self, node):
        for obs in self.obstacles:
            if obs[0] < node.position[0] < obs[0] + obs[2] and obs[1] < node.position[1] < obs[1] + obs[3]:
                return True

        return False

    def plot(self, ax):
        # Clear the current plot
        ax.clear()
        ax.set_xlim([0, self.field_dim[0]])
        ax.set_ylim([0, self.field_dim[1]])

        # Plot obstacles
        for obs in self.obstacles:
            ax.add_patch(Rectangle((obs[0], obs[1]), obs[2], obs[3], color='gray'))

        # Plot nodes
        for node in self.nodes:
            if node.parent:
                ax.plot(*zip(*[node.parent.position, node.position]), 'ro-')
            else:
                ax.plot(*node.position, 'go')
            ax.plot(*self.goal.position, 'bo')

        plt.draw()
        plt.pause(0.01)

if __name__ == "__main__":
    obstacles = [[2, 2, 2, 6], [6, 4, 4, 2]]
    rrt = RRT(start=[0, 0], goal=[9, 9], field_dim=[10, 10], obstacles=obstacles, step_size=0.5)

    # Create the figure and axis objects once
    fig, ax = plt.subplots()

    # Plot the initial field and tree
    rrt.plot(ax)
    plt.show(block=False)

    for _ in range(200):
        rrt.step()
        rrt.plot(ax)

    plt.show()
