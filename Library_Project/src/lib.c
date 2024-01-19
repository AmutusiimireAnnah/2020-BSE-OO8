#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define LM35_PIN 0 // Assuming the LM35 is connected to analog pin 0

// Function to initialize UART for serial communication
void initUART() {
    // Set baud rate to 9600 (for example)
    UBRR0H = 0;
    UBRR0L = 103;
    // Enable transmitter
    UCSR0B = (1 << TXEN0);
    // Set frame format: 8 data bits, 1 stop bit, no parity
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

// Function to read temperature from LM35
float readTemperature() {
    // Read analog value from LM35
    uint16_t adcValue;
    ADMUX = (1 << REFS0) | (LM35_PIN & 0x0F); // Set reference voltage and input channel
    ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC and set prescaler
    while (ADCSRA & (1 << ADSC)); // Wait for conversion to complete
    adcValue = ADC; // Read ADC value

    // Convert ADC value to temperature (in Celsius)
    float temperatureC = (adcValue * 5.0 / 1024) * 100;

    return temperatureC;
}

// Function to send a string over UART
void sendString(const char *str) {
    while (*str) {
        while (!(UCSR0A & (1 << UDRE0))); // Wait for the buffer to be empty
        UDR0 = *str++;
    }
}

int main(void) {
    // Initialize UART
    initUART();

    while (1) {
        // Read temperature
        float temperature = readTemperature();

        // Convert temperature to a string
        char temperatureStr[10];
        snprintf(temperatureStr, sizeof(temperatureStr), "%.2f", temperature);

        // Send temperature over UART
        sendString("Temperature: ");
        sendString(temperatureStr);
        sendString(" °C\n");

        _delay_ms(1000); // Delay for one second
    }

    return 0;
}
