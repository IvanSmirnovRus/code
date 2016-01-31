#include <iostream>
#include <string>
#include <memory>

class TAnimal {
    public:
        virtual ~TAnimal() {
            std::cout << "animal destryed" << std::endl;
        }
        virtual void Cry() const = 0;
};

class TCat : public TAnimal {
    public:
        ~TCat() {
            std::cout << "cat destryed" << std::endl;
        }
        virtual void Cry() const {
            std::cout << "Hi, I'm cat" << std::endl;
        }
};

class TDog : public TAnimal {
    public:
        ~TDog() {
            std::cout << "dog destryed" << std::endl;
        }
        virtual void Cry() const {
            std::cout << "Hi, I'm dog" << std::endl;
        }
};

class TBadDog : public TDog {
    public:
        ~TBadDog() {
            std::cout << "bad dog destryed" << std::endl;
        }

        virtual void Cry() const {
            std::cout << "Hi, I'm bad dog" << std::endl;
            throw 1;
        }
};


TAnimal *CreateAnimal(const std::string &type) {
    if (type == "cat")
        return new TCat;
    else if (type == "dog")
        return new TDog;
    else if (type == "baddog")
        return new TBadDog;
    else
        return NULL;
}

void Work() {
    std::string type;
    std::cin >> type;
    std::auto_ptr<TAnimal> animal(CreateAnimal(type));
    if (animal.get() != NULL) {
        animal->Cry();
        //xxx
    }
}

int main() {
    try {
        Work();
    } catch (...) {
        std::cout << "Exception caught" << std::endl;
    }
}

