#include <iostream>
#include "../lib/mem/mem_commit.h"
int main(int argc, char* agrv []) {
    mem::mem_commit* mem = new mem::mem_commit();
    mem->add_commit("Hello this first commit");
    mem->add_commit("sdasdsa");
    
    mem->log_commit(); 
    return EXIT_SUCCESS;
}