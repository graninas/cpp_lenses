#ifndef GETTER_H
#define GETTER_H

namespace lenses
{

#define GETTER(A, b) [](const A& a) { return a.b; }

// TODO: remove type hint 'Focus'.
template <typename Focus, typename ST, typename Value>
Focus view(const ST& st, const Value& value)
{
    return st.get<Focus>(value);
}


} // namespace lenses


#endif // GETTER_H
