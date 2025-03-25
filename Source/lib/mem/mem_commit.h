#pragma once
#include <string>
#include <iostream>
#include "../type/direction.h"
namespace mem {
    struct mem_node final{
        mem_node ():mem_node("", nullptr) {}
        mem_node(std::string commit, di::direction* direct) {
            this->commit = commit;
            this->next = nullptr;
            this->direct = direct;
        }
        di::direction* direct;
        std::string commit;
        mem_node* next;
    };
    
    class mem_commit final {
        private:
            mem_node* root;
        public:
            void add_commit(std::string commit) {
                mem_node* node = new mem_node(commit, di::make_direction(L"C:\\Users\\SystemX\\Documents\\test"));
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