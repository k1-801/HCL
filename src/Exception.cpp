#include "../include/HCL/Exception.hpp"

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
