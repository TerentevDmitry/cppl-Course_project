// Курс «Продвинутое программирование на C++», профессия «Разработчик на С++»
// Курсовой проект «Парсер INI-файлов»

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

#include "parser.h"

int main()
{
    setlocale(LC_ALL, "ru");

    try 
    {
        iniParser pars1("cppl_course_project.ini");

        //auto value1 = pars1.getValue<std::string>("Section1", "var1");
        //auto value2 = pars1.getValue<std::string>("Section1", "var2");
        //auto value3 = pars1.getValue<std::string>("Section2", "var1");
        //auto value4 = pars1.getValue<std::string>("Section2", "var2");
        //auto value5 = pars1.getValue<std::string>("Section3", "var1");
        //auto value6 = pars1.getValue<std::string>("Section4", "Mode");
        //auto value7 = pars1.getValue<std::string>("Section4", "Vid");
        //auto value8 = pars1.getValue<std::string>("Section5", "var1");
        //auto value9 = pars1.getValue<std::string>("Section5", "var2");
        //auto value10 = pars1.getValue<std::string>("Section5", "var3");
        //auto value11 = pars1.getValue<std::string>("Section99", "unvar1");

        std::cout << pars1.getValue<std::string>("Section1", "var2") << std::endl;
        std::cout << pars1.getValue<int>("Section1", "var1") << std::endl;
        std::cout << pars1.getValue<float>("Section1", "var1") << std::endl;
        std::cout << pars1.getValue<double>("Section1", "var1") << std::endl;

    }
    catch (const std::runtime_error& ex)
    {
        std::cout << "Error when reading the ini file: " << ex.what() << std::endl;
    }
    catch (const std::out_of_range& ex)
    {
        std::cout << "The string cannot be converted to an ini number. " << ex.what() << std::endl;
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << "The string cannot be converted to an ini number. " << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Something new" << std::endl;
    }

    return 0;
}