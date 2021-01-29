#ifndef ETAG_H
#define ETAG_H
#include "first.h"

#include "buffer.h"

#ifdef _AIX
#include <sys/stat.h>
#else
struct stat;            /* declaration */
#endif

typedef enum { ETAG_USE_INODE = 1, ETAG_USE_MTIME = 2, ETAG_USE_SIZE = 4 } etag_flags_t;

int etag_is_equal(const buffer *etag, const char *matches, int weak_ok);
int etag_create(buffer *etag, const struct stat *st, int flags);
void etag_mutate(buffer *mut, const buffer *etag);


#endif
