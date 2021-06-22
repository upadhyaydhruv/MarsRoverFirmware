#include "WatchdogModule.h"

#include "Module.h"
#include "WatchdogWrapper.h"
#include "mbed.h"

namespace Module;

WatchdogModule::WatchdogModule(std::chrono::milliseconds countdown, std::chrono::milliseconds pet)
    : countdown_ms(countdown) {
  Utility::WatchdogWrapper::startWatchdog(countdown_ms);
}

void WatchdogModule::Watchdog_logLastResetReason(void) {
  Utility::WatchdogWrapper::logResetReason();
}

void WatchdogModule::periodic_1s(void) {
  Utility::WatchdogWrapper::petWatchdog();
}
