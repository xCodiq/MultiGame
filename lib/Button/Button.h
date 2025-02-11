//
// Created by: Elmar Blume - 11/02/2025
//

#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>
#include <map>

/**
 * The state of the button
 */
enum ButtonState {
    IDLE,
    PRESSED
};

class Button {
public:
    /**
     * @brief Construct a new Button object
     * @param pin the pin of the button
     */
    explicit Button(int pin);

    /**
     * Check if the button is pressed
     * @return true if the button is pressed, false otherwise
     */
    [[nodiscard]] int isPressed() const;

    /**
     * Run function to let the program know what the button is doing
     * @return the time the button was pressed
     */
    unsigned long examine();

    /**
     * Add a callback function to the button
     *
     * @param time the time the button is pressed in order to call the callback
     * @param callback the function to call when the button is pressed for the given time
     * @return the button object, to allow chaining
     */
    Button &addCallback(unsigned long time, std::function<void()> callback);

    /**
     * Get the callback function for the given time
     *
     * @param time the time the button is pressed
     * @return the callback function
     */
    std::function<void()> getCallback(unsigned long time);

    /**
     * Remove the callback function for the given time
     * @param time the time the button is pressed
     */
    void removeCallback(unsigned long time);

    /**
     * Clear all the callback functions
     */
    void clearCallbacks();

private:
    int m_btn_pin;

    ButtonState m_state;
    unsigned long m_start_time_pressed;

    std::map<unsigned long, std::function<void(void)> > m_callbacks;
};


#endif //BUTTON_H
