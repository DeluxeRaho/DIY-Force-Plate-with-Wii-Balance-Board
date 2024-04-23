import matplotlib.pyplot as plt
import numpy as np

# Corrected sample measurements for 4 sensors, each measured 5 times at each weight
measurements = {
    'Load cell 1': [
        [2,0,8,6,3],  # 0kg measurements
        [133, 127, 134, 143, 122],  # 5kg measurements
        [-36, -46, -35, -43, -39],  # 10kg measurements
        [-18, -4, 3, 32, 1],  # 20kg measurements
        [201, 182, 178, 190, 186], #28kg measurements
        [247, 246, 236, 262, 238] # 32kg measurements
    ],
    'Load cell 2': [
        [3, 7, 1, 0, 10],  # 0kg measurements
        [31, 44, 47, 30, 50],  # 5kg measurements
        [-51, -55, -47, -61, -49],  # 10kg measurements
        [-9, -19, 37, -6, 4],  # 20kg measurements
        [-13, -29, -17, -25, -19],    # 28kg measurements
        [-44, -47, -53, -56, -23]  # 32kg measurements
        
    ],
    'Load cell 3': [  
        [3, 1, 10, 4, 2],  # 0kg measurements
        [72, 77, 79, 66, 83],  # 5kg measurements
        [-134, -136, -146, -142, -130],  # 10kg measurements
        [-89, -105, -106, -96, -133],  # 20kg measurements
        [-102, -101, -96, -93, -108], # 28kg measurements
        [1, -28, 18, -1, -14]  # 32kg measurements
    ],
    'Load cell 4': [  
        [2, 6, 4, 7, 11],  # 0kg measurements
        [22, 31, 20, 17, 27],  # 5kg measurements
        [-1, 1, 1, -4, -3],  # 10kg measurements
        [-100, -119, -93, -123, -116],  # 20kg measurements
        [130, 143, 139, 141, 154],  # 28kg measurements
        [-95, -82, -73, -91, -64]  # 32kg measurements
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
