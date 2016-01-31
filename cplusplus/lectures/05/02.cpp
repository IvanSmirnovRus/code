#include <iostream>
#include <string>

class TAnimal {
    private:
        std::string Name;

    public:
        TAnimal(const std::string &name)
            : Name(name)
        {
        }
        const std::string &GetName() const {
            return Name;
        }
        void Run() {
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
        void Run() {
            std::cout << "TCat::Run()" << std::endl;
        }
};

void Walk(TAnimal &animal) {
    std::cout << animal.GetName() << std::endl;
    animal.Run();
}

void Walk(TCat &cat) {                          // overloaded function
    std::cout << cat.GetName() << std::endl;    // TAnimal::GetName is accessible for TCat object
    cat.Run();
}

int main() {
    TCat cat("Barsik");
    Walk(static_cast<TAnimal&>(cat));
    Walk(cat);
    return 0;
}

