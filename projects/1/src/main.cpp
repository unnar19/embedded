#include <avr/io.h>
#include <digital_in.h>

// put function declarations here:
int main() 
{
    Digital_in C1(3); // D3
    Digital_in C2(4); // D4

    C1.init();
    C2.init();

    while (1) {
        

    }

    return 0;
}