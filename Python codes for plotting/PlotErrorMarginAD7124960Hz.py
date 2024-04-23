import matplotlib.pyplot as plt
import numpy as np

# Corrected sample measurements for 4 sensors, each measured 5 times at each weight
measurements = {
    'Load cell': [
        [-120,44,-16,25,98],  # 0kg measurements
        [-297,462,149,212,-24],  # 5kg measurements
        [-390,108,-263,-23,169],  # 10kg measurements
        [-499,158,9,-210,95],  # 20kg measurements
        [-310,19,-158,-6,4], #28kg measurements
        [-252,-6,183,5,-129] # 32kg measurements
    ]
}

weights = [0, 5000, 10000, 20000, 28000, 32000]
colors = ['red']

plt.figure(figsize=(10, 6))
for sensor, color in zip(measurements.keys(), colors):
    all_weights = []  # This will be your x-axis values
    all_measurements = []  # This will be your y-axis values
    for weight_index, weight in enumerate(weights):
        if weight_index < len(measurements[sensor]):  # Check to prevent 'list index out of range'
            # Extend the lists with the current weight and its corresponding measurements
            all_weights.extend([weight] * len(measurements[sensor][weight_index]))
            all_measurements.extend(measurements[sensor][weight_index])
    
    # Now plot with weights on x-axis and measurement values on y-axis
    plt.scatter(all_weights, all_measurements, color=color, label=sensor)

plt.xlabel('Weight (gram)')
plt.ylabel('Error margin (gram)')
plt.title('Load cells error margin at 960Hz')
plt.xticks(weights)  # Ensure x-ticks match the weights
plt.legend()
plt.grid(True)
plt.show()
