//
// Created by: Elmar Blume - 11/02/2025
//

#include "Button.h"

Button::Button(const int pin) : m_btn_pin(pin), m_state(IDLE), m_start_time_pressed(0) {
    pinMode(pin, INPUT);
}

int Button::isPressed() const {
    return digitalRead(this->m_btn_pin) == LOW;
}

unsigned long Button::examine() {
    if (this->m_state == IDLE && this->isPressed()) {
        this->m_start_time_pressed = millis();
        this->m_state = PRESSED;
    } else if (this->m_state == PRESSED && this->isPressed()) {
        // currently pressed, do nothing
    } else if (this->m_state == PRESSED && !this->isPressed()) {
        const unsigned long time_pressed = millis() - this->m_start_time_pressed;

        this->m_state = IDLE;
        this->m_start_time_pressed = 0;

        // Execute the callback if it exists
        if (const auto callback = this->getCallback(time_pressed))
            callback();

        return time_pressed;
    }

    return 0;
}

Button& Button::addCallback(const unsigned long time, std::function<void()> callback) {
    this->m_callbacks[time] = std::move(callback);
    // return itself for chaining
    return *this;
}

std::function<void()> Button::getCallback(const unsigned long time) {
    for (const auto &[fst, snd]: this->m_callbacks) {
        // Check if the time is within the range of the callback
        if (time > 0 && time < fst) {
            return snd;
        }
    }

    // No callback found
    return nullptr;
}

void Button::removeCallback(const unsigned long time) {
    this->m_callbacks.erase(time);
}

void Button::clearCallbacks() {
    this->m_callbacks.clear();
}
