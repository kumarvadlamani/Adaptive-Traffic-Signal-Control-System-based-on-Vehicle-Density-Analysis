import pandas as pd
import serial
import time

# Connect to Arduino
arduino = serial.Serial('COM4', 9600)  # Adjust COM port if needed
time.sleep(2)  # Let Arduino initialize

# Load and clean the CSV
df = pd.read_csv(r"C:\Users\pavan\Downloads\priority_signals.csv")
df.columns = df.columns.str.strip()  # Remove any extra spaces from headers

# Check if columns exist
print("Columns:", df.columns)

road_map = {
    "North Road": b'N',
    "East Road": b'E',
    "West Road": b'W',
    "South Road": b'S'
}

for index, row in df.iterrows():
    direction = row["Highest Traffic Road"]
    count = int(row["Vehicle Count"])

    if direction in road_map and count > 0:
        arduino.write(road_map[direction])
        print(f"Sent {direction} → LED ON for {count} seconds")
        time.sleep(count)
    else:
        print(f"Row {index + 1}: Invalid direction or 0 vehicles")

arduino.close()
