#include "virtual_machine.h"

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
