#ifndef ATHENA_FILE
#define ATHENA_FILE

#include <dirent.h>
#include <sys/types.h>

namespace athena {
    class File {
        public:
            File() = default;

            File(struct dirent* entity ) {
                if(entity != NULL) {
                    _entity = entity;
                }
            }

            char* getName() const noexcept {
                return _entity->d_name;
            }

            ino_t getInode() const noexcept {
                //
                // Return the inode number for the current file inside the
                // file system
                //
                return _entity->d_ino;
            }

            unsigned char getType() const noexcept {
                //
                // Return the type of the file. This functionality is not
                // supported in all the file systems
                //
                return _entity->d_type;
            }

        private:
            struct dirent* _entity; // Pointer to current file entity
    };

}

#endif
