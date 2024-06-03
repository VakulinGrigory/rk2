#include "virtual_machine.h"

Snapshot::Snapshot(State const& state)
    : state_(state)
{}
std::uint16_t VirtualMachine::GetCpuCount() const {
    return state_.cpuCount;
}

std::uint64_t VirtualMachine::GetRamSize() const {
    return state_.ramSize;
}

std::uint16_t VirtualMachine::ChangeCpuCount(std::uint16_t cpuCount) {
    auto old = state_.cpuCount;
    state_.cpuCount = cpuCount;
    return old;
}

std::uint64_t VirtualMachine::ChangeRamSize(std::uint64_t ramSize) {
    auto old = state_.ramSize;
    state_.ramSize = ramSize;
    return old;
}

void VirtualMachine::ResetToSnapshot(const Snapshot& snapshot) {
    state_ = snapshot.state_;
}

Snapshot VirtualMachine::TakeSnapshot() const {
    return Snapshot(state_);
}
