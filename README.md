**Smart Plant Monitor with Adaptive Learning**

**Overview**
A lightweight embedded system that simulates intelligent plant monitoring using binary search-based sensor classification and adaptive pattern recognition—no heavy ML needed.

**Features**
1) Real-Time Monitoring of moisture, temperature & light for multiple plants- as of now the data is simulated.

2) Efficient Threshold Classification using binary search (8-bit & 16-bit simulated sesnor datas)

3) Adaptive Learning: Matches recent patterns over a time window to detect current stress/pattern of the plant.

4) Trigger-Based Notifications when plant conditions are stressed or reached a threshold during a time window.

**Key Concepts Used**
1)Binary Search Algorithm to find the sensor range efficiently.

2)Sliding Time Window Logic for tracking trends in past records.

3)Pattern Occurrence Tracking to trigger alerts only on repeated stress.

4)Custom Sensor Mapping per plant, supporting real-time dynamic decisions.

5)Simulation-Driven Testing for repeatable validation without real sensors.
   
**Modules Overview**
1)main.c: System controller & logger

2)sensor_data_classifier.c: Binary search logic for sensor range mapping.

3)plant_profile.c: Custom threshold database for each plant.

4)time_stamped_state_data.c: Stores & compares recent history.

5)notification.c: Alerts based on adaptive pattern occurrence.

6)Plant_Sensor_Data_Simulate.c: Sensor data simulation.

**Hardware Requirements:**
1) STM32 / Infineon / Arduino / Any MCU board

**Software Requirements:**
1)Language: C
2)IDE: Embedded IDE (STM32CubeIDE, Keil, etc.)
3)Version control :Git
