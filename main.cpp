#include <iostream>
#include <dirent.h>

#include "dir.h"
#include "file.h"

int main(int argc, char* argv[]) {

    athena::Dir rootDirectory("."); // Create a reference to the root dir

    for( athena::File& file : rootDirectory.getFiles()) {
        std::cout << file.getName() << '\n';
    }

    return 0;
}
