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
#include <iostream>
#include "soLoader/Exceptions.hpp"

namespace SoLoader {
    template <typename T>
    class SoLoader {
        public:
            typedef T *(*EntryPointPtrFunc)(void);
            static constexpr const char *entryPointName = "loadLibrary";

            explicit SoLoader(const std::string &DLLPath) : _dll(nullptr) {
                try {
                    this->loadSo(DLLPath);
                } catch (const Exceptions::InvalidSO &e) {
                    throw e;
                } catch (const Exceptions::InvalidEntryPoint &e) {
                    throw e;
                }
            }

            SoLoader() : _instance(nullptr), _dll(nullptr) {
            }

            void changeSo(const std::string &DLLPath) {
                if (this->_dll != nullptr)
                    dlclose(this->_dll);
                try {
                    this->loadSo(DLLPath);
                } catch (const Exceptions::InvalidSO &e) {
                    throw e;
                } catch (const Exceptions::InvalidEntryPoint &e) {
                    throw e;
                }
            }

            ~SoLoader() {
                if (this->_dll != nullptr)
                    dlclose(this->_dll);
            }

            T *operator->() {
                if (this->_instance == nullptr)
                    std::cerr << "[SoLoader] The instance is null, you might not want to use that" << std::endl;
                return (this->_instance);
            }

            T *getInstance() {
                return (this->_instance);
            }

            std::string getLibPath() {
                return (this->_libPath);
            }

        private:
            T *_instance;
            void *_dll;
            std::string _libPath;

            void loadSo(const std::string &DLLPath) {
                EntryPointPtrFunc entryPointFunc;

                this->_dll = dlopen(DLLPath.c_str(), RTLD_LAZY);
                if (this->_dll == nullptr)
                    throw Exceptions::InvalidSO(DLLPath);
                entryPointFunc = (EntryPointPtrFunc) dlsym(this->_dll, entryPointName);
                if (entryPointFunc == nullptr)
                    throw Exceptions::InvalidEntryPoint(DLLPath);
                this->_instance = entryPointFunc();
                this->_libPath = DLLPath;
            }
    };
}

#endif //OOP_BOOSTRAP_ARCADE_DLLOADER_HPP
