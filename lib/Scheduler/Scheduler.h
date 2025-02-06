//
// Created by: Elmar Blume - 05/02/2025
//

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include <functional>
#include <Arduino.h>

/**
 * A task to execute after a delay, or immediately if the delay is 0
 */
struct Task {
    std::function<void()> callback;
    unsigned long delay;
};

class Scheduler {
public:
    /**
     * Construct a new Scheduler object
     */
    Scheduler() = default;

    /**
     * Add a task to the scheduler
     *
     * @param task the task to add
     */
    void addTask(Task task);

    /**
     * Add a task to the scheduler
     *
     * @param callback the function to call
     * @param delay the delay in milliseconds
     * @note creates a Task object internally
     */
    void addTask(std::function<void()> callback, unsigned long delay);

    /**
     * Add a task to the scheduler
     *
     * @param callback the function to call
     * @note creates a Task object internally, with a delay of 0
     */
    void addTask(std::function<void()> callback);

    /**
     * Execute the tasks
     */
    void execute();

    /**
     * Clear all tasks
     */
    void clearTasks();

private:
    std::queue<Task> m_tasks;
};


#endif //SCHEDULER_H
