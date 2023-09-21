import matplotlib.pyplot as plt
file_path="/home/zq/C-programe-practise/Driveless_PNC/Project2 Stanley ROS1/src/stanley_control/data/referenceline_2d_mod.txt"
with open(file_path,'r') as file:
    lines=file.readlines()
x_values=[]
y_values=[]
for line in lines:
    x,y=line.strip().split()
    x_values.append(float(x))
    y_values.append(float(y))
# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(x_values, y_values, '-o', label='Trajectory')
plt.title('Trajectory Visualization')
plt.xlabel('X values')
plt.ylabel('Y values')
plt.legend()
plt.grid(True)
plt.show()


