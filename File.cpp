#include <athena/File.h>

#include <dirent.h>
#include <iostream>
namespace athena {

    File::File(struct dirent* entity, bool ownsFile)
        : _entity(entity), _ownsFile(ownsFile) {
            /**
             * Do Nothing
             */
        }

    File::File(int fileDescriptor, bool ownsFile) :
        _fileDescriptor(fileDescriptor), _ownsFile(ownsFile) {
            if(fileDescriptor < -1) {
                std::cerr << "File descriptor should be -1 or positive\n";
            }

            if(fileDescriptor == -1 and ownsFile == true) {
                std::cerr << "Cannot own a file with file descriptor -1\n";
            }
        }
}
