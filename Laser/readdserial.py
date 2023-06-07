import serial


_serial = serial.Serial(port='COM5', baudrate=9600)

while True:
    line = str(_serial.readline())

    for x in ['b','\\r', '\\n']:
       line = line.replace(x, "")
    if line == "fdf":
        print("yess")
    print(line)