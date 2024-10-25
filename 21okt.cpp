
#include <iostream>
#include <list>
class Logger {
private:
    int id=0;

public:
    Logger() {
        std::cout<<"Logger():"<<id<<"\n";
    }
    Logger(int x) {
        id=x;
        std::cout<<"Logger(int):"<<id<<"\n";
    }
    Logger& operator=(const Logger& other) {
        id=other.id;
        return *this;
    }
    ~Logger() {         //диструктер
        std::cout<<"~Logger()"<<id<<"\n";
    }
    Logger(const Logger& other) {    //конструктор копирования
        id=other.id;
        std::cout<<"Logger(copy)"<<"\n";
    }
};

//int main() {


  /*  Logger x1(1);
    {
        Logger x2(2);
    }
    Logger x3(3);
*/

    /*
    Logger* ptr1 = new Logger(1);
    Logger* ptr2 = new Logger(2);
    delete ptr1;
    delete ptr2;
    */
    /*
    std::list<Logger> loggers(2);
    loggers.pop_front();
    loggers.pop_back();
    */
/*
    Logger x1(1);
    Logger x2{x1};
    x2=x1;


    return 0;
}*/

