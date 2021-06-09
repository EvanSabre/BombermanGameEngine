/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <string>
#include <dlfcn.h>
#include <iostream>

template<typename T>
class DLLoader {
    public:
        DLLoader(std::string file) {
            _handle = dlopen(file.data(), RTLD_LAZY);
        };
        ~DLLoader() {
            if (_handle)
                dlclose(_handle);
        };
        T *getInstance() const {
            T *(*entry)();
            if (_handle == NULL) {
                return NULL;
            }
            entry = ((T * (*)())dlsym(_handle, "entryPoint"));
            if (entry == NULL)
                return NULL;
            return entry();
        }
    protected:
        void *_handle = NULL;
    private:
};
#endif /* !DLLOADER_HPP_ */
