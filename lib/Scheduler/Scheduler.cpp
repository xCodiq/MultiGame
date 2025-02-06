//
// Created by: Elmar Blume - 05/02/2025
//

#include "Scheduler.h"
#include <utility>

void Scheduler::addTask(Task task) {
    // Add the task to the queue
    this->m_tasks.push(std::move(task));
}

void Scheduler::addTask(std::function<void()> callback, unsigned long delay) {
    // Add the task with the given delay
    this->m_tasks.push({std::move(callback), millis() + delay});
}

void Scheduler::addTask(std::function<void()> callback) {
    // Add the task with a delay of 0
    this->m_tasks.push({std::move(callback), 0});
}

void Scheduler::execute() {
    // If there are no tasks, return
    if (this->m_tasks.empty()) return;

    // Get the first task
    if (const auto &[callback, delay]
            = this->m_tasks.front(); delay == 0 || millis() >= delay) {
        // Execute the callback
        callback();

        // Remove the task from the queue
        this->m_tasks.pop();
    }
}

void Scheduler::clearTasks() {
    // Clear the tasks queue
    while (!this->m_tasks.empty()) {
        this->m_tasks.pop();
    }
}
