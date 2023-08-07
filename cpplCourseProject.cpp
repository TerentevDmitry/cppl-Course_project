// Курс «Продвинутое программирование на C++», профессия «Разработчик на С++»
// Курсовой проект «Парсер INI-файлов»

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

#include "Parser.h"

//std::map<std::string, std::map<std::string, std::string>> parseIniFile(const std::string& filename) 
//{
//    std::map<std::string, std::map<std::string, std::string>> iniData;
//
//    std::ifstream file(filename);
//
//    if (!file.is_open()) {
//        throw std::runtime_error("Ошибка открытия файла: " + filename);
//    }
//
//    std::string currentSection;
//    std::string line;
//    while (std::getline(file, line)) {
//        // Пропускаем комментарии и пустые строки
//        if (line.empty() || line[0] == ';') 
//        {
//            continue;
//        }
//
//        if (line[0] == '[' && line[line.length() - 1] == ']') 
//        {
//            // Найден новый раздел
//            currentSection = line.substr(1, line.length() - 2);
//        }
//        else 
//        {
//            // Найдена строка с ключом и значением
//            std::istringstream iss(line);
//            std::string key;
//            std::string value;
//
//            if (std::getline(iss, key, '=')) 
//            {
//                if (std::getline(iss, value)) 
//                {
//                    size_t pos = line.find(';');  // находим позицию первого вхождения знака ";"
//
//                    if (pos != std::string::npos) // если знак найден
//                    {  
//                        value = line.substr(0, pos);  // обрезаем строку, оставляя только часть до знака ";"
//                    }
//                    iniData[currentSection][key] = value;
//                }
//            }
//        }
//    }
//
//    file.close();
//    return iniData;
//}

int main()
{
    setlocale(LC_ALL, "ru");

    try {
        
        iniParser pars1("cpplCourseProject.ini");

        auto value1 = pars1.getValue("Section1", "var1");
        auto value2 = pars1.getValue("Section1", "var2");
        auto value3 = pars1.getValue("Section2", "var1");
        auto value4 = pars1.getValue("Section2", "var2");
        auto value5 = pars1.getValue("Section3", "var1");
        auto value6 = pars1.getValue("Section4", "var1");
        auto value7 = pars1.getValue("Section5", "var1");
        
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка при чтении ini файла: " << e.what() << std::endl;
    }

    return 0;
}