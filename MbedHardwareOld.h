/*
 * MbedHardware
 *
 *  Created on: Aug 17, 2011
 *      Author: nucho
 */

#ifndef ROS_MBED_HARDWARE_H_
#define ROS_MBED_HARDWARE_H_

#include "mbed.h"
#include "BufferedSerial/BufferedSerial.h"

class MbedHardware {
  public:
    MbedHardware(PinName tx, PinName rx, long baud = ROSSERIAL_BAUDRATE)
      :iostream(tx, rx, ROSSERIAL_INPUT_BUFFER_SIZE){
      baud_ = baud;
#if ROSSERIAL_RTOS_KERNEL_MS_TICK == 0
      t.start();
#endif
    }

    MbedHardware()
      :iostream(ROSSERIAL_TX, ROSSERIAL_RX, ROSSERIAL_INPUT_BUFFER_SIZE) {
        baud_ = ROSSERIAL_BAUDRATE;
#if ROSSERIAL_RTOS_KERNEL_MS_TICK == 0
        t.start();
#endif
    }

    void setBaud(long baud){
      this->baud_= baud;
    }

    int getBaud(){return baud_;}

    void init(){
        iostream.baud(baud_);
    }

    int read(){
        if (iostream.readable()) {
            return iostream.getc();
        } else {
            return -1;
        }
    };
    void write(uint8_t* data, int length) {
        for (int i=0; i<length; i++)
             iostream.putc(data[i]);
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
    BufferedSerial iostream;
    long baud_;
    Timer t;
};


#endif /* ROS_MBED_HARDWARE_H_ */
