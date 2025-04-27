#include "tasks.h"
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <fstream>
#include <algorithm>

std::wstring task1(std::wstring str) {
    int blankIndex = -1;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == L' ') {
            blankIndex = i;
        }
    }
    wchar_t ch = str[0];
    if (blankIndex != -1) {
        str[0] = str[blankIndex + 1];
        str[blankIndex + 1] = ch;
    }
    return str;
}

std::wstring task2(std::wstring str) {
    std::wstring newString;
    for (int i = 0; i <= str.length(); ++i) {
        if (std::isdigit(str[i])) {
            newString += str[i];
        }
    }
    return newString;
}

std::string removeExtraSpaces(const std::string& str) {
    std::string result;
    bool inSpace = false;

    for (wchar_t ch : str) {
        if (ch == L' ') {
            if (!inSpace) {
                result += ch;
                inSpace = true;
            }
        } else {
            result += ch;
            inSpace = false;
        }
    }

    if (result[0] == ' ') {
        result = result.substr(1);
    }
    if (result[result.size()-1] == ' ') {
        result = result.substr(0, result.size()-1);
    }
    return result;
}

void task3() {
    std::ifstream in;
    in.open("../output/text.txt");

    std::ofstream out;
    out.open("../output/task3.txt");

    if (in.is_open() && out.is_open()) {
        std::cout << "Opened" << std::endl;
        std::string line;
        while (std::getline(in, line)) {
            out << removeExtraSpaces(line) << std::endl;
        }
    }
    in.close();
    out.close();
}

