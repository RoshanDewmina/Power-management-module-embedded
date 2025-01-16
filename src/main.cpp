#include "PowerManager.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    PowerManager pm;

    std::cout << "Starting power management simulation..." << std::endl;

    // Start in Idle state
    pm.setPowerState(PowerState::Idle);

    // Simulate wake-up event
    std::this_thread::sleep_for(std::chrono::seconds(2));
    pm.handleEvent("wake_event");

    // Simulate some activity, then return to idle
    std::this_thread::sleep_for(std::chrono::seconds(2));
    pm.handleEvent("idle_event");

    // Simulate entering sleep mode
    std::this_thread::sleep_for(std::chrono::seconds(2));
    pm.handleEvent("sleep_event");

    // Return to active
    std::this_thread::sleep_for(std::chrono::seconds(2));
    pm.handleEvent("wake_event");

    // Display energy usage and stats
    pm.showStatus();

    return 0;
}
