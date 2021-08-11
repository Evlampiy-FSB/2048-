#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(600.f, 700.f), "2048!");
	
	sf::RectangleShape rect1(sf::Vector2f(125, 125));
	rect1.move(sf::Vector2f(20, 20));
	sf::RectangleShape rect2(sf::Vector2f(125, 125));
	rect2.move(sf::Vector2f(165, 20));
	sf::RectangleShape rect3(sf::Vector2f(125, 125));
	rect3.move(sf::Vector2f(310, 20));
	sf::RectangleShape rect4(sf::Vector2f(125, 125));
	rect4.move(sf::Vector2f(455, 20));
	sf::RectangleShape rect5(sf::Vector2f(125, 125));
	rect5.move(sf::Vector2f(20, 165));
	sf::RectangleShape rect6(sf::Vector2f(125, 125));
	rect6.move(sf::Vector2f(165, 165));
	sf::RectangleShape rect7(sf::Vector2f(125, 125));
	rect7.move(sf::Vector2f(310, 165));
	sf::RectangleShape rect8(sf::Vector2f(125, 125));
	rect8.move(sf::Vector2f(455, 165));
	sf::RectangleShape rect9(sf::Vector2f(125, 125));
	rect9.move(sf::Vector2f(20, 310));
	sf::RectangleShape rect10(sf::Vector2f(125, 125));
	rect10.move(sf::Vector2f(165, 310));
	sf::RectangleShape rect11(sf::Vector2f(125, 125));
	rect11.move(sf::Vector2f(310, 310));
	sf::RectangleShape rect12(sf::Vector2f(125, 125));
	rect12.move(sf::Vector2f(455, 310));
	sf::RectangleShape rect13(sf::Vector2f(125, 125));
	rect13.move(sf::Vector2f(20, 455));
	sf::RectangleShape rect14(sf::Vector2f(125, 125));
	rect14.move(sf::Vector2f(165, 455));
	sf::RectangleShape rect15(sf::Vector2f(125, 125));
	rect15.move(sf::Vector2f(310, 455));
	sf::RectangleShape rect16(sf::Vector2f(125, 125));
	rect16.move(sf::Vector2f(455, 455));
	
	std::vector<sf::RectangleShape> rects = {rect1, rect2, rect3, rect4, rect5, rect6, rect7, rect8, rect9, rect10, rect11, rect12, rect13, rect14, rect15, rect16};
	std::vector<int> scores = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
			}
		}
		
		window.clear(sf::Color(255, 255, 255));
		sf::RectangleShape bg(sf::Vector2f(600, 600));
		bg.setFillColor(sf::Color(190, 174, 158));
		window.draw(bg);
		
		for (int i = 0; i < 16; i++) {
			switch (scores[i]) {
				case 2:
					rects[i].setFillColor(sf::Color(240, 228, 217));
					break;
				case 4:
					rects[i].setFillColor(sf::Color(238, 225, 199));
					break;
				case 8:
					rects[i].setFillColor(sf::Color(253, 175, 112));
					break;
				case 16:
					rects[i].setFillColor(sf::Color(255, 143, 86));
					break;
				case 32:
					rects[i].setFillColor(sf::Color(255, 112, 80));
					break;
				case 64:
					rects[i].setFillColor(sf::Color(255, 70, 18));
					break;
				case 128:
					rects[i].setFillColor(sf::Color(241, 210, 104));
					break;
				case 256:
					rects[i].setFillColor(sf::Color(241, 208, 86));
					break;
				case 512:
					rects[i].setFillColor(sf::Color(240, 203, 65));
					break;
				case 1024:
					rects[i].setFillColor(sf::Color(242, 201, 39));
					break;
				case 2048:
					rects[i].setFillColor(sf::Color(243, 197, 0));
					break;
			}
			window.draw(rects[i]);
		}
		
		window.display();
	}
	
	return 0;
}