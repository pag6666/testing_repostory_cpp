#pragma once
#include <string>
#include <iostream>
namespace mem {
    struct mem_node final{
        mem_node ():mem_node("") {}
        mem_node(std::string commit) {
            this->commit = commit;
            this->next = nullptr;
        }
        std::string commit;
        mem_node* next;
    };
    
    class mem_commit final {
        private:
            mem_node* root;
        public:
            void add_commit(std::string commit) {
                mem_node* node = new mem_node(commit);
                if (root == nullptr) {
                    root = node;
                } else {
                    mem_node* current = root;
                    while(current->next) {
                        current = current->next;
                    }
                    current->next = node;
                }
            }
            void log_commit() {
                mem_node* current = root;
                while (current) {
                    std::cout << "commit: "<< current->commit.c_str() << std::endl;
                    current = current->next;
                }
            }
            ~mem_commit() {
                mem_node* current = root;
                while(current) {
                    mem_node* next = current->next;
                    delete current;
                    current = next;
                }
            }
    };
}