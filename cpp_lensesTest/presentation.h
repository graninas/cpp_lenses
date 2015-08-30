#ifndef LENS_STACK_H
#define LENS_STACK_H

#include <functional>

namespace lenses
{

template <typename... Tail>
struct LS
{
    // TODO: remove type hint 'Focus'.
    template <typename Focus>
        Focus get(const Focus& value) const
    {
        return value;
    }

    template <typename Focus>
        Focus apply(const Focus& val, const std::function<Focus(Focus)>& variator) const
    {
        return variator(val);
    }

    template <typename Reroll, typename Lx>
    void reroll_(Reroll& rerolled, const Lx& lx)
    {
        rerolled.m_lens = lx;
    }
};

template<typename L, typename... Tail>
struct LS<L, Tail...> : LS<Tail...>
{
    typedef LS<Tail...> base_type;

    LS(L l, Tail... tail)
        : LS<Tail...>(tail...)
        , m_lens(l) {}

    base_type& m_base = static_cast<base_type&>(*this);
    L m_lens;
};

} // namespace lenses

#endif // LENS_STACK_H
