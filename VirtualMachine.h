#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <iostream>
#include <cstdint>

// Memento 클래스
class Snapshot
{
private:
    friend class VirtualMachine;

    // 예시를 위해 간단하게 했지만, 실제로는 외부에 노출되면 안되는 많은 상태 정보들이
    // 들어있을 것입니다.
    struct State
    {
        std::uint16_t cpuCount{ 1 };
        std::uint64_t ramSize{ 500 };
        // ...
    };

    explicit Snapshot(State const& state)
        : state_(state)
    {}

    State state_;
};

// Originator 클래스
class VirtualMachine
{
public:
    std::uint16_t GetCpuCount() const;
    std::uint64_t GetRamSize() const;

    std::uint16_t ChangeCpuCount(std::uint16_t cpuCount);
    std::uint64_t ChangeRamSize(std::uint64_t ramSize);

    void ResetToSnapshot(Snapshot const& snapshot);
    Snapshot TakeSnapshot() const;

private:
    Snapshot::State state_;
};

void PrintVmInfo(VirtualMachine const& vm);

#endif // VIRTUALMACHINE_H
