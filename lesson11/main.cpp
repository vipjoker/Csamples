#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "res_path.h"
int main (int argc,char** argv){
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0){
		std::cerr << "SDL init error" << SDL_GetError() << std::endl;
		return 1;
	}else{
		std::cout << "Inited" << std::endl;
	} 
	std::cout << "Ressource path is " << getResourcePath() << std::endl;
	SDL_Quit();
	return 0;
}

