#ifndef POWERMANAGER_H
#define POWERMANAGER_H

#include <string>
#include <map>
#include <chrono>
#include <functional>

enum class PowerState {
    Active,
    Sleep,
    Idle
};

class PowerManager {
public:
    PowerManager();
    void setPowerState(PowerState state);
    PowerState getPowerState() const;
    void handleEvent(const std::string& event);
    void showStatus();
    void logEnergyUsage();

private:
    PowerState currentState;
    std::map<PowerState, double> energyUsage;
    std::chrono::time_point<std::chrono::steady_clock> lastStateChange;
};

#endif
