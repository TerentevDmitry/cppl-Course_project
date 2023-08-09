#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>




class iniParser
{
private:
	std::map<std::string, std::map<std::string, std::string>> iniData_;
    std::string filename_;
    std::string currentSection_;
    std::string line_;
    std::string key_;
    std::string value_;


public:
    iniParser(const std::string& filename) : filename_{ filename } 
    {
        std::ifstream file(filename_);

        if (!file.is_open())
        {
            throw std::runtime_error("Ошибка открытия файла: " + filename_);
        }

        while (std::getline(file, line_))
        {
            // Пропускаем комментарии и пустые строки
            if (line_.empty() || line_[0] == ';')
            {
                continue;
            }

            // Находим новый раздел
            if ((line_[0] == '[') && (line_[line_.length() - 1] == ']'))
            {
                // Найден новый раздел
                currentSection_ = line_.substr(1, line_.length() - 2);
            }
            else
            {
                // Найдена строка с ключом и значением
                std::istringstream iss(line_);
                
                if (std::getline(iss, key_, '='))
                {
                    if (std::getline(iss, value_))
                    {
                        size_t pos = value_.find(';');  // находим позицию первого вхождения знака ";"

                        if (pos != std::string::npos) // если знак найден
                        {
                            value_ = value_.substr(0, pos);  // обрезаем строку, оставляя только часть до знака ";"
                        }
                        iniData_[currentSection_][key_] = value_;
                    }
                }
            }
        }
        file.close();
    }

    template <class T>
    T getValue(T currentSection, T key)
    {
        std::map<std::string, std::map<std::string, std::string>>::iterator it1 = iniData_.find(currentSection);
        if (it1 == iniData_.end())
        {

            throw std::runtime_error(currentSection_ + " не найденa");
        }
        else
        {
            std::map<std::string, std::string>& innerMap = iniData_[currentSection];
            if (!innerMap.count(key))
            {
            //    std::cout << "В секции " << currentSection << " есть только ключи: " << std::endl;
            //    
            //    for (const auto& [s1, s2] : iniData_)
            //    {
            //        std::cout << s1 << std::endl;

            //        for (const auto& [k, v] : innerMap)
            //        {
            //            std::cout << k << " - " << v << std::endl;
            //        
            //        }
            //    }
                
                throw std::runtime_error("В секции " + currentSection + ", не найден ключ: " + key);
                //std::cout << "В секции " << currentSection << ", не найден ключ: " << key << std::endl;
            }
            else
            {
                std::cout << "Значение iniData_[" << currentSection << "][" << key << "]: " << iniData_[currentSection][key] << std::endl;
            }
        }
        return iniData_[currentSection][key];
    }
};