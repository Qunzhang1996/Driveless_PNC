import numpy as np
import matplotlib.pyplot as plt

def meansuqre_error(y_true,y_pred):
    return (y_true-y_pred)**2


def gradient_descent(X,y,learning_rate,epochs):
    lens=len(y)
    theta=np.random.randn(3,1)
    X_b=np.c_[np.ones(lens),X,X**2]
    for epoch in range(epochs):
        gradient=-2/lens*X_b.T@(y-X_b@theta)
        theta-=learning_rate*gradient


    return theta

# Quadratic model dataset
np.random.seed(0)
X_quad = 2 * np.random.rand(100, 1)
y_quad = 2 * X_quad**2 + 3 * X_quad + 5 + np.random.randn(100, 1)

# Set hyperparameters for the quadratic model
learning_rate = 0.1
epochs = 1000

# Fit the quadratic model
optimal_params_quad = gradient_descent(X_quad, y_quad, learning_rate, epochs)
print("Optimal Parameters for the Quadratic Model (a, b, c):", optimal_params_quad.flatten())

# Get the optimal parameters for the quadratic model
a, b, c = optimal_params_quad

# Generate points on the x-axis for plotting the quadratic curve
x_plot = np.linspace(np.min(X_quad), np.max(X_quad), 100)

# Calculate the corresponding y values using the quadratic model equation
y_plot = np.dot(np.c_[np.ones_like(x_plot), x_plot, x_plot**2], optimal_params_quad)

# Plot the data points
plt.scatter(X_quad, y_quad, label='Data points')

# Plot the quadratic curve
plt.plot(x_plot, y_plot, color='red', label='Quadratic Model')

plt.xlabel('X')
plt.ylabel('y')
plt.legend()
plt.title('Quadratic Model Fit')
plt.grid(True)
plt.show()
