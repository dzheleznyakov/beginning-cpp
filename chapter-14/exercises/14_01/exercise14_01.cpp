#include <iostream>
#include <vector>

#include "Animal.h"
#include "Sheep.h"
#include "Dog.h"
#include "Cow.h"
#include "Zoo.h"

using std::vector;

int main()
{
    Zoo zoo{};
    Sheep dolly{"Dolly", 100};
    Cow zorka("Zorka", 800);
    Dog bobik{"Bobik", 41};

    zoo.addAnimal(&dolly);
    zoo.addAnimal(&zorka);
    zoo.addAnimal(&bobik);
    zoo.addAnimal(new Dog("Sharik", 52));

    vector<string> zooReport = zoo.whoIsInZoo();
    for (string s : zooReport)
        std::cout << s << std::endl;

    std::cout << std::endl;
    zoo.printResidentsReport();

    std::cout << std::endl;
    zoo.printResidentsSounds();
}
