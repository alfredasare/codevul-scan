#include <limits.h>  // for PATH_MAX
#include <string.h>  // for strncmp()

#define INTENDED_DIRECTORY "/path/to/intended/directory"

static inline int MagickReadDirectory(DIR *directory, struct dirent *entry,
                                      struct dirent **result)
{
    char intended_directory[PATH_MAX];
    strncpy(intended_directory, INTENDED_DIRECTORY, sizeof(intended_directory));

    // Validate the directory parameter
    if (strncmp(intended_directory, directory->dd_path, sizeof(intended_directory)) != 0)
    {
        return -1;  // Return an error code indicating invalid directory
    }

#if defined(MAGICKCORE_HAVE_READDIR_R)
    return readdir_r(directory, entry, result);
#else
    (void) entry;
    errno = 0;
    *result = readdir(directory);
    return errno;
#endif
}