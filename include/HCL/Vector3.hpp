#pragma once

#ifndef VECTOR3_HPP_INCLUDED
#define VECTOR3_HPP_INCLUDED

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

// C++
#include <cstddef>
#include <mutex>
// Qt
#include <QTextStream>
// HCL
#include "../../include/HCL/Operators.hpp"

namespace Hcl
{
    class Vector3
    {
        private:
            mutable std::mutex _m;
            long double x;
            long double y;
            long double z;

        public:
            Vector3();
            Vector3(std::nullptr_t);
            Vector3(const Vector3&);
            Vector3(long double, long double, long double);

            void setX(long double);
            void setY(long double);
            void setZ(long double);

            long double getX() const;
            long double getY() const;
            long double getZ() const;

            Vector3& operator = (const Vector3&);

            long double sqlength() const;
            long double   length() const;

        friend Vector3 operator + (const Vector3&);
        friend Vector3 operator - (const Vector3&);

        friend Vector3 operator + (const Vector3&, const Vector3&);
        friend Vector3 operator - (const Vector3&, const Vector3&);
        friend Vector3 operator * (const Vector3&, long double);
        friend Vector3 operator / (const Vector3&, long double);
        friend Vector3 operator * (long double, const Vector3&);

        friend Vector3& operator += (Vector3&, const Vector3&);
        friend Vector3& operator -= (Vector3&, const Vector3&);
        friend Vector3& operator *= (Vector3&, long double);
        friend Vector3& operator /= (Vector3&, long double);

        friend QTextStream& operator >> (QTextStream&, Vector3&);
        friend QTextStream& operator << (QTextStream&, const Vector3);
    };

    typedef Vector3 Rotation;
    typedef Vector3 Coord;
    typedef Vector3 Force;
    typedef Vector3 Speed;
    typedef QList<Coord> Traectory;
}

#endif // VECTOR3_HPP_INCLUDED
