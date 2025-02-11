//
// Created by: Elmar Blume - 11/02/2025
//

#include "LCD.h"

LCD::LCD(uint8_t address, uint8_t columns, uint8_t rows, Scheduler &scheduler)
    : m_lcd({address, columns, rows}),
      m_scheduler(scheduler) {
    // Initialize the last text pair as empty
    this->m_last_text = {"", ""};
    this->m_last_row = 0;
}

void LCD::showText(const std::string &text, const unsigned long duration) {
    this->m_scheduler.addTask([this, text] {
        // Call the showText function
        this->showText(text);
    });

    // Revert back to the last text after the duration
    this->m_scheduler.addTask([this] {
        this->showText(this->m_last_row == 0 ? this->m_last_text.first : this->m_last_text.second);
    }, duration);
}

void LCD::showText(const std::string &text) {
    this->m_lcd.print(text.c_str());
}

void LCD::showText(const String &text) {
    this->m_lcd.print(text.c_str());
}

void LCD::showText(const char text[]) {
    this->m_lcd.print(text);
}

void LCD::setCursor(const uint8_t col, const uint8_t row) {
    // Set the cursor on the LCD screen
    this->m_lcd.setCursor(col, row);
    this->m_last_row = row;
}

void LCD::init() {
    // Initialize the lcd screen
    this->m_lcd.init();
    this->m_lcd.backlight();
}

void LCD::clear() {
    // Clear the LCD screen
    this->m_lcd.clear();
    this->m_lcd.noBacklight();
}
