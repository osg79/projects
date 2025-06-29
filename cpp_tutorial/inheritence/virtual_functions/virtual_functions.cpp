#include <iostream>
#include <string>

enum class VehicleType
{
    NONE = 0,
    HATCH = 1,
    SEDAN = 2,
    SUV = 3
};

std::ostream &operator<<(std::ostream &os, VehicleType vehicle_type)
{
    switch (vehicle_type)
    {
    case VehicleType::NONE:
        os << "None";
        break;
    case VehicleType::HATCH:
        os << "Hatch";
        break;
    case VehicleType::SEDAN:
        os << "Sedan";
        break;
    case VehicleType::SUV:
        os << "SUV";
        break;
    default:
        os.setstate(std::ios_base::failbit);
    }
    return os;
}

class Car
{
public:
    Car(float length, int number_of_doors, VehicleType type, std::string brand) : m_length{length}, m_number_of_doors{number_of_doors}, m_type{type}, m_brand{brand}
    {
        std::cout << "Car Constructor called" << std::endl;
    }

    // Virtual is required to call the correct destructors during inheritence based polymorphism
    virtual ~Car()
    {
        std::cout << "Car Destructor called" << std::endl;
    }

    virtual void drives()
    {
        std::cout << "Just drives on the road" << std::endl;
    }

    void show_specs() const
    {
        std::cout << "Length: " << m_length << std::endl;
        std::cout << "Number of doors: " << m_number_of_doors << std::endl;
        std::cout << "Vehicle type: " << m_type << std::endl;
        std::cout << "Brand: " << m_brand << std::endl;
    }

    float m_length{};
    int m_number_of_doors{};
    VehicleType m_type{};
    std::string m_brand{};
};

class Mazda2 : public Car
{
public:
    Mazda2(float length, int number_of_doors, VehicleType type, std::string brand) : Car(length, number_of_doors, type, brand)
    {
        std::cout << "Mazda2 Constructor called" << std::endl;
    }

    ~Mazda2()
    {
        std::cout << "Mazda2 Destructor called" << std::endl;
    }

    void drives() override
    {
        std::cout << "Zoom zoom! Fun to drive" << std::endl;
    }

    void special_features()
    {
        std::cout << "Good driving dynamics" << std::endl;
    }
};

class Mazda3 : public Car
{
public:
    Mazda3(float length, int number_of_doors, VehicleType type, std::string brand) : Car(length, number_of_doors, type, brand)
    {
        std::cout << "Mazda3 Constructor called" << std::endl;
    }

    ~Mazda3()
    {
        std::cout << "Mazda3 Destructor called" << std::endl;
    }

    void drives() override
    {
        std::cout << "Zap zap! Super fun to drive" << std::endl;
    }

    void special_features()
    {
        std::cout << "Great driving dynamics" << std::endl;
    }
};

int main()
{
    Car *default_car = new Car(1.0f, 4, VehicleType::NONE, "None");
    default_car->show_specs();
    default_car->drives();

    Mazda2 *mazda2 = new Mazda2(4.0f, 5, VehicleType::HATCH, "Mazda");
    mazda2->show_specs();
    mazda2->drives();
    mazda2->special_features();

    Car *car = new Mazda3(4.5f, 4, VehicleType::SEDAN, "Mazda");
    car->drives();
    // Dynamic dispatch
    car->show_specs();

    delete default_car;
    delete mazda2;
    delete car;
    return 0;
}