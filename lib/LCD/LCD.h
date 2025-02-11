//
// Created by: Elmar Blume - 11/02/2025
//

#ifndef LCD_H
#define LCD_H

#include <string>
#include <utility>
#include <LiquidCrystal_I2C.h>
#include <Scheduler.h>

#define FIRST_ROW_INDEX 0
#define SECOND_ROW_INDEX 1

class LCD {
public:
    explicit LCD(uint8_t address, uint8_t columns, uint8_t rows, Scheduler &scheduler);

    /**
    * Show text on the lcd screen for a certain duration
     *
    * @param text the text string to show
    * @param duration the duration to show the feedback
    */
    void showText(const std::string &text, unsigned long duration);

    /**
     * Show text(std::string) on the lcd screen
     *
     * @param text the text string to show
     */
    void showText(const std::string &text);

    /**
     * Show text(String) on the lcd screen
     *
     * @param text the text String to show
     */
    void showText(const String &text);

    /**
     * Show text(chars) on the lcd screen
     *
     * @param text the text chars to show
     */
    void showText(const char text[]);

    /**
     * Set the cursor on the lcd screen
     *
     * @param col the column index
     * @param row the row index
     */
    void setCursor(uint8_t col, uint8_t row);

    /**
     * Initialize the lcd screen
     */
    void init();

    /**
     * Clear the lcd screen
     */
    void clear();

private:
    // LCD i2c instance
    LiquidCrystal_I2C m_lcd;

    // Scheduler instance
    Scheduler &m_scheduler;

    // Last shown text -> 0=first row, 1=second row
    std::pair<std::string, std::string> m_last_text;
    int m_last_row;
};




#endif //LCD_H
