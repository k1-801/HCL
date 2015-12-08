#include "Factory.hpp"

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

namespace Hcl
{
    template<class T>
    static Factory<T>& Factory<T>::getInstance()
    {
        static Factory<T> _instance;
        return _instance;
    }

    template<class T>
    void Factory<T>::add(QString name, FactoryBuilderFunc<T> func)
    {
        if(name.isEmpty())
            throw Hcl::Exception("Hcl::Factory::add(): no name given");
        Hash hash(name);
        if(_funcs.find(hash) != _funcs.end())
            throw Hcl::Exception("Hcl::Factory::add(): hash collision");
        if(!func)
            throw Hcl::Exception("Hcl::Factory::add(): no builder function given");
        _funcs[hash] = func;
        _names[hash] = name;
    }

    template<class T>
    std::shared_ptr<T> Factory<T>::get(Hash hash) const
    {
        if(_funcs.find(hash) == _funcs.end())
            throw Hcl::Exception("Hcl::Factory::get(): class is not registered");
        return _funcs[hash]();
    }

    template<class T>
    std::shared_ptr<T> Factory<T>::get(QString name) const
    {
        Hash hash(name);
        return get(hash);
    }

    template<class T>
    FactoryBuilderFunc<T> Factory<T>::getFunc(Hash hash) const
    {
        if(_funcs.find(hash) == _funcs.end())
            throw Hcl::Exception("Hcl::Factory::getFunc(): class is not registered");
        return _funcs[hash];
    }

    template<class T>
    QString Factory<T>::getName(Hash hash) const
    {
        if(_names.find(hash) == _names.end())
            throw Hcl::Exception("Hcl::Factory::getName(): class is not registered");
        return _names[hash];
    }

    template<class T>
    QStringList Factory<T>::getTypes() const
    {
        QStringList result;
        for(auto i : _names)
        {
            result.push_back(i);
        }
        return result;
    }

    template<class T>
    void Factory<T>::clear()
    {
        _names.clear();
        _funcs.clear();
    }

    template<class T>
    size_t Factory<T>::size() const
    {
        return _funcs.size();
    }
}
