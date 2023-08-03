import numpy as np
import matplotlib.pyplot as plt

# True polynomial model function: y = a*x^3 + b*x^2 + c*x + d
def true_model(x, a, b, c, d):
    return a * x**3 + b * x**2 + c * x + d

# Generate noisy polynomial data
np.random.seed(0)
x = np.linspace(-2, 2, 50)
a_true, b_true, c_true, d_true = 1.5, -2.5, 2.0, 3.0
y_true = true_model(x, a_true, b_true, c_true, d_true)
y_noisy = y_true + 5 * np.random.randn(len(x))

# Normalize the data in the range [0, 1]
x_normalized = (x - x.min()) / (x.max() - x.min())
y_normalized = (y_noisy - y_noisy.min()) / (y_noisy.max() - y_noisy.min())

# Model function: y = a*x^3 + b*x^2 + c*x + d for parameter estimation
def model_func(params, x):
    a, b, c, d = params
    return a * x**3 + b * x**2 + c * x + d

# Residual function (difference between model and actual data)
def residual_func(params, x, y):
    return y - model_func(params, x)

# Jacobian of the residual function with respect to parameters
def jacobian_func(params, x):
    a, b, c, d = params
    return np.array([
        -x**3, -x**2, -x, -np.ones_like(x)
    ]).T

# Gauss-Newton method to update parameters
def gauss_newton(x, y, initial_params, max_iterations=100, tol=1e-6):
    params = initial_params.copy()
    for i in range(max_iterations):
        residuals = residual_func(params, x, y)
        jacobian = jacobian_func(params, x)
        update = np.linalg.inv(jacobian.T @ jacobian) @ jacobian.T @ residuals
        params += update
        if np.linalg.norm(update) < tol:
            break
    return params

# Set initial guess for parameters (a, b, c, d)
initial_params = [1.0, 1.0, 1.0, 1.0]

# Fit the model using Gauss-Newton method
optimal_params = gauss_newton(x_normalized, y_normalized, initial_params)

# Generate the fitted curve using the optimal parameters
y_fitted = model_func(optimal_params, x_normalized)

# Rescale the fitted curve to the original data range
y_fitted_rescaled = y_fitted * (y_noisy.max() - y_noisy.min()) + y_noisy.min()

# Plot the true polynomial model, noisy data, and the fitted curve
plt.plot(x, y_true, 'g-', label='True Polynomial Model')
plt.plot(x, y_noisy, 'bo', label='Noisy Data')
plt.plot(x, y_fitted_rescaled, 'r-', label='Fitted Model')
plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title('Curve Fitting with Gauss-Newton Method')
plt.grid(True)
plt.show()

print("Optimal Parameters (a, b, c, d):", optimal_params)
