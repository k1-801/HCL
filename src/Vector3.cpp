#include "../../include/HCL/Vector3.hpp"

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

// C
#include <math.h>
// HCL
#include "../../include/HCL/Locker.hpp"

namespace Hcl
{
    Vector3::Vector3()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3::Vector3(std::nullptr_t)
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3::Vector3(const Vector3& v1)
    {
        std::lock_guard<std::mutex> _(v1._m);
        x = v1.x;
        y = v1.y;
        z = v1.z;
    }

    Vector3::Vector3(long double x1, long double y1, long double z1)
    {
        x = x1;
        y = y1;
        z = z1;
    }

    Vector3& Vector3::operator = (const Vector3& v1)
    {
        Hcl::Locker _(_m, v1._m);
        x = v1.x;
        y = v1.y;
        z = v1.z;
        return *this;
    }

    long double Vector3::sqlength() const {std::lock_guard<std::mutex> _(_m); return (x * x + y * y + z * z);}
    long double Vector3::length()   const {std::lock_guard<std::mutex> _(_m); return sqrt(sqlength());}

    Vector3 operator + (const Vector3& v1) {std::lock_guard<std::mutex> _(v1._m); return v1;}
    Vector3 operator - (const Vector3& v1) {std::lock_guard<std::mutex> _(v1._m); return Vector3(-v1.x, -v1.y, -v1.z);}

    Vector3 operator + (const Vector3& v1, const Vector3& v2){Hcl::Locker _(v1._m, v2._m); return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);}
    Vector3 operator - (const Vector3& v1, const Vector3& v2){Hcl::Locker _(v1._m, v2._m); return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);}
    Vector3 operator * (const Vector3& v1, long double    q1){std::lock_guard<std::mutex> _(v1._m); return Vector3(v1.x * q1, v1.y * q1, v1.z * q1);}
    Vector3 operator / (const Vector3& v1, long double    q1){std::lock_guard<std::mutex> _(v1._m); return Vector3(v1.x / q1, v1.y / q1, v1.z / q1);}
    Vector3 operator * (long double    q1, const Vector3& v1){std::lock_guard<std::mutex> _(v1._m); return Vector3(v1.x * q1, v1.y * q1, v1.z * q1);}

    Vector3& operator += (Vector3& v1, const Vector3& v2)
    {
        Hcl::Locker _(v1._m, v2._m);
        v1.x += v2.x;
        v1.y += v2.y;
        v1.z += v2.z;
        return v1;
    }

    Vector3& operator -= (Vector3& v1, const Vector3& v2)
    {
        Hcl::Locker _(v1._m, v2._m);
        v1.x -= v2.x;
        v1.y -= v2.y;
        v1.z -= v2.z;
        return v1;
    }

    Vector3& operator *= (Vector3& v1, long double q1)
    {
        std::lock_guard<std::mutex> _(v1._m);
        v1.x *= q1;
        v1.y *= q1;
        v1.z *= q1;
        return v1;
    }

    Vector3& operator /= (Vector3& v1, long double q1)
    {
        std::lock_guard<std::mutex> _(v1._m);
        v1.x /= q1;
        v1.y /= q1;
        v1.z /= q1;
        return v1;
    }

    QTextStream& operator >> (QTextStream& str, Vector3& v1)
    {
        std::lock_guard<std::mutex> _(v1._m);
        str >> v1.x >> v1.y >> v1.z;
        return str;
    }

    QTextStream& operator << (QTextStream& str, Vector3 v1)
    {
        std::lock_guard<std::mutex> _(v1._m);
        str << v1.x << ' ' << v1.y << ' ' << v1.z;
        return str;
    }
}
