#ifndef TRAVERSED_H
#define TRAVERSED_H

#include "lens.h"

#include <functional>
#include <vector>

namespace lenses
{

// auto zoomer = zoom(personL(), carsL(), traversed(), modelL());
// Account -> Person
// --getter :: std::function<Person(Account)>
// --setter :: std::function<Account(Account&, Person)>

// Person -> std::vector<Car>
// --getter :: std::function<std::vector<Car>(Person)>
// --setter :: std::function<Person(Person&, std::vector<Car>)>

// std::vector<Car> -> ~Car
// --getterT :: std::function<~Car(std::vector<Car>)>
// --setterT :: std::function<std::vector<Car>(std::vector<Car>&, ~Car)>

// Car -> std::string
// --getter :: std::function<std::string(Car)>
// --setter :: std::function<Car(Car&, std::string)>

// TODO: remove explicit containers `vector` etc.
template <typename Value>
Lens<std::vector<Value>, Value> traversed()
{
    return Lens<std::vector<Value>, Value>();
}

}

#endif // TRAVERSED_H
