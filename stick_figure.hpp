#pragma once

#include <SDL2/SDL.h>

class StickFigure{
	public:
		StickFigure();
		~StickFigure() = default;
		
		void update(double delta_time);
		void draw(SDL_Surface *window_surface);
	private:
		SDL_Surface *m_image;
		SDL_Rect m_position;
		double m_x;
		double m_y;
	};
