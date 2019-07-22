#include <iostream>
void pdebug(std::string message) {

#ifdef DEBUG
	std::cout <<"[DebugMessage: " << message << "]" << std::endl;
#endif
}

