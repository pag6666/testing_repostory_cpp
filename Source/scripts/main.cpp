#include <iostream>
#include "../lib/mem/mem_commit.h"
#include "../lib/type/file.h"
int main(int argc, char* agrv []) {
    mem::mem_commit* mem = new mem::mem_commit();
    mem->add_commit("Hello this first commit");
    mem->add_commit("sdasdsa");
    mem->log_commit(); 
    fi::file* file = fi::make_file(L"C:\\Users\\SystemX\\Documents\\test\\sd.txt");
    fi::print_file(file);

    delete file;
    return EXIT_SUCCESS;
}