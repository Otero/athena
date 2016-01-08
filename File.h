#ifndef ATHENA_FILE
#define ATHENA_FILE

#include <dirent.h>
#include <sys/types.h>

namespace athena {
    /**
     * A File represents an open file inside the current OS
     */
    class File {
        public:
            /**
             * Create a File object from an existing struct dirent.
             * Takes ownership of the file if ownsFile is true
             */
            File(struct dirent* entity, bool ownsFile = false );

            /*
             * Create a File object from an existing file descriptor.
             * Takes ownership of the file descriptor iw ownsFile is true
             */
            File(int fileDescriptor, bool ownsFile = false);

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
            int _fileDescriptor;
            bool _ownsFile;
    };
}

#endif
