//
// Created by: Elmar Blume - 11/02/2025
//

#ifndef WPM_H
#define WPM_H

#include <Scheduler.h>
#include <string>
#include <TM1638plus.h>

class WPM {
public:
    explicit WPM(uint8_t strobe, uint8_t clock, uint8_t dio, Scheduler &scheduler);

    /**
    * Show text on the whadda segments for a certain duration
     *
    * @param text the text string to show
    * @param duration the duration to show the feedback
    */
    void showText(const std::string &text, unsigned long duration);

    /**
     * Show text(std::string) on the whadda segments
     *
     * @param text the text string to show
     */
    void showText(const std::string &text);

    /**
     * Show text(String) on the whadda segments
     *
     * @param text the text String to show
     */
    void showText(const String &text);

    /**
     * Show text(chars) on the whadda segments
     *
     * @param text the text chars to show
     */
    void showText(const char text[]);

    /**
     * Clears the current text on the whadda segments
     */
    void clear();

private:
    // TM1638plus instance
    TM1638plus m_tm;

    // Scheduler instance
    Scheduler &m_scheduler;

    // Last shown text on the whadda segments
    std::string m_last_text;
};


#endif //WPM_H
