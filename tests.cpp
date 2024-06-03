#include <gtest/gtest.h>
#include "virtual_machine.cpp"

TEST(VirtualMachineTest, InitialState) {
    VirtualMachine vm;
    EXPECT_EQ(vm.GetCpuCount(), 1);
    EXPECT_EQ(vm.GetRamSize(), 500);
}

TEST(VirtualMachineTest, ChangeCpuCount) {
    VirtualMachine vm;
    vm.ChangeCpuCount(4);
    EXPECT_EQ(vm.GetCpuCount(), 4);
}

TEST(VirtualMachineTest, ChangeRamSize) {
    VirtualMachine vm;
    vm.ChangeRamSize(2000);
    EXPECT_EQ(vm.GetRamSize(), 2000);
}

TEST(VirtualMachineTest, ResetToSnapshot) {
    VirtualMachine vm;
    auto snapshot = vm.TakeSnapshot();
    vm.ChangeCpuCount(4);
    vm.ChangeRamSize(2000);
    vm.ResetToSnapshot(snapshot);
    EXPECT_EQ(vm.GetCpuCount(), 1);
    EXPECT_EQ(vm.GetRamSize(), 500);
}
