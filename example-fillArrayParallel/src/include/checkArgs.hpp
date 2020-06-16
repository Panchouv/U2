#ifndef _CHECKARGS_H_
#define _CHECKARGS_H_

#include <unistd.h>

extern char *optarg;
extern int optind, opterr, optopt;

class checkArgs {
private:
	// 1) Modificar esta sección
	const std::string optString = "t:T:h";
	
	const std::string opciones = "-t num -T type [-h]";

	const std::string descripcion  = "Descripción:\n"
		                             "\t-t   total  de elementos del arreglo\n"
									 "\t-T   tipo de RNE: 1) std::rand(), 2) std::uniform_int_distribution\n"
									 "\t-h   Muestra esta ayuda y termina\n";
	
	typedef struct args_t{
		uint64_t totalElementos;
		int8_t   RNEtype;
	} args_t;
	
	// 2) Modificar constructor
	// 3) Modificar ciclo "getopt" en método checkArgs::getArgs()
	// 4) Recuerde que para compilar nuevamente, y por tratarse
	//    de un archivo header, debe hacer primero un make clean
	
	args_t  parametros;
	
	int argc;
	char **argv;

	
public:
	checkArgs(int _argc , char **_argv);
	~checkArgs();
	args_t getArgs();
	
private:
	void printUsage();
	
	
};

checkArgs::checkArgs(int _argc , char **_argv){
	parametros.totalElementos =  0;
	parametros.RNEtype        = -1;

	argc = _argc;
	argv = _argv;
	
}

checkArgs::~checkArgs(){
	
}

checkArgs::args_t checkArgs::getArgs(){
	int opcion;
	
	while ((opcion = getopt (argc, argv, optString.c_str())) != -1){
		switch (opcion) {
			case 't':
					parametros.totalElementos = atoi(optarg);
					break;
			case 'T':
					parametros.RNEtype = atoi(optarg);
					break;
			case 'h':
			default:
					printUsage();
					exit(EXIT_FAILURE);
		}
	}

	if ( parametros.totalElementos == 0 || parametros.RNEtype == -1){
		printUsage();
		exit(EXIT_FAILURE);
	}
	
	return(parametros);
}

void checkArgs::printUsage(){
	std::cout << "Uso: " <<
		argv[0] << " " << opciones << " " << descripcion << std::endl;
}



#endif
