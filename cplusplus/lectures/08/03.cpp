#include <iostream>
#include <string>
#include <memory>


class TAnimal {
    public:
        virtual ~TAnimal() {
            std::cout << "animal destryed" << std::endl;
        }
        virtual void Cry() const = 0;
        void Walk() const { std::cout << "TAnimal::walk" << std::endl; }
};

typedef void (TAnimal::*TWalkMethod) () const;

class TCat : public TAnimal {
    public:
        ~TCat() {
            std::cout << "cat destryed" << std::endl;
        }
        virtual void Cry() const {
            std::cout << "Hi, I'm cat" << std::endl;
        }
        void Walk() const { std::cout << "TCat::walk" << std::endl; }
};

class TDog : public TAnimal {
    public:
        ~TDog() {
            std::cout << "dog destryed" << std::endl;
        }
        virtual void Cry() const {
            std::cout << "Hi, I'm dog" << std::endl;
        }
        void Walk() const { std::cout << "TDog::walk" << std::endl; }
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


TAnimal *CreateAnimal(const std::string &type, TWalkMethod &walkMethod) {
    if (type == "cat") {
        walkMethod = static_cast<TWalkMethod>(&TCat::Walk);
        return new TCat;
    } else if (type == "dog") {
        walkMethod = static_cast<TWalkMethod>(&TDog::Walk);
        return new TDog;
    } else if (type == "baddog") {
        walkMethod = static_cast<TWalkMethod>(&TDog::Walk);
        return new TBadDog;
    } else {
        walkMethod = NULL;
        return NULL;
    }
}

void Work() {
    std::string type;
    std::cin >> type;
    TWalkMethod meth;
    std::auto_ptr<TAnimal> animal(CreateAnimal(type, meth));
    if (animal.get() != NULL) {
        ((*animal).*meth)();
        (animal.get()->*meth)();
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

