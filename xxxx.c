#include <stdio.h>
#include "pico/stdlib.h"

int main() {

    const uint RED_LED_PIN = 25; 
    const uint GREEN_LED_PIN = 15; 
    const uint BLUE_LED_PIN = 16; 

    
    stdio_init_all();               //serial communication

    // Initialize the LED pins
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);

    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

    // Initially turn all LEDs off
    gpio_put(RED_LED_PIN, false);   // Red LED OFF
    gpio_put(GREEN_LED_PIN, false); // Green LED OFF
    gpio_put(BLUE_LED_PIN, true);   // Blue LED OFF 

    // Loop forever
    while (true) {
        // Keep all LEDs off for the first 5 seconds
        sleep_ms(5000);

        //Turn on each LED for 1 second
        gpio_put(RED_LED_PIN, true);  // Turn on Red LED
        printf("Red LED ON");
        sleep_ms(1000);
        gpio_put(RED_LED_PIN, false); // Turn off Red LED
        printf("Red LED OFF");

        gpio_put(GREEN_LED_PIN, true);  // Turn on Green LED
        printf("Green LED ON");
        sleep_ms(1000);
        gpio_put(GREEN_LED_PIN, false); // Turn off Green LED
        printf("Green LED OFF");

        gpio_put(BLUE_LED_PIN, false);    // Turn on Blue LED 
        printf("Blue LED ON");
        sleep_ms(1000);
        gpio_put(BLUE_LED_PIN, true);   // Turn off Blue LED 
        printf("Blue LED OFF");

        // Turn on all LEDs
        gpio_put(RED_LED_PIN, true);    // Turn on Red LED
        gpio_put(GREEN_LED_PIN, true);  // Turn on Green LED
        gpio_put(BLUE_LED_PIN, false);  // Turn on Blue LED 
        printf("All LEDs ON");
        sleep_ms(2000);

        // Turn off all LEDs
        gpio_put(RED_LED_PIN, false);     // Turn off Red LED
        gpio_put(GREEN_LED_PIN, false);   // Turn off Green LED
        gpio_put(BLUE_LED_PIN, true);     // Turn off Blue LED 
        printf("All LEDs OFF");
    }
}