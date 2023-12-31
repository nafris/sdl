#include "application.hpp"

SDL_Surface *load_surface(char const *path){
	SDL_Surface *image_surface = SDL_LoadBMP(path);
	if(!image_surface){
		return 0;
	}
	return image_surface;
}

Application::Application(){
	m_window = SDL_CreateWindow("Application", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);
	
	if(!m_window){
		std::cout << "Failed to create window\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}
	
	m_window_surface = SDL_GetWindowSurface(m_window);
	
	if(!m_window_surface){
		std::cout << "Failed to get window's  surface\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}
	
		
	//m_image_position.x = 0;
	//m_image_position.y = 0;
	//m_image_position.w = 50;
	//m_image_position.h = 50;
	
	//m_image_x = 0.0;
	//m_image_y = 0.0;
	
	//m_image = load_surface("image.bmp");
}

Application::~Application(){
	SDL_FreeSurface(m_window_surface);
	SDL_DestroyWindow(m_window);

}

void Application::update(double delta_time){
	m_stick_figure.update(delta_time);
	//m_image_x = m_image_x + (5 * delta_time);
	//m_image_position.x = m_image_x;
}

void Application::draw(){
	SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface->format,0 ,0 ,0));
	//SDL_BlitSurface(m_image, NULL, m_window_surface, &m_image_position);
	m_stick_figure.draw(m_window_surface);
	SDL_UpdateWindowSurface(m_window);
}
void Application::loop(){
	bool keep_window_open = true;
	while(keep_window_open){
		while(SDL_PollEvent(&m_window_event) > 0){
			m_stick_figure.handle_events(m_window_event);
			switch(m_window_event.type){
				case SDL_QUIT:
					keep_window_open = false;
					break;
			}
		}
		update(1.0 / 60.0);
		draw();
	}
}
