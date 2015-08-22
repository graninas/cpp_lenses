#ifndef AUTOLENS_H
#define AUTOLENS_H

#include "fold.h"
#include "lenses.h"
#include "getter.h"
#include "setter.h"

#include <functional>

namespace lenses
{

#define MK_FOLD(A, B, member) Fold<A, B> member##L() { \
    return fold<A, B> ( GETTER(A, member) }

#define MK_LENS(A, B, member) Lens<A, B> member##L() { \
    return lens<A, B> ( GETTER(A, member) \
                      , SETTER(A, B, member)); }


} // namespace lenses


#endif // AUTOLENS_H
