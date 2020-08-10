"""
This code is to be run AFTER the Arduino is set up and running serial_led_on_off.ino
Be sure that the Serial monitor is available as well.
"""

import serial
#import getch


class _Getch:
    """
    Getch is used to read one character at a time
    """
    def __init__(self):
        import msvcrt

    def __call__(self):
        import msvcrt
        return msvcrt.getch()


def main():
    ser = serial.Serial('COM3', baudrate=9600, timeout=1)
    while True:
        import msvcrt
        char = ord(msvcrt.getche())  # convert the char to its numeral value
        if char == 13:  # char == ENTER
            ser.write(b'H')
        elif char == 27:  # char == ESC
            break

    ser.close()

    return 0


if __name__ == '__main__':
    main()