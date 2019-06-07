#include <global.h>

#include <omp.h>

int main(int argc, char** argv){
	
	uint8_t ntasks = 5;
	
	#pragma omp parallel num_threads(ntasks)
	{
		uint32_t id;
		id =  omp_get_thread_num();
		printf("Hola  [%d]\n", id);
		printf("Mundo [%d]\n", id);
	}
	
	
	return(EXIT_SUCCESS);
}

