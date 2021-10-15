#ifndef ROS_MBED_HARDWARE_H_
#define ROS_MBED_HARDWARE_H_

#include "mbed.h"
#include "UARTSerial.h"

#ifndef ROSSERIAL_TX
#   define ROSSERIAL_TX USBTX
#endif

#ifndef ROSSERIAL_RX
#   define ROSSERIAL_RX USBRX
#endif

#ifndef ROSSERIAL_BAUDRATE
#   define ROSSERIAL_BAUDRATE 115200
#endif

#ifndef ROSSERIAL_INPUT_BUFFER_SIZE
#   define ROSSERIAL_INPUT_BUFFER_SIZE 512
#endif

#ifndef ROSSERIAL_OUTPUT_BUFFER_SIZE
#   define ROSSERIAL_OUTPUT_BUFFER_SIZE 512
#endif

#ifndef ROSSERIAL_RTOS_KERNEL_MS_TICK
#   define ROSSERIAL_RTOS_KERNEL_MS_TICK 0
#endif

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
