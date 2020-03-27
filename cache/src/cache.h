#ifndef CACHE_H
#define CACHE_H

#include "shell.h"

#ifndef DATA_CACHE_BLOCK_SIZE
#define DATA_CACHE_BLOCK_SIZE 32        // 32B
#endif

#ifndef DATA_CACHE_ASSOCIATE_WAYS
#define DATA_CACHE_ASSOCIATE_WAYS 8
#endif

#ifndef DATA_CACHE_SIZE
#define DATA_CACHE_SIZE (64 << 10)  // 64KB
#endif


#ifndef INSTR_CACHE_BLOCK_SIZE
#define INSTR_CACHE_BLOCK_SIZE 32        // 32B
#endif

#ifndef INSTR_CACHE_ASSOCIATE_WAYS
#define INSTR_CACHE_ASSOCIATE_WAYS 4
#endif

#ifndef INSTR_CACHE_SIZE
#define INSTR_CACHE_SIZE (8 << 10)  // 8KB
#endif





uint32_t datacache_read_32(uint32_t addr);

uint32_t datacache_write_32(uint32_t addr);

uint32_t instrcache_read_32(uint32_t addr);


struct cache_line_t
{
    uint32_t tag;
    uint8_t valid;
    uint8_t dirty;
    uint8_t *data;
};
typedef struct cache_line_t Cache_Line;

struct associate_cache_t
{
    int block_size;
    int size;
    int associate_ways;
    int associate_sets;
    Cache_Line **cache;
    
};




typedef struct associate_cache_t Associate_Cache;
extern Associate_Cache data_cache;
extern Associate_Cache instr_cache;






// interface of cache
void init_cache();
uint32_t data_cache_read_32(uint32_t addr);
uint32_t instr_cache_read_32(uint32_t addr);


#endif