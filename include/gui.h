// gui.h
//
// by Tiago de Lima <tiago.delima@univ-artois.fr>
// on 13 nov 2017.
//
// Implements GUI.

#ifndef _GUI_H
#define _GUI_H

#ifndef NDEBUG
#include <iostream>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <sstream>
#include "scene_interface.h"
#include "Aliases.hpp"

#include "gui_interface.h"

namespace gui {

  class GuiSdlException : GuiException
  {
  public:
    const char * what() const noexcept
    {
      return SDL_GetError();
    }
  };

  class GuiTtfException : GuiException
  {
  public:
    const char * what() const noexcept
    {
      return TTF_GetError();
    }
  };

  class Gui : public GuiInterface
  {
  public:
    Gui(){}
    virtual ~Gui(){}

    unsigned int get_win_width() const override { return this->window_width; }
    unsigned int get_win_height() const override { return this->window_height; }

    void render_line( om::Vec2r a, om::Vec2r b, Color c) const override
    {
      om::Vec2i sc0 = this->screen_coords( a );
      om::Vec2i sc1 = this->screen_coords( b );
      SDL_Color sdlc = to_sdl_color( c );
      SDL_SetRenderDrawColor( this->renderer, sdlc.r, sdlc.g, sdlc.b, sdlc.a );
      SDL_RenderDrawLine( this->renderer, sc0[0], sc0[1], sc1[0], sc1[1] );
    }
    
    void render_point( om::Vec2r p, Color c) const override
    {
      om::Vec2i sc = this->screen_coords( p );
      SDL_Color sdlc = to_sdl_color( c );
      SDL_SetRenderDrawColor( this->renderer, sdlc.r, sdlc.g, sdlc.b, sdlc.a );
      SDL_RenderDrawPoint( this->renderer, sc[0], sc[1] );
    }
    
    void render_text( om::Vec2r pos, std::string text, Color color) const override
    {
      // Render text surface.
      SDL_Surface* text_surface = TTF_RenderText_Solid( this->font, text.c_str(), this->to_sdl_color(color) );
      if( text_surface == nullptr )
	{
	  throw GuiTtfException();
	}

      // Create texture from surface pixels.
      SDL_Texture* texture = SDL_CreateTextureFromSurface( this->renderer, text_surface );
      if( texture == nullptr )
	{
	  throw GuiTtfException();
	}

      // Get size of the texture.
      SDL_Rect src_rect = { 0, 0, text_surface->w, text_surface->h };
      // Set size of the texture on screen.
      SDL_Rect dst_rect = { static_cast<int>(pos[0]), static_cast<int>(pos[1]), src_rect.w, src_rect.h };

      // Render texture to screen.
      SDL_RenderCopy( this->renderer, texture, &src_rect, &dst_rect );

      // Get rid of old surface.
      SDL_FreeSurface( text_surface );
      text_surface = nullptr;
    
      // Free texture.
      SDL_DestroyTexture( texture );
      texture = nullptr;
    }

    void start()
    {
      std::cerr << "Starting up GUI." << std::endl;

      // Initialize SDL.
      if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
	  throw GuiSdlException();
	}

      // Create window.
      this->window = SDL_CreateWindow( "The 3D Scene Viewer",
				       SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				       this->window_width, this->window_height,
				       SDL_WINDOW_SHOWN );
      if( this->window == nullptr )
	{
	  throw GuiSdlException();
	}

      // Create v-synced renderer for window.
      this->renderer = SDL_CreateRenderer( this->window, -1,
					   //                                     SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
					   SDL_RENDERER_ACCELERATED );
      if( this->renderer == nullptr )
	{
	  throw GuiSdlException();
	}

      // Initialize renderer color (black).
      SDL_SetRenderDrawColor( this->renderer, 0xFF, 0xFF, 0xFF, 0xFF );

      // Initialize SDL_ttf.
      if( TTF_Init() == -1 )
	{
	  throw GuiTtfException();
	}

      // Open the font.
      this->font = TTF_OpenFont( this->ttf_file, this->default_font_size );
      if( this->font == nullptr )
	{
	  throw GuiTtfException();
	}

      // Get window surface.
      // this->surface = SDL_GetWindowSurface( window );
    }
    
    void stop()
    {
      std::cerr << "Shuting down GUI." << std::endl;

      // Free font.
      TTF_CloseFont( this->font );
      this->font = nullptr;

      // Destroy window.
      SDL_DestroyRenderer( this->renderer );
      SDL_DestroyWindow( this->window );
      //SDL_FreeSurface( this->surface );
      this->window = nullptr;
      this->renderer = nullptr;
      //this->surface = nullptr;

      // Quit SDL subsystems.
      TTF_Quit();
      SDL_Quit();
    }
    
    void main_loop( SceneInterface * scene) const
    {
      // Event handler.
      SDL_Event event;

      // Ticks (to be able to count frame per second).
      unsigned int start_ticks { SDL_GetTicks() };

      // Start counting frames per second.
      unsigned int num_frames { 0 };
      unsigned int fps { 0 };
      std::stringstream fps_text;

      // While the application is running:
      bool quit { false };
      while( !quit )
	{
	  // Handle events on queue.
	  while( SDL_PollEvent( &event ) != 0 )
	    {
	      // If user requests quit.
	      if( event.type == SDL_QUIT )
		{
		  quit = true;
		}

	      // User presses a key.
	      else if( event.type == SDL_KEYDOWN )
		{
		  // Start camera movement based on key press.
		  switch( event.key.keysym.sym )
		    {
		    case SDLK_ESCAPE:
		      quit = true;
		      break;
		    case SDLK_UP:
		      scene->press_up();
		      break;
		    case SDLK_DOWN:
		      scene->press_down();
		      break;
		    case SDLK_LEFT:
		      scene->press_left();
		      break;
		    case SDLK_RIGHT:
		      scene->press_right();
		      break;
		    case SDLK_SPACE:
		      scene->press_space();
		      break;
		    case SDLK_w:
		      scene->press_w();
		      break;
		    case SDLK_s:
		      scene->press_s();
		      break;
		    case SDLK_a:
		      scene->press_a();
		      break;
		    case SDLK_d:
		      scene->press_d();
		      break;
		    case SDLK_q:
		      scene->press_q();
		      break;
		    case SDLK_e:
		      scene->press_e();
		      break;
		    case SDLK_z:
		      scene->press_z();
		      break;
		    case SDLK_x:
		      scene->press_x();
		      break;
		    }
		}
	      else if( event.type == SDL_KEYUP )
		{
		  // Stop camera movement based on key release.
		  switch( event.key.keysym.sym )
		    {
		    case SDLK_UP:
		    case SDLK_DOWN:
		      scene->release_updown();
		      break;
		    case SDLK_LEFT:
		    case SDLK_RIGHT:
		      scene->release_leftright();
		      break;
		    case SDLK_SPACE:
		      scene->release_space();
		      break;
		    case SDLK_w:
		    case SDLK_s:
		      scene->release_ws();
		      break;
		    case SDLK_a:
		    case SDLK_d:
		      scene->release_ad();
		      break;
		    case SDLK_q:
		    case SDLK_e:
		      scene->release_qe();
		      break;
		    case SDLK_z:
		    case SDLK_x:
		      scene->release_zx();
		      break;
		    }
		}
	    }

	  // Update scene.
	  scene->update();
    
	  // Clear the surface (black).
	  SDL_SetRenderDrawColor( this->renderer, 0x00, 0x00, 0x00, 0x00 );
	  SDL_RenderClear( this->renderer ); 
    
	  // Draw the scene in the surface.
	  scene->draw();

	  // If one second has passed.
	  if( SDL_GetTicks() - start_ticks >= 1000 )
	    {
	      // Take the number of frames and restart counting.
	      fps = num_frames;
	      start_ticks = SDL_GetTicks();
	      num_frames = 0;
	    }
	  // Show fps.	
	  fps_text.str( "" );
	  fps_text << fps << " fps";
	  this->render_text( { 940, 10 }, fps_text.str().c_str(), white );

	  // Update the surface.
	  SDL_RenderPresent( this->renderer );
	  ++num_frames;
	}
    }

  private:
    // TODO: make it more portable and search for a suitable file in the system path.
    const char ttf_file[22] = "res/font/VeraMono.ttf";
    const unsigned int default_font_size { 12 };
    const int window_width { 1024 };
    const int window_height { 1024 };
    const om::Vec2i window_center { window_width / 2, window_height / 2 };

    SDL_Window* window { nullptr };
    //SDL_Surface* surface { nullptr };
    SDL_Renderer* renderer { nullptr };
    TTF_Font* font { nullptr };

    SDL_Color to_sdl_color( Color c ) const
    {
      unsigned char r, g, b, a;
      r = c.red * 0xff;
      g = c.green * 0xff;
      b = c.blue * 0xff;
      a = c.alpha * 0xff;

      SDL_Color s = { r, g, b, a };
      return s;
    }
    
    om::Vec2i screen_coords( om::Vec2r cc) const
      {
	// On the screen, y coordinates are inverted !
	// Thus, you have to turn 180 degrees on the x axis.
	int x = (int) ( cc[0] * this->window_center.At(0) + this->window_center.At(0));
	int y = (int) (-cc[1] * this->window_center.At(0) + this->window_center.At(1));
	return om::Vec2i{x,y};
      }
  };
 
} // namespace gui

#endif // _GUI_H
