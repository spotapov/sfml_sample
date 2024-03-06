#include "game.h"

#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
    try
    {
        game game;

        auto window = RenderWindow{ { 800, 800 }, "Animated Sprite" };
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
                game.left();

            if( Keyboard::isKeyPressed( Keyboard::Right ) )
                game.right();

            game.update( clock.restart().asMicroseconds() );

            window.clear();
            window.draw( game );
            window.display();
        }

        return 0;
    }
    catch( std::exception& ex )
    {
        cerr << ex.what() << endl;
        return -1;
    }
}
