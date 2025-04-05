import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/raz/tehiru/Tehiru-Homework-assignment/drone_ws/install/liftoff_telemetry'
