//
// Created by: Elmar Blume - 11/02/2025
//

#ifndef WPM_H
#define WPM_H

#include <Scheduler.h>
#include <TM1638plus.h>

class WPM {
public:
    explicit WPM(uint8_t strobe, uint8_t clock, uint8_t dio, Scheduler &scheduler);

private:
    // TM1638plus instance
    TM1638plus m_tm;

    // Scheduler instance
    Scheduler &m_scheduler;
};


#endif //WPM_H
