//
// Created by: Elmar Blume - 11/02/2025
//

#include "WPM.h"

WPM::WPM(uint8_t strobe, uint8_t clock, uint8_t dio, Scheduler &scheduler)
    : m_tm({strobe, clock, dio}),
      m_scheduler(scheduler) {
}
