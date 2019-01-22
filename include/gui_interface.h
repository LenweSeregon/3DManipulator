// gui_interface.h
//
// by Tiago de Lima <tiago.delima@univ-artois.fr>
// on 19 July 2017
//
// Defines GUI interface.

#ifndef _GUI_INTERFACE_H
#define _GUI_INTERFACE_H

#include <stdexcept>
#include "Aliases.hpp"

namespace gui {

class Color 
{
    public:
        float red;
        float green;
        float blue;
        float alpha;

	std::string to_string() const
	  {
	    return
	      std::to_string( this->red ) + ", " +
	      std::to_string( this->green ) + ", " +
	      std::to_string( this->blue ) + ", " +
	      std::to_string( this->alpha );
	  }
};

 const Color black { 0.0f, 0.0f, 0.0f, 0.0f };
 const Color white { 1.0f, 1.0f, 1.0f, 0.0f };
 const Color red {1.0f, 0.0f, 0.0f, 0.0f};
 const Color blue {0.0f, 0.0f, 1.0f, 0.0f};
 const Color green {0.0f, 1.0f, 0.0f, 0.0f};
// TODO: more colors...

//! Key symbols.
enum class KeySym
{
    k_up,
    k_down
    // TODO: more key symbols...
};

//! Graphical User Interface.
 class GuiInterface
 {
 public:

   virtual ~GuiInterface(){}
   virtual unsigned int get_win_width() const = 0;
   virtual unsigned int get_win_height() const = 0;

   virtual void render_line( om::Vec2r, om::Vec2r, Color ) const = 0;
   virtual void render_point( om::Vec2r, Color ) const = 0;
   virtual void render_text( om::Vec2r, std::string, Color ) const = 0;
 };


class GuiException : std::exception
{
    public:
        virtual const char * what() const noexcept = 0;

};

} // namespace gui

#endif // _GUI_INTERFACE_H
