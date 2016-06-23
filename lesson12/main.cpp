#include<iostream>
#include<SDL2/SDL.h>
int main (){
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL init error " << SDL_GetError() << std::endl;
	}else{
		std::cout<< "Inited" << std::endl;
	}

	SDL_Window *win = SDL_CreateWindow("Hello world", 100,100,640,480,SDL_WINDOW_SHOWN);

	if(win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(ren == nullptr){
		SDL_DestroyWindow(win);
		std::cout << "SDL_Crete window error" << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
return 0;
}
