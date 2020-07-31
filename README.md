# rosserial-mbed

Version: v1.1.1

This repository is a modified version of `ros_lib` directory created accordingly to [rosserial MBED Setup](http://wiki.ros.org/rosserial_mbed/Tutorials/rosserial_mbed%20Setup) tutorial from official ros documentation.

Condensed, step by step recipe:
1. `$ mkdir -p ~/ros_workspace/src && cd ros_workspace/src && catkin_init_workspace`
2. `$ cd ~/ros_workspace/src && git clone https://github.com/ros-drivers/rosserial`
3. `$ cd ~/ros_workspace && catkin_make` 
4. `$ source devel/setup.bash`
5. `$ rosrun rosserial_mbed make_libraries.py ~/workspace/ros/lib`

This library is compatible with Mbed CLI tools. You can change default Serial pins and baudrate used by rosserial in `mbed_app.json`. 

**Available options**:

* `"rosserial-mbed.tx_pin"` - serial tx pin
* `"rosserial-mbed.rx_pin"` - serial rx pin
* `"rosserial-mbed.baudrate"` - serial baudrate
* `"rosserial-mbed.in_buffer_size"` - node input buffer size (default: 512)
* `"rosserial-mbed.out_buffer_size"` - node output buffer size (default: 512) 
* `"rosserial-mbed.rtos_kernel_ms_tick"` - use kernel_ms_tick instead Ticker 

`rosserial-mbed` uses `UARTSerial` library that has following configuration options:
* `"drivers.uart-serial-rxbuf-size"` - input buffer,
* `"drivers.uart-serial-txbuf-size"`- output buffer,

**Example:**

```json
{
    "target_overrides":{
        "*": {
            "rosserial-mbed.tx_pin": "MY_TX_PIN",
            "rosserial-mbed.rx_pin": "MY_RX_PIN",
            "rosserial-mbed.baudrate": 230400,
            "drivers.uart-serial-rxbuf-size": 512,
            "drivers.uart-serial-txbuf-size": 512,
            "rosserial-mbed.rtos_kernel_ms_tick": 1
        }
    }
}
```

To add this library to your project just run `mbed add https://github.com/byq77/rosserial-mbed.git` in your project's `lib` directory.
