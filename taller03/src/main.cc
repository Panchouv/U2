#include <global.h>
#include <checkArgs.hpp>

void sumaParcial(const std::vector<uint32_t> &v, 
                 uint32_t &suma, 
                 size_t beginIndex, 
				 size_t endIndex) {
    suma = 0;
    for (size_t i = beginIndex; i < endIndex; ++i){
        suma += v[i];
    }
}

int main(int argc, char** argv){
	
	uint32_t totalElementos;
	uint32_t numThreads;
	uint32_t limSuperior;
	
    uint32_t sumaSerial = 0;
	uint32_t sumaParcial1 = 0;
	uint32_t sumaParcial2 = 0;
	uint32_t sumaThreads = 0;
	
	std::vector<uint32_t> v;
	
	std::shared_ptr<checkArgs> argumentos = (std::shared_ptr<checkArgs>) new checkArgs(argc, argv);
	
	totalElementos = argumentos->getArgs().tamProblema;
	numThreads     = argumentos->getArgs().numThreads;
	limSuperior    = 500;
	
	std::cout << "Elementos: " << totalElementos << std::endl;
	std::cout << "Threads  : " << numThreads     << std::endl;
	
	static thread_local std::random_device device;
	static thread_local std::mt19937 rng(device());
	
	
	std::uniform_int_distribution<uint32_t> nRandom(0, limSuperior);
	for(size_t i=0; i < totalElementos; i++){
		uint32_t number = nRandom(rng);
		v.push_back( number );
	}
	
	//======SERIAL======
	for(auto& num : v){
		sumaSerial += num;
	}
	
	auto totalTimeSerial = 0;

	//======THREADS======
	//(1) Separación del trabajo
	std::thread t1(sumaParcial, std::ref(v), std::ref(sumaParcial1), 0, v.size() / 2);
	std::thread t2(sumaParcial, std::ref(v), std::ref(sumaParcial2), v.size() / 2, v.size());
	
	t1.join();
	t2.join();
	
	//(2) Reducción (Consolidación de resultados parciales)
	sumaThreads = sumaParcial1 + sumaParcial2;
	
	auto totalTimeThread = 0;
	
	//======RESULTADOS=====

	std::cout << "====Serial====" << std::endl;
	std::cout << "sumaSerial  : " << sumaSerial << std::endl;
	std::cout << "T. serial   :"  << totalTimeSerial << std::endl;
	std::cout << std::endl;
	std::cout << "====Threads====" << std::endl;
	std::cout << "sumaThreads : " << sumaThreads << std::endl;
	std::cout << "T. paralelo :"  << totalTimeThread << std::endl;
	std::cout << std::endl;
	std::cout << "SpeedUp    :" << std::endl;
	std::cout << "Eficiencia :" << std::endl;

	return(EXIT_SUCCESS);
}

