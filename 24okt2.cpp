#include <iostream>
#include <utility>
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
void f(const Logger& x) {
    std::cout<<"void f\n";
}
int main() {
    /*
     f(Logger());
    std::cout<<"Hello\n";

    Logger x;
    f(x);
    std::cout<<"Bye\n";
    */
    //Logger x1;
   // Logger x2=x1;
 //   Logger x3=Logger();
 //   Logger x4=std::move(x1);
   // x2=std::move(x1);
    inheritedlogger();
}