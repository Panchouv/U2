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
	
	uint32_t total=1;
	#pragma omp parallel for reduction(*:total) num_threads(ntasks)
	for(size_t i = 0; i < 20; i++){
		#pragma omp critical
		{
			uint32_t id =  omp_get_thread_num();
			std::cout << "TH:" << id << "-> i=" << i << std::endl;
		}
		
		total += i;
	}
	
	std::cout << "Total:" << total << std::endl;
	
	
	return(EXIT_SUCCESS);
}

