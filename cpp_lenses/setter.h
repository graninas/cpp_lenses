#ifndef SETTER_H
#define SETTER_H

#include <functional>

namespace lenses
{

#define SETTER(A, B, b) [](A a, const B& replacer) { a.b = replacer; return a; }

#define modify(Type, expr) std::function<Type(Type)>([](Type _value) { return (expr); })

template<typename Type> std::function<Type(Type)> set(Type val)
{
    return [=] (Type) { return val; };
}

template <typename ST, typename Value, typename Focus>
Value evalLens(const ST& st, const Value& value, const std::function<Focus(Focus)>& variator)
{
    return st.apply(value, variator);
}

template <typename ST, typename Value, typename Focus>
Value set(const ST& st, const Value& value, const Focus& newFocus)
{
    return evalLens(st, value, set(newFocus));
}

template <typename ST, typename Value, typename Focus>
Value over(const ST& st, const Value& value, const std::function<Focus(Focus)>& variator)
{
    return evalLens(st, value, variator);
}


} // namespace lenses

#endif // SETTER_H
