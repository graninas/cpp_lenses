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

template<typename L1, typename... Tail>
struct LS<L1, Tail...>
    : LS<Tail...>
{
    typedef LS<Tail...> base_type;
    typedef L1          value_type;

    LS() : LS<Tail...>()
    {}

    LS(L1 l1, Tail... tail)
        : LS<Tail...>(tail...)
        , m_lens(l1)
    {}

    // type alias declarations, C++11
    template <typename Lx>
        using reroll_type = LS<L1, Tail..., Lx>;

    template <typename Lx>
    LS<L1, Tail..., Lx> reroll(const Lx& lx) const
    {
        LS<L1, Tail..., Lx> rerolled;
        rerolled.m_lens = m_lens;
        base.reroll_(rerolled.base, lx);
        return rerolled;
    }

    template <typename Reroll, typename Lx>
    void reroll_(Reroll& rerolled, const Lx& lx) const
    {
        rerolled.m_lens = m_lens;
        base.reroll_(rerolled.base, lx);
    }

    // TODO: remove type hint 'Focus'.
    template <typename Focus, typename Value>
        Focus get(const Value& value) const
    {
        auto z2 = m_lens.getter(value);
        return base.get<Focus>(z2);
    }

    template <typename H1, typename Focus>
        H1 apply(const H1& value, const std::function<Focus(Focus)>& variator) const
    {
        H1 z1 = value;
        auto z2 = m_lens.getter(value);
        z2 = base.apply(z2, variator);
        return m_lens.setter(z1, z2);
    }

    template <typename Contained, typename Focus>
        std::vector<Contained> apply(const std::vector<Contained>& val, const std::function<Focus(Focus)>& variator) const
    {
        auto container = val;
        for (auto it = container.begin(); it != container.end(); ++it)
        {
            *it = base.apply(*it, variator);
        }
        return container;
    }

    template <typename Contained, typename Focus>
        std::list<Contained> apply(const std::list<Contained>& val, const std::function<Focus(Focus)>& variator) const
    {
        auto container = val;
        for (auto it = container.begin(); it != container.end(); ++it)
        {
            *it = base.apply(*it, variator);
        }
        return container;
    }

    base_type& base = static_cast<base_type&>(*this);
    L1 m_lens;
};

} // namespace lenses

#endif // LENS_STACK_H
