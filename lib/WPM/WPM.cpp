//
// Created by: Elmar Blume - 11/02/2025
//

#include "WPM.h"

WPM::WPM(uint8_t strobe, uint8_t clock, uint8_t dio, Scheduler &scheduler)
    : m_tm({strobe, clock, dio}), m_scheduler(scheduler) {
    // Initialize the whadda module
    this->m_tm.displayBegin();
    this->m_tm.reset();
}

void WPM::showText(const std::string &text, unsigned long duration) {
    this->m_scheduler.addTask([this, text] {
        // Call the showText function
        this->showText(text);
    });

    // Revert back to the last text after the duration if necessary
    if (this->m_last_text.empty()) return;

    this->m_scheduler.addTask([this] {
        // Show the last text
        this->showText(this->m_last_text);
    }, duration);
}

void WPM::showText(const std::string &text) {
    this->showText(text.c_str());
}

void WPM::showText(const String &text) {
    this->showText(text.c_str());
}

void WPM::showText(const char text[]) {
    // Display the text on the whadda segments
    if (this->m_last_text != text) this->m_tm.reset();
    this->m_tm.displayText(text);

    // Save the text as last text displayed
    this->m_last_text = text;
}

void WPM::clear() {
    this->m_tm.reset();
}
