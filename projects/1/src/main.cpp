#include <avr/io.h>
#include <encoder.h>

// put function declarations here:
int main() 
{
    Encoder enc(3, 4); // D3 and D4
    enc.init();

    while (1) {
        

    }

    return 0;
}