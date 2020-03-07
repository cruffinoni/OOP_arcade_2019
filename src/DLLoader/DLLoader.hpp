/*
** EPITECH PROJECT, 2020
** OOP_boostrap_Arcade
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef OOP_ARCADE_DLLOADER_HPP
#define OOP_ARCADE_DLLOADER_HPP

#include <string>
#include <dlfcn.h>
#include "Exceptions.hpp"

namespace DLLoader {
    template <typename T>
    class DLLoader {
        public:
            typedef T *(*EntryPointPtrFunc)(void);
            static constexpr const char *entryPointName = "loadLibrary";

            explicit DLLoader(const std::string &DLLPath) : _dll(nullptr) {
                try {
                    this->loadDLL(DLLPath);
                } catch (const Exceptions::InvalidDLL &e) {
                    throw e;
                } catch (const Exceptions::InvalidEntryPoint &e) {
                    throw e;
                }
            }

            void changeDLL(const std::string &DLLPath) {
                if (this->_dll != nullptr)
                    dlclose(this->_dll);
                try {
                    this->loadDLL(DLLPath);
                } catch (const Exceptions::InvalidDLL &e) {
                    throw e;
                } catch (const Exceptions::InvalidEntryPoint &e) {
                    throw e;
                }
            }

            ~DLLoader() {
                if (this->_dll != nullptr)
                    dlclose(this->_dll);
            }

            T *getInstance() {
                return (this->_instance);
            }

        private:
            T *_instance;
            void *_dll;

            void loadDLL(const std::string &DLLPath) {
                EntryPointPtrFunc entryPointFunc;

                this->_dll = dlopen(DLLPath.c_str(), RTLD_LAZY);
                if (this->_dll == nullptr)
                    throw Exceptions::InvalidDLL(DLLPath);
                entryPointFunc = (EntryPointPtrFunc) dlsym(this->_dll, entryPointName);
                if (entryPointFunc == nullptr)
                    throw Exceptions::InvalidEntryPoint(DLLPath);
                this->_instance = entryPointFunc();
            }
    };
}


#endif //OOP_BOOSTRAP_ARCADE_DLLOADER_HPP
