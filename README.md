# Low-Cost Force Measurement System Using Wii Balance Board

## Introduction
Welcome to the GitHub repository for the thesis "Analysis and Validation of Low-Cost Force Measurement Systems," completed as part of an Electrical Engineering degree from the Royal Institute of Technology (KTH), Stockholm. This project aims to retrofit a Wii Balance Board with modern electronics to create an affordable, accurate force measurement device suitable for both sports and medical applications.

## Project Overview
High costs and immobility limit the accessibility of traditional force measurement platforms. This project transforms the Wii Balance Board into a viable alternative by integrating advanced, yet cost-effective, electronics, providing a portable and affordable solution.

## Repository Contents
This repository includes the following components:

### Thesis Document
- [**Analysis and Validation of Low-Cost Force Measurement Systems (Thesis Document)**](https://www.diva-portal.org/smash/record.jsf?dswid=5604&pid=diva2%3A1838323&c=1&searchType=SIMPLE&language=sv&query=rahand+mustafa&af=%5B%5D&aq=%5B%5B%5D%5D&aq2=%5B%5B%5D%5D&aqe=%5B%5D&noOfRows=50&sortOrder=author_sort_asc&sortOrder2=title_sort_asc&onlyFullText=false&sf=all) - Full documentation of the research, including methodology, results, and discussion, available online at DIVA Portal.


### Arduino Sketches
- `AD7124-8FOUR.ino` - Manages four load cells with AD7124-8 ADC for high-frequency force measurements.
- `AD7124-8SINGLE.ino` - Manages a single load cell setup with AD7124-8 ADC, ideal for individual tests.
- `HX711ALLFOUR.ino` - Configures four load cells using HX711 ADC, suited for lower-frequency measurements.
- `HX711SINGLE.ino` - Configures a single load cell with HX711 ADC for simple, cost-effective measurements. This sketch integrates with the Blynk app for real-time data visualization.
- `CalibrateHX711.ino` - Provides an automated calibration script for HX711 load cells.

### Python Scripts
- `PlotErrorMarginAD712410Hz.py` - Analyzes and visualizes error margins at 10Hz with AD7124-8.
- `PlotErrorMarginAD7124960Hz.py` - Analyzes and visualizes error margins at 960Hz with AD7124-8.
- `PlotErrorMarginHX711.py` - Analyzes and visualizes error margins for HX711.

## Calibration Process

### AD7124 Calibration
The AD7124 requires manual calibration to ensure accuracy. This involves placing known weights on the load cells to determine the calibration factors. Users must perform these steps:

1. **Setup Known Weights**: Place known weights on each load cell. It's recommended to use weights that span the typical range of force you expect to measure.
2. **Record Outputs**: Note the raw output from the AD7124 for each weight.
3. **Calculate Calibration Factors**: Use the known weights and recorded outputs to calculate the calibration factors. This usually involves fitting a linear regression model where the output is a function of the weight.
4. **Adjust Calibration Factors in Code**: Enter these calibration factors into the respective Arduino sketches (`AD7124-8FOUR.ino` and `AD7124-8SINGLE.ino`) to adjust the output readings accordingly.

### HX711 Calibration
The `CalibrateHX711.ino` sketch simplifies the calibration process for the HX711 load cells. This script automatically calculates the calibration factor when a known weight is placed on the load cells. Steps to use this script are as follows:

1. **Upload the Calibration Sketch**: Load the `CalibrateHX711.ino` to your microcontroller connected to the HX711 and load cells.
2. **Set Known Weight**: Place a known weight on the load cell as instructed by the script.
3. **Run the Calibration**: The script will output the calibration factor.
4. **Update Main Sketches**: Input this calibration factor into the `HX711SINGLE.ino` and `HX711ALLFOUR.ino` sketches to ensure accurate weight measurements.

## Installation
Clone this repository and set up your development environment as follows:
```bash
git clone https://github.com/DeluxeRaho/DIY-Force-Plate-with-Wii-Balance-Board.git
```
- Install Arduino IDE and Python 3.x from their respective official websites.

## Usage

### Preparation of the Wii Balance Board
Before using the software provided in this repository, you need to prepare your Wii Balance Board:

1. **Acquire a Wii Balance Board**: These are readily available second-hand online or at many gaming or electronics stores.
2. **Open the Balance Board**: Carefully disassemble the Wii Balance Board. Instructions for this can typically be found online or in the user manual.
3. **Remove Unnecessary Components**: Inside the Balance Board, you will find various electronics and wiring. Remove everything except for the load cells and their four connecting wires.
4. **Identify Load Cell Wires**: Each load cell has four wires. These are usually colored red, black, white, and green or blue. The colors may vary depending on the manufacturer.

### Connecting the Load Cells to an ADC
After preparing the Wii Balance Board, you'll need to connect the load cells to an Analog-to-Digital Converter (ADC). Detailed circuit diagrams are provided in each project folder (`HX711` and `AD7124-8`) for both single-load-cell (`SINGLE`) and four-load-cell (`ALLFOUR`) configurations.

1. **Choose an ADC**: Depending on your precision and frequency requirements, select either the HX711 or AD7124-8. The HX711 is suitable for lower-frequency measurements, whereas the AD7124-8 is better for high-frequency applications.
2. **Wiring Load Cells to ADC**: Follow the circuit diagrams provided in the respective folder to correctly wire the load cells to your chosen ADC.
3. **Calibration**: Before taking measurements, calibrate the load cells using the calibration steps provided in the [Calibration Process](#calibration-process) section.

### Connecting ADC to a Microcontroller
To process and transmit the data from the load cells:

1. **Select a Microcontroller**: An ESP32 is recommended due to its built-in Wi-Fi capabilities, making it suitable for projects involving real-time data monitoring via the Blynk app.
2. **Connect the ADC to the Microcontroller**: Use the circuit diagrams provided to connect your ADC to the ESP32 or other suitable microcontrollers.
3. **Upload Arduino Sketch**: Depending on your configuration (single or four load cells), upload the appropriate Arduino sketch (`HX711SINGLE.ino`, `HX711ALLFOUR.ino`, `AD7124-8SINGLE.ino`, or `AD7124-8FOUR.ino`) to the microcontroller.

### Running the System
Once everything is connected and the software is uploaded:
- Power on the system.
- Use the Blynk app or another visualization tool to monitor the force measurements in real-time.
- Regularly recalibrate and maintain the system to ensure accuracy and reliability.

By following these detailed setup instructions, users will be able to transform a standard Wii Balance Board into a high-functioning, low-cost force measurement system suitable for a wide range of applications.

### How to Contribute
Contributors are welcome to fork the repository, commit modifications to a new branch, and submit a pull request for review.

### Licensing
This project is released under the MIT License. See the LICENSE file for full details.
