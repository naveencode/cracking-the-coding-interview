#include <string>
#include <iostream>
#include <chrono>
#include <ctime>

class Automobile {
    public:
        Automobile();
        Automobile(std::string newManufactureName, 
                    std::string newModelName,
                    int newModelYear);
        
        void setManufactureName(std::string newManufactureName);
        void setModelName(std::string newModelName);
        void setModelYear(int newModelYear);

        std::string getManufactureName();
        std::string getModelName();
        int getModelYear();

        //support methods
        std::string getDescription();
        int getAge();

    private:
        std::string _manufactureName;
        std::string _modelName;
        int _modelYear;

};

int Automobile::getAge() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm utc_tm = *gmtime(&t);

    int curr_year = utc_tm.tm_year + 1900;
    return curr_year - _modelYear;
}

std::string Automobile::getDescription() {
    std::string info = "";
    info += std::to_string(_modelYear) + " ";
    info += _manufactureName + " ";
    info += _modelName;
    return info;
}

Automobile::Automobile() {
    // sensible defaults
    _manufactureName = "";
    _modelName = "";
    _modelYear = -1;
}

Automobile::Automobile(std::string newManufactureName, std::string newModelName,
                        int newModelYear) {
    setManufactureName(newManufactureName);
    setModelName(newModelName);
    setModelYear(newModelYear);
}


void Automobile::setManufactureName(std::string newManufactureName) {
    // Validation?
    _manufactureName = newManufactureName;
}

void Automobile::setModelName(std::string newModelName) {
    // Validation?
    _modelName = newModelName;
}

void Automobile::setModelYear(int newModelYear) {
    // Validation?
    _modelYear = newModelYear;
}

std::string Automobile::getManufactureName() {
    return _manufactureName;
}

std::string Automobile::getModelName() {
    return _modelName;
}

int Automobile::getModelYear() {
    return _modelYear;
}

int main() {
    Automobile a("Chevrolet", "Impala", 1957);
    // std::cout << a.getModelYear() << std::endl;
    // std::cout << a.getDescription() << std::endl;
    std::cout << a.getAge();
    return 0;
}