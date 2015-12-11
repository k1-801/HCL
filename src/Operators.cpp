#include "../include/HCL/Operators.hpp"

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

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

QTextStream& operator >> (QTextStream& str, QColor& c)
{
    c.setNamedColor(str.read(6));
    return str;
}

QTextStream& operator << (QTextStream& str, QColor c)
{
    str << c.name();
    return str;
}
