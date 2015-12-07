#include <math.h>

#include <HCL/Vector3.hpp>
#include "Vector3.hpp"

namespace Kilo
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
        v1._lock.lock();
        x = v1.x;
        y = v1.y;
        z = v1.z;
        v1._lock.unlock();
    }

    Vector3::Vector3(long double x1, long double y1, long double z1)
    {
        x = x1;
        y = y1;
        z = z1;
    }

    Vector3& Vector3::operator = (const Vector3& v1)
    {
        v1._lock.lock();
        x = v1.x;
        y = v1.y;
        z = v1.z;
        v1._lock.unlock();
        return *this;
    }

    long double Vector3::sqlength() const {return (x * x + y * y + z * z);}
    long double Vector3::length()   const {return sqrt(sqlength());}

    Vector3 operator + (const Vector3& v1){return v1;}
    Vector3 operator - (const Vector3& v1)
    {
        v1._lock.lock();
        Vector3 result(-v1.x, -v1.y, -v1.z);
        v1._lock.unlock();
        return result;
    };

    Vector3 operator + (const Vector3& v1, const Vector3& v2)
    {
        v1._lock.lock();
        Vector3 result(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
        v1._lock.unlock();
        return result;
    }

    Vector3 operator - (const Vector3& v1, const Vector3& v2)
    {
        Vector3 result;
        result.x = v1.x - v2.x;
        result.y = v1.y - v2.y;
        result.z = v1.z - v2.z;
        return result;
    }

    Vector3 operator * (const Vector3& v1, long double q1)
    {
        Vector3 result;
        result.x = v1.x * q1;
        result.y = v1.y * q1;
        result.z = v1.z * q1;
        return result;
    }

    Vector3 operator / (const Vector3& v1, long double q1)
    {
        Vector3 result;
        result.x = v1.x / q1;
        result.y = v1.y / q1;
        result.z = v1.z / q1;
        return result;
    }

    Vector3 operator * (long double q1, const Vector3& v1)
    {
        Vector3 result;
        result.x = v1.x * q1;
        result.y = v1.y * q1;
        result.z = v1.z * q1;
        return result;
    }

    Vector3& operator += (Vector3& v1, const Vector3& v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;
        v1.z += v2.z;
        return v1;
    }

    Vector3& operator -= (Vector3& v1, const Vector3& v2)
    {
        v1.x -= v2.x;
        v1.y -= v2.y;
        v1.z -= v2.z;
        return v1;
    }

    Vector3& operator *= (Vector3& v1, long double q1)
    {
        v1.x *= q1;
        v1.y *= q1;
        v1.z *= q1;
        return v1;
    }

    Vector3& operator /= (Vector3& v1, long double q1)
    {
        v1.x /= q1;
        v1.y /= q1;
        v1.z /= q1;
        return v1;
    }

    QTextStream& operator >> (QTextStream& str, bool& b)
    {
        short tmp;
        str >> tmp;
        b = tmp;
        return str;
    }

    QTextStream& operator << (QTextStream& str, bool b)
    {
        str << (short)(b);
        return str;
    }

    QTextStream& operator >> (QTextStream& str, long double& ld)
    {
        double tmp;
        str >> tmp;
        ld = tmp;
        return str;
    }

    QTextStream& operator << (QTextStream& str, long double ld)
    {
        str << (double)(ld);
        return str;
    }

    QTextStream& operator >> (QTextStream& str, Vector3& v1)
    {
        str >> v1.x >> v1.y >> v1.z;
        return str;
    }

    QTextStream& operator << (QTextStream& str, Vector3 v1)
    {
        str << v1.x << ' ' << v1.y << ' ' << v1.z;
        return str;
    }
}
