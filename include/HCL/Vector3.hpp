#pragma once

#ifndef VECTOR3_HPP_INCLUDED
#define VECTOR3_HPP_INCLUDED

// C++
#include <cstddef>
// Qt
#include <QMutex>
#include <QTextStream>

namespace Kilo
{
    class Vector3
    {
        private:
            QMutex _lock;
            long double x;
            long double y;
            long double z;

        public:
            Vector3();
            Vector3(std::nullptr_t);
            Vector3(const volatile Vector3&);
            Vector3(long double, long double, long double);

            void setX(long double) volatile;
            void setY(long double) volatile;
            void setZ(long double) volatile;

            long double getX() const volatile;
            long double getY() const volatile;
            long double getZ() const volatile;

            Vector3& operator = (const volatile Vector3&);

            long double sqlength() const volatile;
            long double   length() const volatile;
    };

    Vector3 operator + (const volatile Vector3&);
    Vector3 operator - (const volatile Vector3&);

    Vector3 operator + (const volatile Vector3&, const volatile Vector3&);
    Vector3 operator - (const volatile Vector3&, const volatile Vector3&);
    Vector3 operator * (const volatile Vector3&, long double);
    Vector3 operator / (const volatile Vector3&, long double);
    Vector3 operator * (long double, const volatile Vector3&);

    Vector3& operator += (volatile Vector3&, const volatile Vector3&);
    Vector3& operator -= (volatile Vector3&, const volatile Vector3&);
    Vector3& operator *= (volatile Vector3&, long double);
    Vector3& operator /= (volatile Vector3&, long double);

    QTextStream& operator >> (QTextStream&, bool&);
    QTextStream& operator << (QTextStream&, bool);
    QTextStream& operator >> (QTextStream&, long double&);
    QTextStream& operator << (QTextStream&, long double);
    QTextStream& operator >> (QTextStream&, volatile Vector3&);
    QTextStream& operator << (QTextStream&, const volatile Vector3);

    typedef Vector3 Rotation;
    typedef Vector3 Color;
    typedef Vector3 Coord;
    typedef Vector3 Force;
    typedef Vector3 Speed;
    typedef QList<Vector3> Traectory;
}

#endif // VECTOR3_HPP_INCLUDED
