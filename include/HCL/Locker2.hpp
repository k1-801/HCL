#pragma once

#ifndef HCL_LOCKER_HPP
#define HCL_LOCKER_HPP

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

// C++
#include <mutex>

namespace Hcl
{
    namespace internal
    {
        class Locker
        {
            public:
                Locker(std::mutex&, std::mutex&);
        };
    }

    class Locker : private internal::Locker
    {
        private:
            std::lock_guard<std::mutex> _g1;
            std::lock_guard<std::mutex> _g2;

        public:
            Locker(std::mutex&, std::mutex&);
    };
}

#endif // HCL_LOCKER_HPP
