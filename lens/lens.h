#ifndef LENS_H
#define LENS_H

#include <functional>

#include "identity.h"

namespace lenses
{

template <typename Value, typename Focus, template <typename> class Container = Identity>
struct Lens
{
    std::function<Focus(Value)> getter;
    std::function<Value(Value&, Focus)> setter;

    // TODO: this seems a right way to generalize of different lenses applying.
    Value apply(const Value& value, const std::function<Focus(Focus)>& variator) const
    {
        Value z1 = value;
        auto z2 = getter(value);
        z2 = variator(z2);
        return setter(z1, z2);
    }
};

template <typename Value, typename Focus>
Lens<Value, Focus>
    lens(const std::function<Focus(Value)>& getter,
         const std::function<Value(Value, Focus)>& setter)
{
    Lens<Value, Focus> l;
    l.getter = getter;
    l.setter = setter;
    return l;
}

template <typename Value, typename Focus>
    bool isFocus(const Lens<Value, Focus>& l)
{
    return false;
}

template <typename Focus>
    bool isFocus(const Lens<Focus, Id>& l)
{
    return true;
}

template <typename Focus>
Lens<Focus, Id> idL()
{
    Lens<Focus, Id> l;
    return l;
}

}

#endif // LENS_H
