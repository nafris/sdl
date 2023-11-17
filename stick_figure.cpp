#include "stick_figure.hpp"

StickFigure::StickFigure(){
	m_image = SDL_LoadBMP("image.bmp");
	
	m_position.x = 0;
	m_position.y = 0;
	m_position.w = 50;
	m_position.h = 50;
	
	m_x = 0.0;
	m_y = 0.0;
}

void StickFigure::update(double delta_time){
	m_x = m_x + (5.0 * delta_time);
	m_position.x = m_x;
}

void StickFigure::draw(SDL_Surface *window_surface){
	SDL_BlitSurface(m_image, NULL, window_surface, &m_position);
}
	
