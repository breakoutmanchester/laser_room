# Lasers & Sensors Assignment


|  Laser Num | Laser Pin  | Sensor Pin  |
| ------------ | ------------ | ------------ |
|  1 | 2  | 34  |
| 2  | 3  | 30  |
| 3  | 4  |  40 |
| 4  |  5 |  37 |
| 5 | 6  |  35 |
| 6  | 7  | 25  |
|  7 | 8  |  38 |
| 8  |  9 |  41 |
| 9  |  10 | 36  |
| 10  | 11  |  26 |
|11|  12 | 28  |
|  12 |  13 | 27  |
|  13 |  14 | 39  |
|14|  15 | 29  |
| 15  |  16 | 33  |
| 16  |  22 | 31  |
| 17  |  23 | 42  |
|  18 |  24 | 32  |

1.  **Laser Pin** = Pin on the Arduino the laser are attached to
2.  **Laser Num** = Each laser is assigned a number
3.  **Sensor Pin** = Pin on the Arduino the sensor are attached to

------------
### Troubleshooting

## Testing Sensors and Lasers

When testing the sensors you should use the 'sketch_may31a.ino' file and run this with the 'sensor_test.py' python code. The Python program will display all the lasers that aren't alligned correctly. If no problems occur, text displaying 'All good :)' will appear. However, you do not need the Python file to test the Lasers, instead just run the Arduino code as normal and use Serial to see the output.

------------

## Configuration & Setup

Approximately half of the Lasers and half of the sensors are powered by the laptop and a external power supply (5V) due to voltage issue which caused the relays to 'stick' in turn causing the lasers to stay ON when they shouldn't. Green lasers need to be powered by an external power supply not the Arduino if there is quite a bit of load on the Arduino already because they draw much more current than the red lasers.
