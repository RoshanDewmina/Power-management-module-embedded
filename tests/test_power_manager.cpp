#include "PowerManager.h"
#include <cassert>
#include <iostream>

int main() {
    PowerManager pm;

    pm.setPowerState(PowerState::Active);
    assert(pm.getPowerState() == PowerState::Active);

    pm.handleEvent("sleep_event");
    assert(pm.getPowerState() == PowerState::Sleep);

    pm.handleEvent("wake_event");
    assert(pm.getPowerState() == PowerState::Active);

    pm.handleEvent("idle_event");
    assert(pm.getPowerState() == PowerState::Idle);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
