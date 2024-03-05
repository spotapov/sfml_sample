#include "core.h"

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
    core core;

    auto window = RenderWindow{ { 800, 800 }, "Running Circle" };
    window.setFramerateLimit( 60 );

    Clock clock;
    while( window.isOpen() )
    {
        Event event;
        while( window.pollEvent( event ) )
        {
            if( event.type == Event::Closed )
                window.close();

            if( event.type == Event::KeyPressed )
                if( event.key.code == Keyboard::Escape )
                    window.close();
        }

        if( Keyboard::isKeyPressed( Keyboard::Left ) )
            core.touch_left();

        if( Keyboard::isKeyPressed( Keyboard::Right ) )
            core.touch_right();

        if( Keyboard::isKeyPressed( Keyboard::Up ) )
            core.touch_up();

        if( Keyboard::isKeyPressed( Keyboard::Down ) )
            core.touch_down();

        core.update( clock.restart().asMicroseconds() );

        window.clear();
        window.draw( core );
        window.display();
    }

    return 0;
}
