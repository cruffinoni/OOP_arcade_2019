/*
** EPITECH PROJECT, 2020
** OOP_boostrap_Arcade
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_BOOSTRAP_ARCADE_DLLOADER_HPP
#define OOP_BOOSTRAP_ARCADE_DLLOADER_HPP

#include <string>
#include <dlfcn.h>

namespace DLLoader {
    template <typename T>
    class DLLoader {
        public:
            typedef T *(*EntryPointPtrFunc)(void);
            //static constexpr char *entryPoint = "hello";

            explicit DLLoader(const std::string &DLLPath) : _dll(nullptr) {
                void *dll = dlopen(DLLPath.c_str(), RTLD_LAZY);
                EntryPointPtrFunc entryPointFunc;

                if (dll == nullptr)
                    throw std::exception();
                entryPointFunc = ((EntryPointPtrFunc) (dlsym(dll, DLLPath.c_str())));
                if (entryPointFunc == nullptr)
                    throw std::exception();
                this->_instance = entryPointFunc();
            }

            ~DLLoader() {
                if (this->_dll != nullptr)
                    dlclose(this->_dll);
            }

            T *GetInstance() {
                return (this->_instance);
            }

        private:
            T *_instance;
            void *_dll;
    };
}


#endif //OOP_BOOSTRAP_ARCADE_DLLOADER_HPP
