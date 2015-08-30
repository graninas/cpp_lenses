#ifndef GETTER_H
#define GETTER_H

#include <list>

namespace lenses
{

#define GETTER(A, b) [](const A& a) { return a.b; }

// TODO: remove type hint 'Focus'.
template <typename Focus, typename LS, typename Value>
Focus view(const LS& stack, const Value& value)
{
    return stack.get<Focus>(value);
}



//Experimental

template <typename Focus, typename LS, typename Value>
std::list<Focus> toListOf(const LS& stack, const Value& value)
{
    //stack.getMany<Focus>(value);

    return std::list<Focus>();
}


} // namespace lenses


#endif // GETTER_H
