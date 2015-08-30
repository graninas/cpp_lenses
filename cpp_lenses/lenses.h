#ifndef LENSES_H
#define LENSES_H

#include "identity.h"
#include "lens.h"
#include "lens_stack.h"
#include "bind_combinator.h"
#include "fold.h"
#include "traversed.h"

#include <functional>

namespace lenses
{

// N.B.! No copy-paste!
#define zoom bindL

} // namespace lenses

#endif // LENSES_H
