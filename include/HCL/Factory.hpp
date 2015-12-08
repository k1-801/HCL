#pragma once

#ifndef HCL_FACTORY_HPP
#define HCL_FACTORY_HPP

/**
 * This file is a part of Haont Common Library (HCL)
 * Contains factory - a portable object factory class
 * Builds objects of any registered subclass of T (may also build T itself, if registered)
 *
 * @project HCL
 * @author k1-801
 */

// C++
#include <memory>
#include <utility>
// Qt
#include <QMap>
#include <QString>
// HCL
#include "Defs.hpp"
#include "Exception.hpp"
#include "Hash.hpp"

namespace Hcl
{
    template <class T>
    using FactoryBuilderFunc = std::shared_ptr<T>(*)();

    template <class T>
    class Factory
    {
        private:
            QMap<Hash, QString              > _names;
            QMap<Hash, FactoryBuilderFunc<T>> _funcs;
            Factory(){}

        public:
            static Factory<T>& getInstance();

            void add(QString name, FactoryBuilderFunc<T> func);
            std::shared_ptr<T> get(Hash hash) const;
            std::shared_ptr<T> get(QString name) const;
            FactoryBuilderFunc<T> getFunc(Hash hash) const;
            QString getName(Hash hash) const;
            QStringList getTypes() const;

            void clear();
            size_t size() const;
    };
}

#define REGISTRATOR_T(bns, bname, dns, dname) FactoryRegistrator_##bns##__##bname##_##dns##__##dname

// Registration helper: use in target class compilation unit
#define REGISTER_IN_FACTORY(bns, bname, dns, dname) \
namespace \
{ \
    class REGISTRATOR_T(bns, bname, dns, dname) \
    { \
        private: \
            static REGISTRATOR_T(bns, bname, dns, dname) _instance; \
            REGISTRATOR_T(bns, bname, dns, dname)() \
            { \
                Hcl::Factory<bns::bname>::getInstance().add(HCL_STRING(dns::dname), &REGISTRATOR_T(bns, bname, dns, dname)::build); \
            } \
            static std::shared_ptr<bns::bname> build() \
            { \
                std::shared_ptr<dns::dname> tmp = std::make_shared<dns::dname>(); \
                return std::shared_ptr<bns::bname>(tmp); \
            } \
    } \
    REGISTRATOR_T(bns, bname, dns, dname)::_instance; \
}

#include "Factory.tpp"

#endif // HCL_FACTORY_HPP
