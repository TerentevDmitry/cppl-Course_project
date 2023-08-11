#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <type_traits>

class iniParser
{
private:
	std::map<std::string, std::map<std::string, std::string>> iniData_;
    std::string filename_;
    std::string currentSection_;
    std::string line_;
    std::string key_;
    std::string value_;
    int tmpIniDataInt_ = 0;
    
    float tmpIniDataFloat_ = 0.0;


public:
    iniParser(const std::string& filename);

    //base
    template <class T>
    T getValue(const std::string currentSection, const std::string key)
    {
        //проверка совпадения типов данных
        static_assert(sizeof(T)==-1,"Invalid data type");

        //std::map<std::string, std::map<std::string, std::string>>::iterator it1 = iniData_.find(currentSection);
        //if (it1 == iniData_.end())
        //{
        //    throw std::runtime_error(currentSection_ + " not found");
        //}
        //else
        //{
        //    std::map<std::string, std::string>& innerMap = iniData_[currentSection];
        //    if (!innerMap.count(key))
        //    {
        //    //    std::cout << "В секции " << currentSection << " есть только ключи: " << std::endl;
        //    //    
        //    //    for (const auto& [s1, s2] : iniData_)
        //    //    {
        //    //        std::cout << s1 << std::endl;
        //    //        for (const auto& [k, v] : innerMap)
        //    //        {
        //    //            std::cout << k << " - " << v << std::endl;
        //    //        
        //    //        }
        //    //    }
        //        throw std::runtime_error("In the section " + currentSection + ", no key found: " + key);
        //    }
        //    else
        //    {
        //        std::cout << "Value [" << currentSection << "][" << key << "]: " << iniData_[currentSection][key] << std::endl;
        //    }
        //}
        //return iniData_[currentSection][key];
    }

    //std::string
    template <>
    std::string getValue(const std::string currentSection, const std::string key)
    {
        std::map<std::string, std::map<std::string, std::string>>::iterator it1 = iniData_.find(currentSection);
        if (it1 == iniData_.end())
        {
            throw std::runtime_error(currentSection_ + " not found");
        }
        else
        {
            std::map<std::string, std::string>& innerMap = iniData_[currentSection];
            if (!innerMap.count(key))
            {
                throw std::runtime_error("In the section " + currentSection + ", no key found: " + key);
            }
            else
            {
                std::cout << "Value [" << currentSection << "][" << key << "]: " << iniData_[currentSection][key] << std::endl;
            }
        }
        return iniData_[currentSection][key];
    }

    //int
    template <>
    int getValue(const std::string currentSection, const std::string key)
    {

        std::map<std::string, std::map<std::string, std::string>>::iterator it1 = iniData_.find(currentSection);
        if (it1 == iniData_.end())
        {
            throw std::runtime_error(currentSection_ + " not found");
        }
        else
        {
            std::map<std::string, std::string>& innerMap = iniData_[currentSection];
            if (!innerMap.count(key))
            {
                throw std::runtime_error("In the section " + currentSection + ", no key found: " + key);
            }
            else
            {
                std::cout << "Value [" << currentSection << "][" << key << "]: " << iniData_[currentSection][key] << std::endl;
            }
        }
        
        if (iniData_[currentSection][key].find("."))
        {
            std::cout << "Warning. Type of this value double or float converted to ini !!!" << std::endl;
        }
        
        try
        {
            tmpIniDataInt_ = std::stoi(iniData_[currentSection][key]);
        }
        catch (const std::out_of_range& ex)
        {
            throw ex;
        }
        catch (const std::invalid_argument& ex)
        {
            throw ex;
        }
        return tmpIniDataInt_;
    }

    //int
    template <>
    double getValue(const std::string currentSection, const std::string key)
    {

        std::map<std::string, std::map<std::string, std::string>>::iterator it1 = iniData_.find(currentSection);
        if (it1 == iniData_.end())
        {
            throw std::runtime_error(currentSection_ + " not found");
        }
        else
        {
            std::map<std::string, std::string>& innerMap = iniData_[currentSection];
            if (!innerMap.count(key))
            {
                throw std::runtime_error("In the section " + currentSection + ", no key found: " + key);
            }
            else
            {
                std::cout << "Value [" << currentSection << "][" << key << "]: " << iniData_[currentSection][key] << std::endl;
            }
        }
        double tmpIniDataDouble_ = 9.9999;
        try
        {
            tmpIniDataDouble_ = std::stod(iniData_[currentSection][key]);
        }
        catch (const std::out_of_range& ex)
        {
            throw ex;
        }
        catch (const std::invalid_argument& ex)
        {
            throw ex;
        }
        return tmpIniDataDouble_;
    }
   
    
    




};