#include "file.h"
#include <filesystem>
namespace di {
    
    struct direction {
        std::wstring path;
        std::vector<fi::file*> files;
    };
    
    di::direction* make_direction(std::wstring path) {
        di::direction* direct = new di::direction();
        direct->path = path;
        direct->files = std::vector<fi::file*>();

        std::vector<std::wstring> files_list;

        try {
            for (const auto& entry : std::filesystem::directory_iterator(path)) {
                if (entry.is_regular_file()) {
                    files_list.push_back(entry.path().wstring());
                }
            }

            for (std::wstring file : files_list) {
                direct->files.push_back(fi::make_file(file));
            }
        } catch (const std::filesystem::filesystem_error& e) {

        }
        return direct;
    }

    void print_direction(std::wstring path) {
        di::direction* direct = di::make_direction(path);
        std::wcout << L"direct:= " << direct->path << std::endl; 
        for (fi::file* file : direct->files) {
            std::wcout << "\tfile:= ";
            fi::print_file(file);
        }
    }
}