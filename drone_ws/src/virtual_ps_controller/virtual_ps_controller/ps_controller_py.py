import rclpy
from rclpy.node import Node
from evdev import UInput, AbsInfo, ecodes as e
from sensor_msgs.msg import Joy

class PS4ControllerNode(Node):
    def __init__(self):
        super().__init__('ps_controller_node')
        self.subscription = self.create_subscription(
            Joy,
            'joy',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        
        # PS4 controller setup
        self.ui = UInput(
            {
                e.EV_ABS: [
                    (e.ABS_X, AbsInfo(value=0, min=-32768, max=32767, fuzz=0, flat=0, resolution=0)),   # Left joystick X
                    (e.ABS_Y, AbsInfo(value=0, min=-32768, max=32767, fuzz=0, flat=0, resolution=0)),   # Left joystick Y
                    (e.ABS_RX, AbsInfo(value=0, min=-32768, max=32767, fuzz=0, flat=0, resolution=0)),  # Right joystick X
                    (e.ABS_RY, AbsInfo(value=0, min=-32768, max=32767, fuzz=0, flat=0, resolution=0)),  # Right joystick Y
                    (e.ABS_Z, AbsInfo(value=0, min=0, max=255, fuzz=0, flat=0, resolution=0)),          # L2 trigger
                    (e.ABS_RZ, AbsInfo(value=0, min=0, max=255, fuzz=0, flat=0, resolution=0)),         # R2 trigger
                    (e.ABS_HAT0X, AbsInfo(value=0, min=-1, max=1, fuzz=0, flat=0, resolution=0)),       # D-pad X
                    (e.ABS_HAT0Y, AbsInfo(value=0, min=-1, max=1, fuzz=0, flat=0, resolution=0)),       # D-pad Y
                ],
                e.EV_KEY: [
                    e.BTN_SOUTH,    # Cross
                    e.BTN_EAST,     # Circle
                    e.BTN_NORTH,    # Triangle
                    e.BTN_WEST,     # Square
                    e.BTN_TL,       # L1
                    e.BTN_TR,       # R1
                    e.BTN_TL2,      # L2 as button
                    e.BTN_TR2,      # R2 as button
                    e.BTN_SELECT,   # Share
                    e.BTN_START,    # Options
                    e.BTN_THUMBL,   # L3
                    e.BTN_THUMBR,   # R3
                    e.BTN_MODE,     # PS button
                    e.BTN_TRIGGER_HAPPY1, # Touchpad button
                ],
            },
            name='Sony DualShock 4 Controller',
            vendor=0x054c,  # Sony vendor ID
            product=0x05c4, # DualShock 4 product ID
            version=0x0111,
            bustype=e.BUS_USB,
        )
        
        self.get_logger().info('Virtual PS4 controller created')
        self.last_axes = [0] * 8
        self.last_buttons = [0] * 14

    def listener_callback(self, msg):
        axes = msg.axes
        buttons = msg.buttons

        # Map joystick inputs to PS4 controller inputs
        # Note: We invert axes where necessary to match PS4 behavior
        x = int(axes[0] * 32767)               # Left stick X
        y = int(axes[1] * -32767)              # Left stick Y (inverted)
        rx = int(axes[3] * 32767)              # Right stick X
        ry = int(axes[4] * -32767)             # Right stick Y (inverted)
        
        # L2 and R2 triggers (0-255 range)
        l2_value = int((axes[2] + 1) * 127.5)  # Convert -1 to 1 range to 0-255
        r2_value = int((axes[5] + 1) * 127.5)  # Convert -1 to 1 range to 0-255
        
        hat0x = int(axes[6])                   # D-pad X
        hat0y = int(axes[7] * -1)              # D-pad Y (inverted)

        # Map buttons (PS4 layout)
        button_states = {
            e.BTN_SOUTH: buttons[0],     # Cross
            e.BTN_EAST: buttons[1],      # Circle
            e.BTN_NORTH: buttons[2],     # Triangle 
            e.BTN_WEST: buttons[3],      # Square
            e.BTN_TL: buttons[4],        # L1
            e.BTN_TR: buttons[5],        # R1
            e.BTN_TL2: 1 if l2_value > 128 else 0,  # L2 button
            e.BTN_TR2: 1 if r2_value > 128 else 0,  # R2 button
            e.BTN_SELECT: buttons[6],    # Share
            e.BTN_START: buttons[7],     # Options
            e.BTN_THUMBL: buttons[8],    # L3
            e.BTN_THUMBR: buttons[9],    # R3
            e.BTN_MODE: buttons[10],     # PS button
            e.BTN_TRIGGER_HAPPY1: buttons[11] if len(buttons) > 11 else 0,  # Touchpad
        }
        
        self.send_input(x, y, rx, ry, l2_value, r2_value, hat0x, hat0y, button_states)

    def send_input(self, x, y, rx, ry, l2, r2, hat0x, hat0y, button_states):
        # Send joystick events if changed
        self.ui.write(e.EV_ABS, e.ABS_X, x)
        self.ui.write(e.EV_ABS, e.ABS_Y, y)
        self.ui.write(e.EV_ABS, e.ABS_RX, rx)
        self.ui.write(e.EV_ABS, e.ABS_RY, ry)
        self.ui.write(e.EV_ABS, e.ABS_Z, l2)
        self.ui.write(e.EV_ABS, e.ABS_RZ, r2)
        self.ui.write(e.EV_ABS, e.ABS_HAT0X, hat0x)
        self.ui.write(e.EV_ABS, e.ABS_HAT0Y, hat0y)
        
        # Send button events
        for btn_code, state in button_states.items():
            self.ui.write(e.EV_KEY, btn_code, state)
        
        # Synchronize events
        self.ui.syn()

def main(args=None):
    rclpy.init(args=args)
    node = PS4ControllerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.ui.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()