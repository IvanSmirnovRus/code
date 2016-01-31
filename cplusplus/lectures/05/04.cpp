#include <iostream>

class TAnimal {
    public:
        void Run() {
            std::cout << "TAnimal::Run()" << std::endl;
        }
};

class TCat : public TAnimal {
    public:
        virtual void Run() {
            std::cout << "TCat::Run()" << std::endl;
        }
};

class TBlackProperty {
    public:
        int GetColor() {
            return 0;
        }
};

class TBlackCat : public TCat, public TBlackProperty {
    public:
        void Run() {
            std::cout << "TBlackCat::Run()" << std::endl;
        }
};

void Walk(TAnimal &animal) {
    animal.Run();
}

void WalkWithCat(TCat &cat) {
    cat.Run();
}

int main() {
    TBlackCat cat;
    Walk(cat);
    WalkWithCat(cat);
    return 0;
}

