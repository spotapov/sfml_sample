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
        for( auto event = Event{}; window.pollEvent(event); )
        {
            if( event.type == Event::Closed )
                window.close();

            if( event.type == Event::KeyPressed )
            {
                if( event.key.code == Keyboard::Left )
                    core.touch_left();

                if( event.key.code == Keyboard::Right )
                    core.touch_right();

                if( event.key.code == Keyboard::Up )
                    core.touch_up();

                if( event.key.code == Keyboard::Down )
                    core.touch_down();

                if( event.key.code == Keyboard::Escape )
                    window.close();
            }
        }

        core.update( clock.restart().asMicroseconds() );

        window.clear();
        window.draw( core );
        window.display();
    }

    return 0;
}
