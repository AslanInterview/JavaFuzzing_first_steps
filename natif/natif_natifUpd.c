#include "natif_natifUpd.h"
#include <stdlib.h>
#include <sys/shm.h>




#define LIBAFL_SHMEM_NAME "__AFL_SHM_ID"
#define MAP_SIZE 65536
#define env_size 100

char *__afl_area_ptr = NULL; //[MAP_SIZE];

int _afl_prev_loc = 0;




void DumpHex(const void* data, size_t size) {
	char ascii[17];
	size_t i, j;
	ascii[16] = '\0';
	for (i = 0; i < size; ++i) {
		fprintf(stderr, "%02X ", ((unsigned char*)data)[i]);
		if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') {
			ascii[i % 16] = ((unsigned char*)data)[i];
		} else {
			ascii[i % 16] = '.';
		}
		if ((i+1) % 8 == 0 || i+1 == size) {
			fprintf(stderr, " ");
			if ((i+1) % 16 == 0) {
				fprintf(stderr, "|  %s \n", ascii);
			} else if (i+1 == size) {
				ascii[(i+1) % 16] = '\0';
				if ((i+1) % 16 <= 8) {
					fprintf(stderr, " ");
				}
				for (j = (i+1) % 16; j < 16; ++j) {
					fprintf(stderr, "   ");
				}
				fprintf(stderr, "|  %s \n", ascii);
			}
		}
	}
}




JNIEXPORT void JNICALL Java_natif_natifUpd_mapUp(JNIEnv *, jclass, int i) {


  unsigned int j;
  j = (_afl_prev_loc ^ i);
  j %= MAP_SIZE;


  // Prepare the shmem id once
  // TODO: Check for failures
  if (__afl_area_ptr == NULL) {
    const char *shmem_name = getenv(LIBAFL_SHMEM_NAME);
    int fuzzid = atoi(shmem_name);
    char *tmp = 0;


    tmp = shmat(fuzzid, 0, 0);
    *tmp = 1;
    __afl_area_ptr = tmp;

    fprintf(stderr, "\n\n\nafl shared data pointer: %p\n\n\n", __afl_area_ptr);
    __afl_area_ptr[j]++;
    _afl_prev_loc = i >> 1; // Hva faen?


    DumpHex(__afl_area_ptr, 40);
  } else {
	
    fprintf(stderr, "\n\n\n__afl_area_ptr was initialized and pointing to: %p\n\n\n", __afl_area_ptr);
    __afl_area_ptr[j]++;
    _afl_prev_loc = i >> 1; // Hva faen?
    DumpHex(__afl_area_ptr, 40);
  }

}
