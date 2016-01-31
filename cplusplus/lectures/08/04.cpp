#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <cstdlib>

class TAnimal {
    public:
        virtual ~TAnimal() {
            std::cout << "animal destryed" << std::endl;
        }
        virtual void Cry() const = 0;
};

class TCat : public TAnimal {
    private:
        std::string Name;
    public:
        TCat(const std::string &name)
            : Name(name)
        {}
        ~TCat() {
            std::cout << "cat destryed" << std::endl;
        }
        virtual void Cry() const {
            std::cout << "Hi, I'm cat " << Name << std::endl;
        }
};

class TDog : public TAnimal {
    private:
        int Number;
    protected:
        int GetNumber() const {
            return Number;
        }
    public:
        TDog(int number)
            : Number(number)
        {}
        ~TDog() {
            std::cout << "dog destryed" << std::endl;
        }
        virtual void Cry() const {
            std::cout << "Hi, I'm dog number " << Number << std::endl;
        }
};

class TBadDog : public TDog {
    public:
        TBadDog()
            : TDog(13)
        {}
        ~TBadDog() {
            std::cout << "bad dog destryed" << std::endl;
        }

        virtual void Cry() const {
            std::cout << "Hi, I'm bad dog number " << GetNumber() << std::endl;
            throw 1;
        }
};


TAnimal *CreateAnimal(const std::string &type,
          std::map<std::string, std::string> &args) {
    if (type == "cat")
        return new TCat(args["name"]);
    else if (type == "dog")
        return new TDog(atoi(args["number"].c_str()));
    else if (type == "baddog")
        return new TBadDog;
    else
        return NULL;
}

void Work() {
    std::string type;
    std::cin >> type;
    std::map<std::string, std::string> args;
    for (; ;) {
        std::string name, value;
        std::cin >> name;
        if (name == "stop")
            break;
        std::cin >> value;
        args[name] = value;
    }
    std::auto_ptr<TAnimal> animal(CreateAnimal(type, args));
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

