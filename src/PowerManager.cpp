#include "PowerManager.h"
#include <iostream>

PowerManager::PowerManager()
    : currentState(PowerState::Idle),
      lastStateChange(std::chrono::steady_clock::now()) {
    // Initialize energy usage values for each state
    energyUsage[PowerState::Active] = 0.0;
    energyUsage[PowerState::Sleep] = 0.0;
    energyUsage[PowerState::Idle] = 0.0;
}

void PowerManager::setPowerState(PowerState state) {
    // Log energy usage for the time spent in the current state
    logEnergyUsage();

    currentState = state;
    lastStateChange = std::chrono::steady_clock::now();

    switch (state) {
        case PowerState::Active:
            std::cout << "System is now active." << std::endl;
            break;
        case PowerState::Sleep:
            std::cout << "System is now in sleep mode." << std::endl;
            break;
        case PowerState::Idle:
            std::cout << "System is now idle." << std::endl;
            break;
    }
}

PowerState PowerManager::getPowerState() const {
    return currentState;
}

void PowerManager::handleEvent(const std::string& event) {
    if (event == "wake_event") {
        setPowerState(PowerState::Active);
    } else if (event == "idle_event") {
        setPowerState(PowerState::Idle);
    } else if (event == "sleep_event") {
        setPowerState(PowerState::Sleep);
    } else {
        std::cout << "Unknown event: " << event << std::endl;
    }
}

void PowerManager::logEnergyUsage() {
    // Calculate the time spent in the current state
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - lastStateChange;

    // Update the total energy usage for the current state
    energyUsage[currentState] += elapsed.count();

    lastStateChange = now;
}

void PowerManager::showStatus() {
    std::cout << "Current power state: ";
    switch (currentState) {
        case PowerState::Active:
            std::cout << "Active";
            break;
        case PowerState::Sleep:
            std::cout << "Sleep";
            break;
        case PowerState::Idle:
            std::cout << "Idle";
            break;
    }
    std::cout << std::endl;

    std::cout << "Energy usage (seconds in state):" << std::endl;
    std::cout << "  Active: " << energyUsage[PowerState::Active] << "s" << std::endl;
    std::cout << "  Sleep:  " << energyUsage[PowerState::Sleep] << "s" << std::endl;
    std::cout << "  Idle:   " << energyUsage[PowerState::Idle] << "s" << std::endl;
}
