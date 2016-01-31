#include <iostream>
#include <string>
#include <memory>

class TAnimal {
    private:
        std::string Name;

    public:
        TAnimal(const std::string &name)
            : Name(name)
        {
        }
        virtual ~TAnimal() {
        }
        const std::string &GetName() const {
            return Name;
        }
        virtual void Run() {
            std::cout << "TAnimal::Run()" << std::endl;
        }
};

class TCat : public TAnimal {
    private:
        typedef TAnimal TParent;
    public:
        TCat(const std::string &name)
            : TParent(name)
        {
        }
        /*virtual*/ void Run() {
            std::cout << "TCat::Run()" << std::endl;
        }
};

class TDog : public TAnimal {
    private:
        typedef TAnimal TParent;
    public:
        TDog(const std::string &name)
            : TParent(name)
        {
        }
        /*virtual*/ void Run() {
            std::cout << "TDog::Run()" << std::endl;
        }
};

void Walk(TAnimal &animal) {
    std::cout << animal.GetName() << std::endl;
    animal.Run();
}

TAnimal *CreateAnimal() {
    std::cout << "Enter type of animal (cat/dog): ";
    std::string type, name;
    std::cin >> type;
    if (type == "cat") {
        std::cin >> name;
        return new TCat(name);
    } else if (type == "dog") {
        std::cin >> name;
        return new TDog(name);
    }
    return NULL;
}

int main() {
    std::auto_ptr<TAnimal> animal(CreateAnimal());
    if (animal.get() == NULL)
        return 0;
    Walk(*animal);
    return 0;
}

