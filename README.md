# rosserial-mbed-lib

This repository is a slightly modified content of `ros_lib` directory created accordingly to [rosserial MBED Setup](http://wiki.ros.org/rosserial_mbed/Tutorials/rosserial_mbed%20Setup) tutorial from official ros documentation. Modification involves changing default Serial pins used by library to fit CORE2 RPI connector. You can adjust them in `mbed_app.json` under "target_overrides" tag.

Condensed, step by step recipe:
1. `$ mkdir -p ~/ros_workspace/src && cd ros_workspace/src && catkin_init_workspace`
2. `$ cd ~/ros_workspace/src && git clone https://github.com/ros-drivers/rosserial`
3. `$ cd ~/ros_workspace && catkin_make` 
4. `$ source devel/setup.bash`
5. `$ rosrun rosserial_mbed make_libraries.py ~/workspace/ros/lib`




