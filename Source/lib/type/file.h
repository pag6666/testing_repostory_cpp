#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace fi
{
    struct file{
        std::wstring path;
        std::size_t size_file;
        std::vector<std::wstring> lines;
        std::wstring type_file;
    };
    
    std::wstring getFileExtension(const std::wstring& filename) {
        std::size_t dotPosition = filename.find_last_of(L'.');
        if (dotPosition != std::wstring::npos && dotPosition != 0) {
            return filename.substr(dotPosition);
        }
        return L""; 
    }
    
    fi::file* make_file(std::wstring path) {
        fi::file* file = new fi::file();
        std::wifstream ifstream(path.c_str());
        if(!ifstream) {
            //error
            exit(EXIT_FAILURE);
        }
        std::vector<std::wstring> lines;
        std::wstring line;

        while(std::getline(ifstream, line)) {
            lines.push_back(line);
        }

        ifstream.seekg(0, std::ios::end);
        std::streamsize size = ifstream.tellg(); 
        ifstream.seekg(0, std::ios::beg);
        ifstream.close();

        file->path = path;
        file->size_file = size;
        file->lines = lines;
        file->type_file = getFileExtension(path);
        return file;
    }

    void print_file(fi::file* file) {
        std::wcout << L"{ path:= " << file->path 
        << L", size_file:= " << file->size_file 
        << ", type_file:= " << file->type_file << L"}" 
        << std::endl;
    }
}
