
import rclpy
from rclpy.node import Node
from evdev import UInput, AbsInfo, ecodes as e
from sensor_msgs.msg import Joy

class VirtualControllerNode(Node):
    def __init__(self):
        super().__init__('virtual_controller_node')
        self.subscription = self.create_subscription(
            Joy,
            'joy',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        
        self.ui = UInput(
            {
                e.EV_ABS: [
                    (e.ABS_X, AbsInfo(value=0, min=-32768, max=32767, fuzz=0, flat=0, resolution=0)),   # Left joystick X
                    (e.ABS_Y, AbsInfo(value=0, min=-32768, max=32767, fuzz=0, flat=0, resolution=0)),   # Left joystick Y
                    (e.ABS_RX, AbsInfo(value=0, min=-32768, max=32767, fuzz=0, flat=0, resolution=0)),  # Right joystick X
                    (e.ABS_RY, AbsInfo(value=0, min=-32768, max=32767, fuzz=0, flat=0, resolution=0)),  # Right joystick Y
                    (e.ABS_Z, AbsInfo(value=0, min=-32768, max=32767, fuzz=0, flat=0, resolution=0)),   # Left trigger
                    (e.ABS_RZ, AbsInfo(value=0, min=-32768, max=32767, fuzz=0, flat=0, resolution=0)),  # Right trigger
                    (e.ABS_HAT0X, AbsInfo(value=0, min=-1, max=1, fuzz=0, flat=0, resolution=0)),       # D-pad X
                    (e.ABS_HAT0Y, AbsInfo(value=0, min=-1, max=1, fuzz=0, flat=0, resolution=0)),       # D-pad Y
                ],
                e.EV_KEY: [
                    e.BTN_A,
                    e.BTN_B,
                    e.BTN_X,
                    e.BTN_Y,
                    e.BTN_TL,
                    e.BTN_TR,
                    e.BTN_SELECT,
                    e.BTN_START,
                    e.BTN_THUMBL,
                    e.BTN_THUMBR,
                    e.BTN_MODE,
                ],
                e.EV_FF: [],  # Force feedback (optional)
            },
            # vendor=0x045e,
            # product=0x028e,
            # version=0x0110,
            bustype=e.BUS_USB,
            name='Xbox Virtual Controller',
        )
        
        self.last_axes = [0] * 8
        self.last_buttons = [0] * 11

    def listener_callback(self, msg):
        axes = msg.axes
        buttons = msg.buttons

        # Map joystick inputs to virtual controller inputs
        x = int(axes[0] * -32767)
        y = int(axes[1] * -32767)
        rx = int(axes[3] * -32767)
        ry = int(axes[4] * -32767)
        z = int(axes[2] * -32767)
        rz = int(axes[5] * -32767)
        hat0x = int(axes[6] * -1.0)
        hat0y = int(axes[7] * -1.0)

        button_states = {
            e.BTN_A: buttons[0],
            e.BTN_B: buttons[1],
            e.BTN_X: buttons[2],
            e.BTN_Y: buttons[3],
            e.BTN_TL: buttons[4],
            e.BTN_TR: buttons[5],
            e.BTN_SELECT: buttons[6],
            e.BTN_START: buttons[7],
            e.BTN_THUMBL: buttons[8],
            e.BTN_THUMBR: buttons[9],
            e.BTN_MODE: buttons[10],
        }
        
        self.send_input(x, y, rx, ry, z, rz, hat0x, hat0y, button_states)
        self.last_axes = [x, y, rx, ry, z, rz, hat0x, hat0y]
        self.last_buttons = buttons

    def send_input(self, x, y, rx, ry, z, rz, hat0x, hat0y, buttons):
        self.ui.write(e.EV_ABS, e.ABS_X, x)
        self.ui.write(e.EV_ABS, e.ABS_Y, y)
        self.ui.write(e.EV_ABS, e.ABS_RX, rx)
        self.ui.write(e.EV_ABS, e.ABS_RY, ry)
        self.ui.write(e.EV_ABS, e.ABS_Z, z)
        self.ui.write(e.EV_ABS, e.ABS_RZ, rz)
        self.ui.write(e.EV_ABS, e.ABS_HAT0X, hat0x)
        self.ui.write(e.EV_ABS, e.ABS_HAT0Y, hat0y)
        for button, state in buttons.items():
            self.ui.write(e.EV_KEY, button, state)
        self.ui.syn()

def main(args=None):
    rclpy.init(args=args)
    node = VirtualControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()