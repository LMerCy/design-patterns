#include<iostream>
#include<memory>
class Singleton{
public:
    static Singleton* getInstance(){
        std::cout << "get instance" << std::endl;
        if(instance == nullptr)
            instance = new Singleton;
        return instance;
    };
    Singleton(Singleton &) = delete;
    Singleton& operator=(const Singleton&)=delete;
    ~Singleton(){
        std::cout << "decontructor" << std::endl;
    };
private:
    Singleton(){
        std::cout << "contruct!" << std::endl;
    };
    static Singleton* instance;
};
class FixedSingleton{
public:
    static std::shared_ptr<FixedSingleton> getInstance(){
        std::cout << "get instance" << std::endl;
        if(instance == nullptr){
            std::lock_guard<std::mutex> lk(m_mutex);
            if(instance == nullptr)
                instance = std::shared_ptr<FixedSingleton>(new FixedSingleton());
        }
        return instance;
    };
    FixedSingleton(FixedSingleton &) = delete;
    FixedSingleton& operator=(const FixedSingleton&)=delete;
    ~FixedSingleton(){
        std::cout << "decontructor fixedsingleton" << std::endl;
    };
private:
    FixedSingleton(){
        std::cout << "construct fixedSingleton" << std::endl;
    };
    static std::shared_ptr<FixedSingleton> instance;
    static std::mutex m_mutex;
};
class MeyersSingleton{
public:
    ~MeyersSingleton(){
        std::cout << "destroy MeyersSingleton" << std::endl;
    };
    MeyersSingleton(MeyersSingleton &)=delete;
    MeyersSingleton& operator=(const MeyersSingleton&)=delete;
    static MeyersSingleton & getInstance(){
        static MeyersSingleton instance;
        return instance;
    }
private:
    MeyersSingleton(){};
};
Singleton* Singleton::instance = nullptr;
std::shared_ptr<FixedSingleton> FixedSingleton::instance = nullptr;
std::mutex FixedSingleton::m_mutex;

int main(){
    // Singleton* single1 = Singleton::getInstance();
    // Singleton* single2 = Singleton::getInstance();
    // std::shared_ptr<FixedSingleton> single3 = FixedSingleton::getInstance();
    MeyersSingleton & single4 = MeyersSingleton::getInstance();
    // delete single1;
    // delete single2;
    return 0;
}