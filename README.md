C++ Lenses
==========

This is an experimental functional lenses built on C++.

Features:
- Infinite lenses chains.
- `to` composition combinator to chain lenses well.
- Not fully generic traversing of std::vectors and std::lists (alpha).
- Macroses for autolenses.
- `set`, `view`, `over` combinators.
- Experimental not generic folding and `toListOf`, `toVectorOf` combinators.

```
struct Address
{
    std::string city;
    std::string street;
    int house;
    int flat;
};

struct Person
{
    std::string name;
    std::string surname;
    int age;
    Address address;

    std::vector<Car> cars;
};

struct Account
{
    Person person;
    std::string login;
    std::string password;
};

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

void lensTest()
{
    Account acc = getAccount();
    QVERIFY(acc.person.address.house == 20);
    QVERIFY(acc.person.address.street == "Brooklin");

    auto houseLens = personL() to addressL() to houseL();
    auto streetLens = personL() to addressL() to streetL();

    std::function<int(int)> modifier = [](int old) { return old + 6; };

    Account newAcc1 = lenses::set(streetLens, acc, std::string("Churchill's"));
    Account newAcc2 = over(houseLens, newAcc1, modifier);

    QVERIFY(newAcc1.person.address.house == 20);
    QVERIFY(newAcc1.person.address.street == "Churchill's");
    QVERIFY(newAcc2.person.address.house == 26);
    QVERIFY(newAcc2.person.address.street == "Churchill's");
    QVERIFY(acc.person.address.house == 20);
    QVERIFY(acc.person.address.street == "Brooklin");
}
```
