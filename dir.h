#ifndef ATHENA_DIR
#define ATHENA_DIR

#include <dirent.h>
#include <vector>

#include "file.h"

namespace athena {
    class Dir {
        public:
            Dir() = default;

            Dir(char* path);

            ~Dir() {
                closedir(_rootDirectory);
            }

            std::vector<File>& getFiles() noexcept {
                return _files;
            }

        private:
            char* _rootPath; // The path where the object created points
            DIR* _rootDirectory; // Pointer to root directory
            //
            // The dirent method readdir returns a pointer to an struct of
            // type dirent. In order to reduce complexity inside this class
            // and add more functionalities to files objects, wrap them inside
            // a File object.
            //
            // As a directory is a container for multiple files, add
            // keep all the files inside a vector to iterate over them
            //
            std::vector<File> _files;
    };

}

#endif
