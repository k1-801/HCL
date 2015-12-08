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

    class Locker2 : private internal::Locker
    {
        private:
            std::lock_guard<std::mutex> _g1;
            std::lock_guard<std::mutex> _g2;

        public:
            Locker2(std::mutex&, std::mutex&);
    };
    typedef std::lock_guard<std::mutex> Locker1;
}


#endif // HCL_LOCKER_HPP
