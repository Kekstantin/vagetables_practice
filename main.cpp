#include "C:\Users\ִלטענטי\source\repos\KVADRAT_IO\Project10\control.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Lesson 2. kychka-pc.ru");
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		initialization(&window);
		window.clear();
		window.display();
	}

	return 0;
}