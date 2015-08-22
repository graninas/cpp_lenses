#ifndef STRUCT_LENSES_H
#define STRUCT_LENSES_H

#include "../lenses.h"
#include "../autolens.h"

#include "address.h"
#include "person.h"
#include "account.h"

namespace sample
{

using namespace lenses;


MK_LENS(Car, std::string, number)
MK_LENS(Car, std::string, model)
MK_LENS(Car, int, mileage)
MK_LENS(Car, std::list<std::string>, accessories)

MK_LENS(Address, std::string, city)
MK_LENS(Address, std::string, street)
MK_LENS(Address, int, house)
MK_LENS(Address, int, flat)

MK_LENS(Person, std::string, name)
MK_LENS(Person, std::string, surname)
MK_LENS(Person, int, age)
MK_LENS(Person, Address, address)
MK_LENS(Person, std::vector<Car>, cars)

MK_LENS(Account, Person, person)
MK_LENS(Account, std::string, login)
MK_LENS(Account, std::string, password)


} // namespace sample

#endif // STRUCT_LENSES_H
