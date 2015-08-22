#ifndef BIND_COMBINATOR_H
#define BIND_COMBINATOR_H

#include "lenses.h"

namespace lenses
{

template <typename H1, typename H2>
LS<Lens<H1, H2>>
    bindL(const Lens<H1, H2>& l1)
{
    return LS<Lens<H1, H2>>(l1);
}

template <typename H1, typename H2, typename H3>
LS<Lens<H1, H2>, Lens<H2, H3>>
    bindL(const Lens<H1, H2>& l1, const Lens<H2, H3>& l2)
{
    return LS<Lens<H1, H2>, Lens<H2, H3>>(l1, l2);
}

template <typename H1, typename H2, typename H3, typename H4>
LS<Lens<H1, H2>, Lens<H2, H3>, Lens<H3, H4>>
    bindL(const Lens<H1, H2>& l1, const Lens<H2, H3>& l2, const Lens<H3, H4>& l3)
{
    return LS<Lens<H1, H2>, Lens<H2, H3>, Lens<H3, H4>>(l1, l2, l3);
}

template <typename H1, typename H2, typename H3, typename H4, typename H5>
LS<Lens<H1, H2>, Lens<H2, H3>, Lens<H3, H4>, Lens<H4, H5>>
    bindL(const Lens<H1, H2>& l1, const Lens<H2, H3>& l2, const Lens<H3, H4>& l3, const Lens<H4, H5>& l4)
{
    return LS<Lens<H1, H2>, Lens<H2, H3>, Lens<H3, H4>, Lens<H4, H5>>(l1, l2, l3, l4);
}

template <typename H1, typename H2, typename H3, typename H4, typename H5, typename H6>
LS<Lens<H1, H2>, Lens<H2, H3>, Lens<H3, H4>, Lens<H4, H5>, Lens<H5, H6>>
    bindL(const Lens<H1, H2>& l1, const Lens<H2, H3>& l2, const Lens<H3, H4>& l3, const Lens<H4, H5>& l4, const Lens<H5, H6>& l5)
{
    return LS<Lens<H1, H2>, Lens<H2, H3>, Lens<H3, H4>, Lens<H4, H5>, Lens<H5, H6>>(l1, l2, l3, l4, l5);
}


} // namespace lenses

#endif // BIND_COMBINATOR_H
