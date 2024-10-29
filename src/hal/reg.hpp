#include <cstdint>

#ifndef MCU_REG_HPP
#define MCU_REG_HPP

namespace hal
{

    template <typename T = std::uint32_t>
    class reg
    {
    protected:
        volatile T *const reg_ptr;

    public:
        explicit reg(std::uintptr_t address) : reg_ptr(reinterpret_cast<volatile T *>(address)) {}

        reg(const reg&) = delete;
        reg& operator=(const reg&) = default;
        reg(reg&&) = delete;
        reg& operator=(reg&&) = delete;

        T read() const { return *reg_ptr; }
        void write(T value) { *reg_ptr = value; }
    };

    template <typename T = std::uint32_t>
    class reg_ro
    {
    private:
        volatile const T *const reg_ptr;

    public:
        explicit reg_ro(std::uintptr_t address) : reg_ptr(reinterpret_cast<volatile const T *>(address)) {}

        reg_ro(const reg_ro&) = delete;
        reg_ro& operator=(const reg_ro&) = delete;
        reg_ro(reg_ro&&) = delete;
        reg_ro& operator=(reg_ro&&) = delete;

        T read() const { return *reg_ptr; }
    };

    template <typename T = std::uint32_t>
    class reg_wo
    {
    private:
        volatile T *const reg_ptr;

    public:
        explicit reg_wo(std::uintptr_t address) : reg_ptr(reinterpret_cast<volatile T *>(address)) {}

        reg_wo(const reg_wo&) = delete;
        reg_wo& operator=(const reg_wo&) = delete;
        reg_wo(reg_wo&&) = delete;
        reg_wo& operator=(reg_wo&&) = delete;

        void write(T value) { *reg_ptr = value; }
    };

} // namespace core
#endif
