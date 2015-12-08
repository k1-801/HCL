#include "../include/HCL/Hash.hpp"

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

// HCL
#include "../include/HCL/Exception.hpp"

namespace Hcl
{
    Hash::Hash()
    {
        _data.resize(8);
    }

    Hash::Hash(const QString& data)
    {
        QCryptographicHash tmp(QCryptographicHash::Md5);
        tmp.addData(data.toUtf8());
        _set(tmp);
    }

    Hash::Hash(const QByteArray& data)
    {
        QCryptographicHash tmp(QCryptographicHash::Md5);
        tmp.addData(data);
        _set(tmp);
    }

    Hash::Hash(const void* data, uint64_t len)
    {
        QCryptographicHash tmp(QCryptographicHash::Md5);
        tmp.addData((const char*)(data), len);
        _set(tmp);
    }

    // Mess next

    void Hash::_set(QCryptographicHash& tmp)
    {
        _data = tmp.result();
    }

    QByteArray Hash::toHex() const
    {
        return _data.toHex();
    }

    QByteArray& Hash::data()
    {
        return _data;
    }

    // Operators

    bool operator == (const Hash& a, const Hash& b)
    {
        uint64_t* adata = (uint64_t*)(a._data.data());
        uint64_t* bdata = (uint64_t*)(b._data.data());
        return (*adata == *bdata && *(adata + 1) == *(bdata + 1));
        //return (a._data == b._data);
    }

    bool operator != (const Hash& a, const Hash& b)
    {
        uint64_t* adata = (uint64_t*)(a._data.data());
        uint64_t* bdata = (uint64_t*)(b._data.data());
        return (*adata != *bdata || *(adata + 1) != *(bdata + 1));
        //return (a._data != b._data);
    }

    bool operator <  (const Hash& a, const Hash& b)
    {
        uint64_t* adata = (uint64_t*)(a._data.data());
        uint64_t* bdata = (uint64_t*)(b._data.data());
        return (*adata < *bdata ||(*adata == *bdata && *(adata + 1) < *(bdata + 1)));
        //return (a._data < b._data);
    }
}
