import matplotlib.pyplot as plt
import numpy as np

# Corrected sample measurements for 4 sensors, each measured 5 times at each weight
measurements = {
    'Lastcell 1': [
        [21,30,33,26,29],  # 0kg measurements
        [-11,-8,-20,-10,-19],  # 5kg measurements
        [-1,7,1,0,-4],  # 10kg measurements
        [-92,-84,-83,-77,-87],  # 20kg measurements
        [-29,-25,-37,-26,-40], #28kg measurements
        [-64,-62,-71,-76,-68] # 32kg measurements
    ],
    'Lastcell 2': [
        [15,22,23,25,18],  # 0kg measurements
        [8,16,19,17,10],  # 5kg measurements
        [-70,-77,-68,-72,-66],  # 10kg measurements
        [-67,-75,-74,-74,-82],  # 20kg measurements
        [-44,-32,-36,-50,-47],    # 28kg measurements
        [-27,-33,-26,-25,-22]  # 32kg measurements
        
    ],
    'Lastcell 3': [  
        [18,28,25,23,22],  # 0kg measurements
        [88,82,79,84,77],  # 5kg measurements
        [-41,-36,-34,-31,-35],  # 10kg measurements
        [-25,-9,-4,-16,-17],  # 20kg measurements
        [90,88,99,104,111], # 28kg measurements
        [-29,-26,-34,-19,-23]  # 32kg measurements
    ],
    'Lastcell 4': [  
        [9,13,3,10,0],  # 0kg measurements
        [-10,1,-1,4,-4],  # 5kg measurements
        [-153,-143,-158,-150,-146],  # 10kg measurements
        [-203,-196,-191,-198,-206],  # 20kg measurements
        [-167,-180,-163,-162,-178],  # 28kg measurements
        [-154,-149,-155,-168,-160]  # 32kg measurements
    ]
}

weights = [0, 5000, 10000, 20000, 28000, 32000]
colors = ['red', 'green', 'blue', 'orange']

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
plt.title('Load cells error margin')
plt.xticks(weights)  # Ensure x-ticks match the weights
plt.legend()
plt.grid(True)
plt.show()
