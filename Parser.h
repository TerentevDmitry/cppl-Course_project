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
            throw std::runtime_error("������ �������� �����: " + filename_);
        }

        while (std::getline(file, line_))
        {
            // ���������� ����������� � ������ ������
            if (line_.empty() || line_[0] == ';')
            {
                continue;
            }

            // ������� ����� ������
            if ((line_[0] == '[') && (line_[line_.length() - 1] == ']'))
            {
                // ������ ����� ������
                currentSection_ = line_.substr(1, line_.length() - 2);
            }
            else
            {
                // ������� ������ � ������ � ���������
                std::istringstream iss(line_);
                
                if (std::getline(iss, key_, '='))
                {
                    if (std::getline(iss, value_))
                    {
                        size_t pos = value_.find(';');  // ������� ������� ������� ��������� ����� ";"

                        if (pos != std::string::npos) // ���� ���� ������
                        {
                            value_ = value_.substr(0, pos);  // �������� ������, �������� ������ ����� �� ����� ";"
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
        std::cout << "�������� iniData_[" << currentSection << "][" << key << "]: " << iniData_[currentSection][key] << std::endl;
        return 0;
    }








};

