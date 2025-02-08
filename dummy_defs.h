// dummy_defs.h
#ifndef DUMMY_DEFS_H
#define DUMMY_DEFS_H

#ifndef NULL
#define NULL 0
#endif

// Provide a minimal definition for trace_iterator
struct trace_iterator {
    int idx;
};

#endif // DUMMY_DEFS_H
