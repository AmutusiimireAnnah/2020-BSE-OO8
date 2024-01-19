/*
 * lm35.h - LM35 Temperature Sensor Library
 * 
 * Description:
 * This library provides functions to interface with the LM35 temperature sensor.
 * It includes functions for initializing UART communication, reading temperature,
 * and sending temperature values over UART.
 * 
 * Usage:
 * 1. Include this header file in your C program: #include "lm35.h"
 * 2. Call initUART() to initialize UART communication.
 * 3. Use readTemperature() to read the temperature from the LM35 sensor.
 * 4. Optionally, use sendString() to send a string over UART.
 * 
 * Note: Adjust the functions based on your specific hardware and requirements.
 * 
 * Author: Your Name
 * Date: January 18, 2024
 */

#ifndef LM35_H
#define LM35_H

/*
 * Function: initUART
 * -------------------
 * Initializes UART communication for serial output.
 * 
 * Parameters: None
 * Returns:    None
 */
void initUART();

/*
 * Function: readTemperature
 * -------------------------
 * Reads the temperature from the LM35 sensor.
 * 
 * Parameters: None
 * Returns:    The temperature in Celsius as a float.
 */
float readTemperature();

/*
 * Function: sendString
 * --------------------
 * Sends a string over UART.
 * 
 * Parameters:
 *   str: The string to be sent.
 * 
 * Returns: None
 */
void sendString(const char *str);

#endif /* LM35_H */
