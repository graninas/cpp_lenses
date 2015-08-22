#include <QString>
#include <QtTest>

#include "../identity.h"
#include "../lenses.h"
#include "../fold.h"
#include "../traversed.h"
#include "../bind_combinator.h"
#include "../to_combinator.h"

#include "common.h"
#include "address.h"
#include "person.h"
#include "account.h"

#include "struct_lenses.h"


using namespace sample;

class LensTest : public QObject
{
    Q_OBJECT

public:
    LensTest();

    static Address getAddress();
    static Person getPerson();
    static Account getAccount();

private Q_SLOTS:

    void lensTest();

    void bindLCombinatorTest();
    void genericStack1Test();
    void genericStack2Test();
    void rerollStackTest();
    void toCombinatorTest();
    void traversed1LensTest();
    void traversed2LensTest();
    void traversed3LensTest();
    void viewCombinatorTest();

    void toListCombinatorTest();
    void overCombinatorTest();
    void setCombinatorTest();

    void setValueImplicitLensTest();
    void modifyValueOutlineLensTest();
    void modifyValueInlineLensTest();
};

LensTest::LensTest()
{
}

Address LensTest::getAddress()
{
    Address address;
    address.city = "New York";
    address.street = "Brooklin";
    address.house = 20;
    address.flat = 2;
    return address;
}

Person LensTest::getPerson()
{
    std::list<std::string> car1Accessories = {"Rug", "Tinting"};
    std::list<std::string> car2Accessories = {"Tinting", "Tuning"};

    Car car1 = {"x555xx", "Ford Focus", 0, car1Accessories};
    Car car2 = {"y555yy", "Toyota Corolla", 10000, car2Accessories};

    Person person;
    person.name = "Paul";
    person.surname = "Jonson";
    person.age = 29;
    person.address = getAddress();
    person.cars = {car1, car2};
    return person;
}

Account LensTest::getAccount()
{
    Account account;
    account.person = getPerson();
    account.login = "admin";
    account.password = "admin";
    return account;
}

void LensTest::lensTest()
{
    Account acc = getAccount();
    QVERIFY(acc.person.address.house == 20);
    QVERIFY(acc.person.address.street == "Brooklin");

    auto houseLens = personL() to addressL() to houseL();
    auto streetLens = personL() to addressL() to streetL();

    std::function<int(int)> modifier = [](int old) { return old + 6; };

    acc = set(streetLens, acc, std::string("Churchill's"));
    acc = over(houseLens, acc, modifier);

    QVERIFY(acc.person.address.house == 26);
    QVERIFY(acc.person.address.street == "Churchill's");
}

void LensTest::bindLCombinatorTest()
{
    auto zoomer1 = LS<Lens<Account, Person>, Lens<Person, Address>>(personL(), addressL());
    auto zoomer2 = LS<Lens<Account, Person>, Lens<Person, Address>, Lens<Address, int>>(personL(), addressL(), houseL());

    auto zoomer3_1 = bindL<Account, Person, Address, int>(personL(), addressL(), houseL());
    auto zoomer3_2 = bindL<Account, Person, Address>(personL(), addressL());
    auto zoomer3_3 = bindL(personL(), addressL());
    auto zoomer3_4 = bindL(personL(), addressL(), houseL());
}

void LensTest::genericStack1Test()
{
    auto zoomer = bindL(personL(), addressL(), houseL());

    Account acc = evalLens(zoomer, getAccount(), set(100));

    QVERIFY(acc.person.address.house == 100);
}

void LensTest::genericStack2Test()
{
    Person person = {"Name", "Surname", 10, Address(), {}};
    Account account = set(personL(), getAccount(), person);

    QVERIFY(account.person.name == "Name");
    QVERIFY(account.person.surname == "Surname");
}

void LensTest::rerollStackTest()
{
    LS<Lens<Account, Person>, Lens<Person, Address>> zoomer = bindL(personL(), addressL());
    LS<Lens<Account, Person>, Lens<Person, Address>, Lens<Address, int>> newZoomer = zoomer.reroll<Lens<Address, int>>(houseL());

    Account acc = evalLens(newZoomer, getAccount(), set(100));
    QVERIFY(acc.person.address.house == 100);
}

void LensTest::toCombinatorTest()
{
    auto zoomer1 = addressL() to houseL();

    LS<Lens<Account, Person>, Lens<Person, Address>, Lens<Address, int>> zoomer2 = (personL() to addressL()) to houseL();
    LS<Lens<Account, Person>, Lens<Person, Address>, Lens<Address, int>> zoomer3 = personL() to addressL() to houseL();

    Person pers  = set(zoomer1, getPerson(),  100);
    Account acc1 = set(zoomer2, getAccount(), 100);
    Account acc2 = set(zoomer3, getAccount(), 100);

    QVERIFY(pers.address.house == 100);
    QVERIFY(acc1.person.address.house == 100);
    QVERIFY(acc2.person.address.house == 100);
}

void LensTest::traversed1LensTest()
{
    auto zoomer = zoom(personL(), carsL(), traversed<Car>(), modelL());

    std::function<std::string(std::string)> variator = [](std::string) { return std::string("BMW x6"); };
    Account acc = over(zoomer, getAccount(), variator);

    QVERIFY(acc.person.cars.size() == 2);
    QVERIFY(acc.person.cars[0].model == "BMW x6");
    QVERIFY(acc.person.cars[1].model == "BMW x6");
}

void LensTest::traversed2LensTest()
{
    Car car1 = {"x555xx", "Ford Focus", 0, {}};
    Car car2 = {"y555yy", "Toyota Corolla", 10000, {}};

    std::vector<Car> cars = {car1, car2};

    auto zoomer = traversed<Car>() to modelL();

    std::function<std::string(std::string)> variator = [](std::string) { return std::string("BMW x6"); };
    std::vector<Car> result = over(zoomer, cars, variator);

    QVERIFY(result.size() == 2);
    QVERIFY(result[0].model == "BMW x6");
    QVERIFY(result[1].model == "BMW x6");
}

void LensTest::traversed3LensTest()
{
    auto zoomer = carsL() to traversed<Car>() to accessoriesL() to traversed<std::string>();

    Person p = set(zoomer, getPerson(), std::string("none"));

    QVERIFY(p.cars.size() == 2);
    QVERIFY(p.cars[0].accessories.size() == 2);
    QVERIFY(p.cars[0].accessories.front() == std::string("none"));
    QVERIFY(p.cars[0].accessories.back() == std::string("none"));
    QVERIFY(p.cars[1].accessories.size() == 2);
    QVERIFY(p.cars[1].accessories.front() == std::string("none"));
    QVERIFY(p.cars[1].accessories.back() == std::string("none"));
}

void LensTest::viewCombinatorTest()
{
    // TODO: remove type hint 'Address'.
    Address address = view<Address>(personL() to addressL(), getAccount());

    auto expectedAddr = getAddress();
    QVERIFY(address.city == expectedAddr.city);
    QVERIFY(address.flat == expectedAddr.flat);
    QVERIFY(address.house == expectedAddr.house);
    QVERIFY(address.street == expectedAddr.street);
}

void LensTest::toListCombinatorTest()
{
    Car car1 = {"x555xx", "Ford Focus", 0, {}};
    Car car2 = {"y555yy", "Toyota Corolla", 10000, {}};

    std::vector<Car> cars = {car1, car2};

    auto fC = foldedC<Car>();

    auto zoomer = zoom_Fold_(fC, modelL());
    std::list<std::string> result = toListOf(zoomer, cars);

    QVERIFY(result.size() == 2);
    QVERIFY(result.front() == "Ford Focus");
    QVERIFY(result.back() == "Toyota Corolla");
}

void LensTest::overCombinatorTest()
{
    auto zoomer = zoom(addressL(), houseL());

    std::function<int(int)> modifier = [](int old) { return old + 6; };

    Person newPerson = over(zoomer, getPerson(), modifier);

    QVERIFY(newPerson.address.house == 26);
}

void LensTest::setCombinatorTest()
{
    auto zoomer = zoom(addressL(), houseL());

    Person newPerson = set(zoomer, getPerson(), 100);

    QVERIFY(newPerson.address.house == 100);
}

void LensTest::setValueImplicitLensTest()
{
    auto zoomer = zoom(addressL(), houseL());

    Person newPerson = evalLens(zoomer, getPerson(), set(100));

    QVERIFY(newPerson.address.house == 100);
}

void LensTest::modifyValueOutlineLensTest()
{
    auto zoomer = zoom(addressL(), houseL());
    std::function<int(int)> modifier = [](int old) { return old + 6; };

    Person newPerson = evalLens(zoomer, getPerson(), modifier);

    QVERIFY(newPerson.address.house == 26);
}

void LensTest::modifyValueInlineLensTest()
{
    auto zoomer = zoom(addressL(), houseL());

    Person newPerson = evalLens(zoomer, getPerson(), modify(int, _value + 6));

    QVERIFY(newPerson.address.house == 26);
}

QTEST_APPLESS_MAIN(LensTest)

#include "tst_lens.moc"
