#include <iostream>

class TAnimal {
    public:
        void Run() {
            std::cout << "TAnimal::Run()" << std::endl;
        }
};

class TCat : public TAnimal {
    public:
        void Run() {
            std::cout << "TCat::Run()" << std::endl;
        }
};

void Walk(TAnimal &animal) {
    animal.Run();
}

void Walk(TCat &cat) {          // overloaded function
    cat.Run();
}

int main() {
    TCat cat;
    Walk(static_cast<TAnimal&>(cat));
    Walk(cat);
    return 0;
}

