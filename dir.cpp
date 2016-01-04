#include <iostream>
#include <dirent.h>

#include "dir.h"
#include "file.h"

athena::Dir::Dir(char* path) {
    _rootPath = path;
    _rootDirectory = opendir(_rootPath);
    //
    // After opening the directory add all the files in the current directory
    // inside our vector. This method consumes to much memory when the
    // directory has a lot of files, so it should be improved in the near
    // future.
    //
    if (_rootDirectory != NULL) {
        struct dirent* temporalEntity;
        while(temporalEntity = readdir(_rootDirectory)) {
            _files.push_back(File(temporalEntity));
        }
    }
    else {
        std::cerr << "Directory not found" << std::endl;
    }
}
