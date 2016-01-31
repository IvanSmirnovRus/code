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

class TAnimalCreator {
    public:
        virtual TAnimal *CreateObject(std::map<std::string, std::string> &args) const = 0;
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

class TCatCreator : public TAnimalCreator {
    public:
        virtual TAnimal *CreateObject(std::map<std::string, std::string> &args) const {
            return new TCat(args["name"]);
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

class TDogCreator : public TAnimalCreator {
    public:
        virtual TAnimal *CreateObject(std::map<std::string, std::string> &args) const {
            return new TDog(atoi(args["number"].c_str()));
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

class TBadDogCreator : public TDogCreator {
    public:
        virtual TAnimal *CreateObject(std::map<std::string, std::string> &) const {
            return new TBadDog;
        }
};

class TAnimalFactory {
    private:
        std::map<std::string, TAnimalCreator*> Creators;
        TAnimalFactory() {}
        TAnimalFactory(const TAnimalFactory &);
        TAnimalFactory &operator = (const TAnimalFactory &);
        ~TAnimalFactory() {}
    public:
        static TAnimalFactory &Instance() {
            static TAnimalFactory Factory;
            static bool IsInitialized = false;
            static TCatCreator CatCreator;
            static TDogCreator DogCreator;
            static TBadDogCreator BadDogCreator;
            if (!IsInitialized) {
                IsInitialized = true;
                Factory.RegisterCreator("cat", &CatCreator);
                Factory.RegisterCreator("dog", &DogCreator);
                Factory.RegisterCreator("baddog", &BadDogCreator);
            }
            return Factory;
        }
        TAnimal *CreateObject(const std::string &type,
                  std::map<std::string, std::string> &args) {
            std::map<std::string, TAnimalCreator*>::const_iterator it = Creators.find(type);
            if (it == Creators.end())
                return NULL;
            return it->second->CreateObject(args);
        }
        void RegisterCreator(const std::string &type, TAnimalCreator *obj) {
            Creators[type] = obj;
        }
};

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
    std::auto_ptr<TAnimal> animal(TAnimalFactory::Instance().CreateObject(type, args));
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

