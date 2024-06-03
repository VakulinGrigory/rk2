#include <iostream>
#include <stack>
#include <vector>

class Snapshot
{
private:
    struct State
    {
        std::uint16_t cpuCount{ 1 };
        std::uint64_t ramSize{ 500 };
        // ...
    };

    explicit Snapshot(State const& state);

    State state_;

    friend class VirtualMachine;
};

class VirtualMachine
{
public:
    std::uint16_t GetCpuCount() const;
    std::uint64_t GetRamSize() const;
    std::uint16_t ChangeCpuCount(std::uint16_t cpuCount);
    std::uint64_t ChangeRamSize(std::uint64_t ramSize);
    void ResetToSnapshot(const Snapshot& snapshot);
    Snapshot TakeSnapshot() const;

private:
    Snapshot::State state_;
};
