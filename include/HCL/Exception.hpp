#pragma once

#ifndef HCL_EXCEPTION_HPP
#define HCL_EXCEPTION_HPP

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

// Qt
#include <QString>

namespace Hcl
{
    class Exception
    {
        protected:
            QString _text;

        public:
            Exception(QString = "Unknown exception");
            virtual ~Exception();
            const QString& getText() const;
    };
}

#endif // HCL_EXCEPTION_HPP
