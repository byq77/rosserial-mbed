#ifndef ROS_MBED_HARDWARE_H_
#define ROS_MBED_HARDWARE_H_

#include "mbed.h"
#include "UARTSerial.h"

class MbedHardware
{
public:
    MbedHardware(PinName tx, PinName rx, long baud = ROSSERIAL_BAUDRATE)
        : iostream(tx, rx, baud)
    {}

    MbedHardware()
        : iostream(ROSSERIAL_TX, ROSSERIAL_RX, ROSSERIAL_BAUDRATE)
    {}

    void setBaud(long baud)
    {
        this->iostream.set_baud(baud);
    }

    void init()
    {
#if ROSSERIAL_RTOS_KERNEL_MS_TICK == 0
        t.start();
#endif
        iostream.set_flow_control(mbed::SerialBase::Disabled);
    }

    int read(uint8_t* data, int length){
        iostream.set_blocking(false);
        int res = iostream.read(data,length);
        iostream.set_blocking(true);
        return res > 0 ? res : -1;
    };

    void write(uint8_t* data, int length) {
        iostream.write(data,length);
    }

    unsigned long time()
    {
#if ROSSERIAL_RTOS_KERNEL_MS_TICK
      return Kernel::get_ms_count();
#else
      return t.read_ms();
#endif
    }

  protected:
    UARTSerial iostream;
#if ROSSERIAL_RTOS_KERNEL_MS_TICK == 0
    Timer t;
#endif
};


#endif /* ROS_MBED_HARDWARE_H_ */
