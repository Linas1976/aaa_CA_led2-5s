#include "mbed.h"
// defines led pins
DigitalOut led1(LED1);
DigitalOut led2(PA_5);

Thread t1;
Thread t2;

//Thread function to toggle led1 every 2 seconds
void led1_thread() {
    while (true) {
        led1 = !led1;
        ThisThread::sleep_for(2s);
    }
}
// Thread function to toggle led2 every 5 second
void led2_thread() {
    while (true) {
        led2 = !led2;
        ThisThread::sleep_for(5s);
    }
}
//runs in its own thread in the OS and starts threads
int main()
{
    t1.start(led1_thread);
    t2.start(led2_thread);
//loops infinitely
    while (true) {

    }
}
