// Курс «Продвинутое программирование на C++», профессия «Разработчик на С++»
// Курсовой проект «Парсер INI-файлов»

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

#include "Parser.h"

int main()
{
    setlocale(LC_ALL, "ru");

    try 
    {
        iniParser pars1("cpplCourseProject.ini");

        auto value1 = pars1.getValue<std::string>("Section1", "var1");
        auto value2 = pars1.getValue<std::string>("Section1", "var2");
        auto value3 = pars1.getValue<std::string>("Section2", "var1");
        auto value4 = pars1.getValue<std::string>("Section2", "var2");
        //auto value5 = pars1.getValue<std::string>("Section3", "var1");
        //auto value6 = pars1.getValue<std::string>("Section4", "Mode");
        //auto value7 = pars1.getValue<std::string>("Section4", "Vid");
        //auto value8 = pars1.getValue<std::string>("Section5", "var1");
        auto value9 = pars1.getValue<std::string>("Section5", "var2");
        //auto value10 = pars1.getValue<std::string>("Section5", "var3");
        //auto value11 = pars1.getValue<std::string>("Section99", "unvar1");
    }
    catch (const std::runtime_error& ex)
    {
        std::cout << "Ошибка при чтении ini файла: " << ex.what() << std::endl;
    }
    

    return 0;
}