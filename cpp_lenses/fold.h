#ifndef FOLD_H
#define FOLD_H

#include "identity.h"
#include "lenses.h"

#include <functional>
#include <algorithm>
#include <list>

namespace lenses
{

/*
template <typename Folded, typename Contained>
struct Fold
{

};

// TODO: generalize hardcoded vector.
template <typename Contained, typename Folded = std::vector<Contained>>
Fold<std::vector<Contained>, Contained> foldedC()
{
    return Fold<std::vector<Contained>, Contained>();
}

template <typename Folded, typename Contained, typename Zoomed1>
struct FoldStack
{
    Fold<Folded, Contained> fold1;
    Lens<Contained, Zoomed1> fold2;
};

template <typename Folded, typename Contained, typename Zoomed1>
FoldStack<Folded, Contained, Zoomed1>
    zoom_Fold_(const Fold<Folded, Contained>& f1,
               const Lens<Contained, Zoomed1>& f2)
{
    FoldStack<Folded, Contained, Zoomed1> fs;
    fs.fold1 = f1;
    fs.fold2 = f2;
    return fs;
}

// TODO: remove explicit containers `vector` etc.
template <typename Folded, typename Contained, typename Zoomed1>
std::vector<Zoomed1> toVectorOf(const FoldStack<Folded, Contained, Zoomed1>& stack,
                                const std::vector<Contained>& items)
{
    std::vector<Zoomed1> zoomedItems;
    std::for_each(items.cbegin(), items.cend(), [&](const Contained& it)
    {
        auto val = stack.fold2.getter(it);
        zoomedItems.push_back(val);
    });

    return zoomedItems;
}

// TODO: remove explicit containers `vector` etc.




template <typename Folded, typename Contained, typename Zoomed1>
std::list<Zoomed1> toListOf(const FoldStack<Folded, Contained, Zoomed1>& stack,
                            const std::vector<Contained>& items)
{
    std::list<Zoomed1> zoomedItems;
    std::for_each(items.cbegin(), items.cend(), [&](const Contained& it)
    {
        auto val = stack.fold2.getter(it);
        zoomedItems.push_back(val);
    });

    return zoomedItems;
}
*/


}

#endif // FOLD_H
