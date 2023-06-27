
#include "natif_natifUpd.h"
#include <stdlib.h>
#include <sys/shm.h>

#define LIBAFL_SHMEM_NAME "__AFL_SHM_ID"
#define MAP_SIZE 65536
#define env_size 100

char *__afl_area_ptr = NULL; //[MAP_SIZE];
char *afl_shared_data = NULL;

JNIEXPORT void JNICALL Java_natif_natifUpd_mapUp(JNIEnv *, jclass, int i) {

  // Prepare the shmem id once
  // TODO: Check for failures
  if (afl_shared_data == NULL) {
    const char *shmem_name = getenv(LIBAFL_SHMEM_NAME);
    int fuzzid = atoi(shmem_name);

    fprintf(stderr, "fuzzid: %d\n", fuzzid);

    afl_shared_data = shmat(fuzzid, 0, 0);
    fprintf(stderr, "\n\n\nafl shared data pointer: %p\n\n\n", afl_shared_data);
  }

  // Getting the __afl_area_ptr
  if (__afl_area_ptr == NULL) {

    fputs("Ininting the __afl_area_ptr", stderr);
  }

  // if (shmem_name = getenv(LIBAFL_SHMEM_NAME)) {
  // int a = atoi(shmem_name);
  // void* b = shmat(a, 0, 0);
  // if (b == (void *)-1) {
  // //std::cerr << "\t[natif_natifUpd.so] shmat failed\n";
  // return;
  // }
  // fprintf(stderr, "Enviroment variable is %d\n", a);
  // //std::cerr << "\t[natif_natifUpd.so] Enviroment variable is: " <<
  // shmem_name << "\tConstant: "<< i << " [shmem+]" << std::endl; return;
  // } else {
  // fprintf(stderr, "\t[natif_natifUpd.so] unable to get the enviroment
  // variable\n");
  // //exit(-1);
  // }

  /*


  if(__afl_area_ptr == nullptr){
      mai = i;
      out << "on prend __afl_area_ptr" << std::endl;
      PVOID areaPtr = nullptr;

      GetEnvironmentVariable(TEXT("AFL_STATIC_CONFIG"), envbuff, env_size);
      if(GetLastError() == ERROR_ENVVAR_NOT_FOUND){
          out << "afl env static not found" << std::endl;
          out.close();
      }
      out << "afl env: " << envbuff << std::endl;
      fuzzid = strtok(envbuff, ":");
      strcpy(shm, "afl_shm_");
      strcat(shm, fuzzid);
      out << "afl shm: " << shm << std::endl;
      HANDLE mem = OpenFileMapping(FILE_MAP_ALL_ACCESS, false, shm);
      areaPtr = MapViewOfFile(mem, FILE_MAP_ALL_ACCESS, 0, 0, 0);
      if(areaPtr == nullptr){
         out << "shm value failed" << std::endl;
         out.close();
      }
      __afl_area_ptr = (char*)areaPtr;
  }

  __afl_area_ptr[j]++;

  prev = i >> 1; // pour contruire bien l'itiniraire
  out.close();
  */
}
