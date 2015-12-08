#ifndef HCL_LOCKER_HPP
#define HCL_LOCKER_HPP

// C++
#include <mutex>

namespace Hcl
{
    class Locker
    {
        private:
            std::mutex* _m1;
            std::mutex* _m2;

        public:
            Locker(std::mutex&);
            Locker(std::mutex&, std::mutex&);
            ~Locker();
    };
}

#define LOCK(a) Hcl::Locker _l(a);
#define LOCK2(a,b) Hcl::Locker _l(a, b);

#endif // HCL_LOCKER_HPP
