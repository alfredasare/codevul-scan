#include <limits.h>
#include <pwd.h>
#include <string.h>

#ifdef HAVE_SYS_STATVFS_H
#include <sys/statvfs.h>
#else
#include <sys/vfs.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "system.h"

#define ISSLASH(x) ((x) == '/' || (x) == '\\')

/* Remove DIRECTORY and its subdirectories.  If RECURSIVE is nonzero,
   remove the subdirectories themselves, too; otherwise, only remove
   empty ones.  If VERBOSE is nonzero, print a message for each
   directory removed.