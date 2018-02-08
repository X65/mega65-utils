#ifndef BUSE_H_INCLUDED
#define BUSE_H_INCLUDED
#ifdef USE_BUSE

#ifdef __cplusplus
extern "C" {
#endif
  
  /* Most of this file was copied from nbd.h in the nbd distribution. */
#include <linux/types.h>
#include <sys/types.h>
#include <linux/nbd.h>

  struct buse_operations {
    int (*read)(void *buf, u_int32_t len, u_int64_t offset, void *userdata);
    int (*write)(const void *buf, u_int32_t len, u_int64_t offset, void *userdata);
    void (*disc)(void *userdata);
    int (*flush)(void *userdata);
    int (*trim)(u_int64_t from, u_int32_t len, void *userdata);

    // either set size, OR set both blksize and size_blocks
    u_int64_t size;
    u_int32_t blksize;
    u_int64_t size_blocks;
  };

  int buse_main(const char* dev_file, const struct buse_operations *bop, void *userdata);

#ifdef __cplusplus
}
#endif

#endif
#endif /* BUSE_H_INCLUDED */
