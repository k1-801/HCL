#pragma once

#ifndef HCL_OPERATORS_HPP
#define HCL_OPERATORS_HPP

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

// Qt
#include <QColor>
#include <QDebug>
#include <QTextStream>
// HCL
#include "../include/HCL/Vector3.hpp"

// QTextStream
QTextStream& operator >> (QTextStream&, bool&);
QTextStream& operator << (QTextStream&, bool);
QTextStream& operator >> (QTextStream&, long double&);
QTextStream& operator << (QTextStream&, long double);
QTextStream& operator >> (QTextStream&, QColor&);
QTextStream& operator << (QTextStream&, QColor);
// QDebug
QDebug operator << (QDebug, long double);

#endif // OPERATORS_HPP

