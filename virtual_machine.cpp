#include "VirtualMachine.h"

std::uint16_t VirtualMachine::GetCpuCount() const
{
    return state_.cpuCount;
}

std::uint64_t VirtualMachine::GetRamSize() const
{
    return state_.ramSize;
}

std::uint16_t VirtualMachine::ChangeCpuCount(std::uint16_t cpuCount)
{
    auto old = state_.cpuCount;
    state_.cpuCount = cpuCount;
    return old;
}

std::uint64_t VirtualMachine::ChangeRamSize(std::uint64_t ramSize)
{
    auto old = state_.ramSize;
    state_.ramSize = ramSize;
    return old;
}

void VirtualMachine::ResetToSnapshot(Snapshot const& snapshot)
{
    state_ = snapshot.state_;
}

Snapshot VirtualMachine::TakeSnapshot() const
{
    return Snapshot(state_);
}

void PrintVmInfo(VirtualMachine const& vm)
{
    std::cout << "----------------" << std::endl;
    std::cout << "Cpu Count : " << vm.GetCpuCount() << std::endl;
    std::cout << "Ram Size  : " << vm.GetRamSize() << std::endl << std::endl;
}

int main()
{
    VirtualMachine vm;

    PrintVmInfo(vm);
    auto snapshot_1 = vm.TakeSnapshot();

    vm.ChangeCpuCount(16);
    vm.ChangeRamSize(1500);
    PrintVmInfo(vm);
    auto snapshot_2 = vm.TakeSnapshot();

    vm.ResetToSnapshot(snapshot_1);
    PrintVmInfo(vm);

    vm.ChangeCpuCount(4);
    vm.ChangeRamSize(6000);
    PrintVmInfo(vm);

    vm.ResetToSnapshot(snapshot_2);
    PrintVmInfo(vm);
}
