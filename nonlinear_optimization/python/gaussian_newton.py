import numpy as np
import matplotlib.pyplot as plt

# Objective function: f(x) = x^2 + 10*sin(x)
def objective_function(x):
    return x**2 + 10 * np.sin(x)

# Derivative of the objective function: f'(x) = 2*x + 10*cos(x)
def derivative_function(x):
    return 2 * x + 10 * np.cos(x)

def gradient_descent(learning_rate, initial_x, epochs):
    x = initial_x
    x_history = [x]
    for epoch in range(1000):
        gradient = derivative_function(x)
        x -= learning_rate * gradient
        x_history.append(x)
        if epoch > 0 and abs(objective_function(x_history[-1]) - objective_function(x_history[-2])) < 1e-6:
            break
    return x, np.array(x_history)

def gauss_newton(initial_x, epochs):
    x = initial_x
    x_history = [x]
    for epoch in range(epochs):
        gradient = derivative_function(x)
        hessian_approximation = 2 + 10 * np.sin(x)
        x -= gradient / hessian_approximation
        x_history.append(x)
    return x, np.array(x_history)

learning_rate = 0.4
initial_x = 5
epochs = 20

# Find the minimum using Gradient Descent
min_x_gd, x_history_gd = gradient_descent(learning_rate, initial_x, epochs)

# Find the minimum using Gauss-Newton
min_x_gn, x_history_gn = gauss_newton(initial_x, epochs)

# Generate points for visualization
x_vals = np.linspace(-10, 10, 500)
y_vals = objective_function(x_vals)

# Plot the function and the found minimum points
plt.plot(x_vals, y_vals, label='Objective Function')
plt.scatter(x_history_gd, objective_function(x_history_gd), color='red', label='Gradient Descent', marker='o')
plt.scatter(x_history_gn, objective_function(x_history_gn), color='green', label='Gauss-Newton', marker='x')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.title('Gradient Descent vs. Gauss-Newton')
plt.legend()
plt.grid(True)
plt.show()

print("Minimum x using Gradient Descent:", min_x_gd)
print("Minimum x using Gauss-Newton:", min_x_gn)
