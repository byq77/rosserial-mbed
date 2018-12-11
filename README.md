# rosserial-mbed-lib

This repository is a slightly modified content of `ros_lib` directory created accordingly to [rosserial MBED Setup](http://wiki.ros.org/rosserial_mbed/Tutorials/rosserial_mbed%20Setup) tutorial from official ros documentation.

Condensed, step by step recipe:
1. `$ mkdir -p ~/ros_workspace/src && cd ros_workspace/src && catkin_init_workspace`
2. `$ cd ~/ros_workspace/src && git clone https://github.com/ros-drivers/rosserial`
3. `$ cd ~/ros_workspace && catkin_make` 
4. `$ source devel/setup.bash`
5. `$ rosrun rosserial_mbed make_libraries.py ~/workspace/ros/lib`

This library is compatible with Mbed CLI tools. You can change default Serial pins and baudrate used by rosserial in `mbed_app.json`. 

Example:

```json
{
    "target_overrides":{
        "*": {
            "mbed-rosserial-lib.tx_pin": "MY_TX_PIN",
            "mbed-rosserial-lib.rx_pin": "MY_RX_PIN",
            "mbed-rosserial-lib.baudrate": "230400"
        }
    }
}
```


