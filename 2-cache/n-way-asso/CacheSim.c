/**
 * CacheSim.c 
 * This program is designed for class exercise only.
 * It is provided as is. There is no warranty or support of any kind.
 *
 * Krerk Piromsopa, Ph.D.
 * Department of Computer Engineering
 * Chulalongkorn University
 * Bangkok, Thailand.
 * 
 * History
 * 2013 - Initial design
 * 2015 - Refactor/Clean code
**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <math.h>

#define CACHE_SIZE 1024*1
// #define CACHE_SIZE 1024*4
// #define CACHE_SIZE 1024*8
// #define CACHE_SIZE 1024*32
// #define CACHE_SIZE 1024*512
// #define CACHE_SIZE 1024*1024

#define BLOCK_SIZE 4

#define WAY 2

#define INDEX_SIZE (CACHE_SIZE/BLOCK_SIZE)/WAY

// 0 = RR, 1 = LRU
#define REPLACEMENT_ALGO 0

#define INDEXLEN ((int)log2(INDEX_SIZE))
#define OFFSETLEN ((int)log2(BLOCK_SIZE))
#define TAGLEN (32-INDEXLEN-OFFSETLEN)
typedef unsigned char Byte;
typedef unsigned char bool;
struct Cache{
    bool valid;
    bool dirty;
    unsigned long tag;
    Byte data[BLOCK_SIZE];
};

long MISS;
long HIT;
struct Cache cache[WAY][INDEX_SIZE];
int RR[INDEX_SIZE];
int init() {
	MISS=0;
	HIT=0;
	int i;
	for(int c=0;c<WAY;c++) {
		for(i=0;i<INDEX_SIZE;i++) {
			cache[c][i].valid=0;
			cache[c][i].tag=0;
			cache[c][i].dirty=0;
		}
	}
	for(i=0;i<INDEX_SIZE;i++) {
		RR[i] = 0;
	}
}
int calAddr(unsigned long addr,unsigned long *tag,unsigned long *idx,unsigned long *offset) {
	unsigned long tmp;
	int i;
	*tag=addr>>(OFFSETLEN+INDEXLEN);
	tmp=0;
	for(i=0;i<INDEXLEN;i++) {
		tmp<<=1;
		tmp|=0x01;
	}
	*idx=addr>>OFFSETLEN & tmp;
	tmp=0;
	for(i=0;i<OFFSETLEN;i++) {
		tmp<<=1;
		tmp|=0x01;
	}
	*offset=addr & tmp;
}
int access(unsigned long addr){
    unsigned long offset;
	unsigned long tag;
	unsigned long idx;
    int i;
	int valid=0;
	calAddr(addr,&tag,&idx,&offset);
	for(int c=0;c<WAY;c++) {
		if(cache[c][idx].tag==tag && cache[c][idx].valid){
			HIT++;
			return 0;
		}
	}
	// miss in all ways; need to kick someone
    MISS++;
	if(REPLACEMENT_ALGO == 0) { // RR
		cache[RR[idx]][idx].valid = 1;
		cache[RR[idx]][idx].tag = tag;
		RR[idx] = (RR[idx]+1) % WAY;
	} else { // LRU

	}
	// else{
    //     cache[idx].valid=1;
    //     cache[idx].tag = tag;
	// }

}
int main(int argc,char *argv[]){
    FILE *input;
    char buff[1025];
    unsigned long myaddr;
    // if (argc<2) {
	// 	fprintf(stderr,"Usage:\n\t%s address_file\n",argv[0]);
	// 	exit(-1);
	// }
    // input=fopen(argv[1],"r");
	input=fopen("gcc_ld_trace.txt","r");
    //read file
    while (fgets(& buff[0],1024,input)) {
		sscanf(buff,"0x%x",&myaddr);
        access(myaddr);
    }
    printf("HIT: %7d\nMISS:%7d\n",HIT,MISS);

}