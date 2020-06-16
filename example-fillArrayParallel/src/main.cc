#include <global.h>
#include <checkArgs.hpp>


uint64_t* g_numbers = nullptr;



void fillArray(size_t beginIdx, size_t endIdx, size_t RNEtype) {
	//Used for std::rand
	std::srand(std::time(0)); //current time as seed 
	
	//Used for std::uniform_int_distribution
	std::random_device device;
	std::mt19937 rng(device());
	std::uniform_int_distribution<> unif(0, RAND_MAX);
	
	for(size_t i = beginIdx; i < endIdx; ++i){		
		switch(RNEtype){
			case 0: 
				g_numbers[i] = std::rand(); //<== Not thread safe
				break;
			case 1:
				g_numbers[i] = unif(rng);
				break;
		}
	}
}


int main(int argc, char** argv)
{
	uint64_t totalElementos;

	auto argumentos = (std::shared_ptr<checkArgs>) new checkArgs(argc, argv);
	
	totalElementos = argumentos->getArgs().totalElementos;
	
	size_t RNEtype = argumentos->getArgs().RNEtype;

	// ======LLENADO DE LA ESTRUCTURA CON NUMEROS==Secuencial
	g_numbers = new uint64_t[totalElementos];
	auto start = std::chrono::high_resolution_clock::now();
	
	fillArray(0, totalElementos, RNEtype);
	
	auto end     = std::chrono::high_resolution_clock::now(); 
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	auto totalTimeFill_secuencial = elapsed.count();
	
	delete[] g_numbers;
	
	// ======LLENADO DE LA ESTRUCTURA CON NUMEROS==Threads
	g_numbers = new uint64_t[totalElementos];
	start = std::chrono::high_resolution_clock::now();
	
	std::thread llenado_t1(fillArray, 0, totalElementos / 2, RNEtype);
	std::thread llenado_t2(fillArray, totalElementos / 2, totalElementos, RNEtype);	
	llenado_t1.join();
	llenado_t2.join();
	
	end     = std::chrono::high_resolution_clock::now(); 
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	auto totalTimeFill_threads = elapsed.count();
	
	
	std::cout << std::endl;

	// ======LLENADO DE LA ESTRUCTURA CON NUMEROS==END

	
	std::cout << "====Llenado arreglo====" << std::endl;
	std::cout << "Tiempo secuencial :"  << totalTimeFill_secuencial<< "[ms]" << std::endl;
	std::cout << "Tiempo threads    :"  << totalTimeFill_threads<< "[ms]" << std::endl;
	std::cout << "SpeedUp           :"  << (double)totalTimeFill_secuencial/totalTimeFill_threads << std::endl;
	

	

	return(EXIT_SUCCESS);
}

