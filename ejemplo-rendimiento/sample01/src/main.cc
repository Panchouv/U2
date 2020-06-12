#include <global.h>
#include <checkArgs.hpp>

int main(int argc, char** argv){
	
	uint64_t repeticiones;

	std::shared_ptr<checkArgs> argumentos = (std::shared_ptr<checkArgs>) new checkArgs(argc, argv);
	
	repeticiones = argumentos->getArgs().repeticiones;

	
	std::cout << "Repeticiones: " << repeticiones << std::endl;
	
	double x1 = 45.43;
	double x2 = 50.90;
	double y1 = 46.34;
	double y2 = 51.94;
	
	double the_dist;
	
	//======Versión 1======
	the_dist = 0;
	auto start = std::chrono::high_resolution_clock::now();
	
	for(size_t i = 0; i < repeticiones; i++) {
		the_dist += sqrt( pow(x2-x1,2) + pow(y2-y1,2) );
	}
	
	auto end     = std::chrono::high_resolution_clock::now(); 
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	auto totalTime01 = elapsed.count();

	std::cout << "====Versión 1====" << std::endl;
	std::cout << "Tiempo01 :"  << totalTime01 << "[ms]" << std::endl;
	std::cout << "Distancia:"  << the_dist << std::endl;
	std::cout << std::endl;
	
	//======Versión 2======
	the_dist = 0;
	start = std::chrono::high_resolution_clock::now();
	
	for(size_t i = 0; i < repeticiones; i++) {
		the_dist += sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
	}
	

	end     = std::chrono::high_resolution_clock::now(); 
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	auto totalTime02 = elapsed.count();
	
	std::cout << "====Versión 2====" << std::endl;
	std::cout << "Tiempo02 :"  << totalTime02 << "[ms]" << std::endl;
	std::cout << "Distancia:"  << the_dist << std::endl;
	std::cout << std::endl;
	
	//======Versión 3======
	the_dist = 0;
	start = std::chrono::high_resolution_clock::now();
	
	double dx = x2-x1;
	double dy = y2-y1;
	
	for(size_t i = 0; i < repeticiones; i++) {
		the_dist += sqrt( dx*dx + dy*dy );
	}
	
	end     = std::chrono::high_resolution_clock::now(); 
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	auto totalTime03 = elapsed.count();

	std::cout << "====Versión 3====" << std::endl;
	std::cout << "Tiempo03 :"  << totalTime03 << "[ms]" << std::endl;
	std::cout << "Distancia:"  << the_dist << std::endl;
	std::cout << std::endl;
	
	std::cout << "====Desempeño====" << std::endl;
	std::cout << "Aceleración A(1,2) = " << (double)totalTime01/totalTime02 <<std::endl;
	std::cout << "Aceleración A(1,3) = " << (double)totalTime01/totalTime03 <<std::endl;
	

	return(EXIT_SUCCESS);
}

