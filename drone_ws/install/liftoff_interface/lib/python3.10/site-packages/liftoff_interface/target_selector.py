import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
import tkinter as tk

class TargetSelector(Node):
    def __init__(self):
        super().__init__('target_selector')
        self.target_publisher = self.create_publisher(Point, 'target_coordinates', 10)
        self.init_ui()

    def init_ui(self):
        self.root = tk.Tk()
        self.root.title("Target Selector")
        self.canvas_width = 800
        self.canvas_height = 600
        self.canvas = tk.Canvas(self.root, width=self.canvas_width, height=self.canvas_height, bg="white")
        self.canvas.pack()

        # Draw gridlines for better orientation
        self.draw_grid()

        # Bind mouse click event
        self.canvas.bind("<Button-1>", self.on_click)

        # Start the Tkinter main loop
        self.root.mainloop()

    def draw_grid(self):
        """Draw gridlines on the canvas."""
        grid_spacing = 50  # Spacing between gridlines in pixels
        for x in range(0, self.canvas_width, grid_spacing):
            self.canvas.create_line(x, 0, x, self.canvas_height, fill="lightgray")
        for y in range(0, self.canvas_height, grid_spacing):
            self.canvas.create_line(0, y, self.canvas_width, y, fill="lightgray")

    def on_click(self, event):
        """Handle mouse click events."""
        # Clear previous markers
        self.canvas.delete("marker")

        # Draw a marker at the clicked position
        marker_radius = 5
        self.canvas.create_oval(
            event.x - marker_radius, event.y - marker_radius,
            event.x + marker_radius, event.y + marker_radius,
            fill="red", tags="marker"
        )

        # Convert screen coordinates to world coordinates (example logic)
        world_x = event.x * 0.01  # Scale factor for conversion
        world_y = event.y * 0.01
        world_z = 0.0  # Assuming a flat plane for simplicity

        # Publish the target coordinates
        target_msg = Point()
        target_msg.x = world_x
        target_msg.y = world_y
        target_msg.z = world_z
        self.target_publisher.publish(target_msg)

        self.get_logger().info(f"Target selected: ({world_x:.2f}, {world_y:.2f}, {world_z:.2f})")

def main(args=None):
    rclpy.init(args=args)
    node = TargetSelector()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()