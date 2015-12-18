#include "../include/HCL/Operators.hpp"

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

// Qt
#include <QObject>
// HCL
#include "../include/HCL/Exception.hpp"
#include "../include/HCL/Locker2.hpp"

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
    QString buf;
    str >> buf;
    c.setNamedColor(buf);
    return str;
}

QTextStream& operator << (QTextStream& str, QColor c)
{
    str << c.name();
    return str;
}

// QDebug
QDebug operator << (QDebug str, long double ld)
{
    str << (double)(ld);
    return str;
}
