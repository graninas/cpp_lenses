#ifndef LENS_H
#define LENS_H

#include <functional>

#include <identity.h>

namespace lenses
{
// TODO: a better generic lenses?
//template <typename Value, typename Focus, template <typename> class Container = Identity>
template <typename Value, typename Focus>
struct Lens
{
    std::function<Focus(Value)> getter;
    std::function<Value(Value, Focus)> setter;

    // TODO: this seems a right way to generalize of different lenses applying.
    Value apply(Value value, const std::function<Focus(Focus)>& variator) const
    {
        auto z2 = getter(value);
        z2 = variator(z2);
        return setter(value, z2);
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
    bool isFocus(const Lens<Focus, fp::Id>& l)
{
    return true;
}

template <typename Focus>
Lens<Focus, fp::Id> idL()
{
    Lens<Focus, fp::Id> l;
    return l;
}

} // namespace lenses

#endif // LENS_H
