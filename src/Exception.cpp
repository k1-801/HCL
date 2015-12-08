#include "../include/HCL/Exception.hpp"

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

// C
#include <stdio.h>

namespace Hcl
{
    Exception::Exception(QString text)
    {
        _text = text;
    }

    Exception::~Exception(){}

    const QString& Exception::getText() const
    {
        return _text;
    }
}
