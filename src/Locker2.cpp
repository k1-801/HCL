#include "include/HCL/Locker.hpp"

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

namespace Hcl
{
    namespace internal
    {
        Locker::Locker(std::mutex& m1, std::mutex& m2)
        {
            std::lock(m1, m2);
        }
    }
    Locker::Locker(std::mutex& m1, std::mutex& m2) : internal::Locker(m1, m2), _g1(m1, std::adopt_lock), _g2(m2, std::adopt_lock) {}
}
