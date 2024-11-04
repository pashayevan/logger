#include <iostream>
#include <utility>
#include <exception>

class Logger {
private:
    inline static int counter = 0;
    const int id;
public:
    Logger():id(++counter) {
        std::cout<<"Logger():"<<id<<"\n";
    }
    Logger(const Logger& other): id(++counter){
        std::cout<<"Logger(copy):"<<id<<"\n";
    }
    Logger& operator= (const Logger& other){
        std::cout<<"Logger=:"<<id<<"\n";
        return *this;
    }
    Logger(Logger&& other): id(--counter) {
        std::cout<<"Logger(&& )";
      }
    ~Logger(){
        --counter;
        std::cout<<"~Logger()"<<id<<"\n";
    }

};
class inheritedlogger: public Logger {
public:
    inheritedlogger() {
        std::cout<<"inherited Logger()";
    }
    ~inheritedlogger() {
        std::cout<<"~inherited Logger()\n";
    }
};

class C {
private:
    Logger x;
public:
    C() {
        std::cout<<"C()\n";
        Logger y;
        throw std::exception();
    }
    ~C() {
        std::cout<<"~C()\n";

    }

};

void f(const Logger& x) {
    std::cout<<"void f\n";
}
void f() {
    std::cout<<"f() func:\n";
    Logger x;
    throw std::exception();
}
int main() {
    /*
     f(Logger());
    std::cout<<"Hello\n";

    Logger x;
    f(x);
    std::cout<<"Bye\n";
    */
    //Logger xSSS1;
   // Logger x2=x1;
 //   Logger x3=Logger();
 //   Logger x4=std::move(x1);
   // x2=std::move(x1);
    //inheritedlogger();

    try {
        Logger x;
        f();
    }
    catch(const std::exception& ex) {
        std::cerr<<"something bad\n";
        return 1;
    }
    try {
        C c;
    }
    catch(const std::exception& ex) {
        std::cout<<"Error\n;";
    }
}