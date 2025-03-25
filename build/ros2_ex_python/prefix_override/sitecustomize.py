import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/Projects/ros2_workspace/ros2_starting-project/install/ros2_ex_python'
