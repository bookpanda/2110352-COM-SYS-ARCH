/**
 * CacheSim.h
 * This program is designed for class exercise only.
 * It is provided as is. There is no warranty or support of any kind.
 *
 * Krerk Piromsopa, Ph.D.
 * Department of Computer Engineering
 * Chulalongkorn University
 * Bangkok, Thailand.
**/
#ifndef CACHESIM_H_INCLUDED
#define CACHESIM_H_INCLUDED

/* Please adjust parameters here */
// #define CACHE_SIZE 1024

#define CACHE_SIZE 4096
// #define CACHE_SIZE 8192
// #define CACHE_SIZE 16384
// #define CACHE_SIZE 32768

#define BLOCK_SIZE 4
// #define BLOCK_SIZE 8
// #define BLOCK_SIZE 16
// #define BLOCK_SIZE 32

// #define INDEX_SIZE 256
// #define INDEX_SIZE 512
#define INDEX_SIZE CACHE_SIZE/BLOCK_SIZE

#define TAGLEN 22
#define INDEXLEN 8
#define OFFSETLEN 2
typedef unsigned char Byte;
typedef unsigned char bool;
typedef struct Cache{
    bool valid;
    bool dirty;
    unsigned long tag;
	Byte data[BLOCK_SIZE];
};

#endif // CACHESIM_H_INCLUDED