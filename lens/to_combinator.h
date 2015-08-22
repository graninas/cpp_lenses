#ifndef TO_COMBINATOR_H
#define TO_COMBINATOR_H

#include "identity.h"
#include "lens_stack.h"
#include "lenses.h"

#include <functional>

using namespace std;

namespace lenses
{

namespace // anonymous
{

struct ToProxy
{
public:
    template<typename T>
    T operator () (T a) const { return a; }
} toProxy;

template <typename L1, typename L2>
LS<Lens<L1, L2>> operator<(const Lens<L1, L2>& l, const ToProxy&)
{
    return LS<Lens<L1, L2>>(l);
}

template <typename ST>
ST operator<(const ST& st, const ToProxy&)
{
    return st;
}

template <typename ST, typename L>
typename ST::template reroll_type<L> operator>(const ST& st, const L& l)
{
    return st.reroll(l);
}

} // namespace anonymous

#define to < toProxy >


} // namespace lenses

#endif // TO_COMBINATOR_H
