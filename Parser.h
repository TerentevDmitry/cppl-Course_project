#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>



//template <class T>
class iniParser
{
private:
	std::map<std::string, std::map<std::string, std::string>> iniData;
    std::string filename = "cpplCourseProject.ini";


public:
	//Parser(T x, T y, T z) : var1_{ x }, var2_{ y }, var3_{ z } {}


    // ���� ���
    std::map<std::string, std::map<std::string, std::string>> parseIniFile(const std::string& filename)
    {
        std::ifstream file(filename);

        if (!file.is_open()) 
        {
            throw std::runtime_error("������ �������� �����: " + filename);
        }

        std::string currentSection;
        std::string line;
        while (std::getline(file, line)) 
        {
            // ���������� ����������� � ������ ������
            if (line.empty() || line[0] == ';')
            {
                continue;
            }

            if (line[0] == '[' && line[line.length() - 1] == ']')
            {
                // ������ ����� ������
                currentSection = line.substr(1, line.length() - 2);
            }
            else
            {
                // ������� ������ � ������ � ���������
                std::istringstream iss(line);
                std::string key;
                std::string value;

                if (std::getline(iss, key, '='))
                {
                    if (std::getline(iss, value))
                    {
                        size_t pos = line.find(';');  // ������� ������� ������� ��������� ����� ";"

                        if (pos != std::string::npos) // ���� ���� ������
                        {
                            value = line.substr(0, pos);  // �������� ������, �������� ������ ����� �� ����� ";"
                        }
                        iniData[currentSection][key] = value;
                    }
                }
            }
        }
        file.close();
        return iniData;
    }
};

