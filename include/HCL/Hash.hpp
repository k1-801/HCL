#pragma once

#ifndef HCL_HASH_HPP
#define HCL_HASH_HPP

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

// C++
#include <cstdint>
#include <cstddef>
// Qt
#include <QCryptographicHash>
#include <QString>
#include <QTextStream>

#ifndef HCL_HASH_DIGITS
#define HCL_HASH_DIGITS 64
#endif // HCL_HASH_DIGITS

namespace Hcl
{
    class Hash
    {
        protected:
            QByteArray _data;
            void _set(QCryptographicHash&);

        public:
                     Hash();
            explicit Hash(const QString&);
            explicit Hash(const QByteArray&);
            explicit Hash(const void*, uint64_t);
            QByteArray toHex() const;
            QByteArray& data();

        friend bool operator == (const Hash&, const Hash&);
        friend bool operator != (const Hash&, const Hash&);
        friend bool operator <  (const Hash&, const Hash&);

        // < is only for sorting in std::map or QMap. No >, >= or <= supported.
        // Do not use this operator yourself because using it has no practical sense.
    };
}

#endif // HCL_HASH_HPP
