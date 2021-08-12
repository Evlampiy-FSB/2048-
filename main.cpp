#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>

std::vector<int> addNewRects(int amount, std::vector<int> scores) {
	for (int i = 0; i <= amount; i++) {
		std::srand(time(NULL));
		int rect;
		do {
			rect = rand() % 15 + 0;
		} while (scores[rect] != 0);
		int num = rand() % 100 + 1;
		if (num > 75) {
			scores[rect] = 4;
		} else {
			scores[rect] = 2;
		}
	}
	
	return scores;
}

int main() {
	sf::RenderWindow window(sf::VideoMode(600.f, 700.f), "2048!");
	 
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	sf::RectangleShape rect1(sf::Vector2f(125, 125));
	sf::Text text1("", font, 40);
	rect1.move(sf::Vector2f(20, 20));
	sf::RectangleShape rect2(sf::Vector2f(125, 125));
	sf::Text text2("", font, 40);
	rect2.move(sf::Vector2f(165, 20));
	sf::RectangleShape rect3(sf::Vector2f(125, 125));
	sf::Text text3("", font, 40);
	rect3.move(sf::Vector2f(310, 20));
	sf::RectangleShape rect4(sf::Vector2f(125, 125));
	sf::Text text4("", font, 40);
	rect4.move(sf::Vector2f(455, 20));
	sf::RectangleShape rect5(sf::Vector2f(125, 125));
	sf::Text text5("", font, 40);
	rect5.move(sf::Vector2f(20, 165));
	sf::RectangleShape rect6(sf::Vector2f(125, 125));
	sf::Text text6("", font, 40);
	rect6.move(sf::Vector2f(165, 165));
	sf::RectangleShape rect7(sf::Vector2f(125, 125));
	sf::Text text7("", font, 40);
	rect7.move(sf::Vector2f(310, 165));
	sf::RectangleShape rect8(sf::Vector2f(125, 125));
	sf::Text text8("", font, 40);
	rect8.move(sf::Vector2f(455, 165));
	sf::RectangleShape rect9(sf::Vector2f(125, 125));
	sf::Text text9("", font, 40);
	rect9.move(sf::Vector2f(20, 310));
	sf::RectangleShape rect10(sf::Vector2f(125, 125));
	sf::Text text10("", font, 40);
	rect10.move(sf::Vector2f(165, 310));
	sf::RectangleShape rect11(sf::Vector2f(125, 125));
	sf::Text text11("", font, 40);
	rect11.move(sf::Vector2f(310, 310));
	sf::RectangleShape rect12(sf::Vector2f(125, 125));
	sf::Text text12("", font, 40);
	rect12.move(sf::Vector2f(455, 310));
	sf::RectangleShape rect13(sf::Vector2f(125, 125));
	sf::Text text13("", font, 40);
	rect13.move(sf::Vector2f(20, 455));
	sf::RectangleShape rect14(sf::Vector2f(125, 125));
	sf::Text text14("", font, 40);
	rect14.move(sf::Vector2f(165, 455));
	sf::RectangleShape rect15(sf::Vector2f(125, 125));
	sf::Text text15("", font, 40);
	rect15.move(sf::Vector2f(310, 455));
	sf::RectangleShape rect16(sf::Vector2f(125, 125));
	sf::Text text16("", font, 40);
	rect16.move(sf::Vector2f(455, 455));
	
	std::vector<sf::RectangleShape> rects = {rect1, rect2, rect3, rect4, rect5, rect6, rect7, rect8, rect9, rect10, rect11, rect12, rect13, rect14, rect15, rect16};
	std::vector<int> scores = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	std::vector<sf::Text> texts = {text1, text2, text3, text4, text5, text6, text7, text8, text9, text10, text11, text12, text13, text14, text15, text16};
	std::vector<int> scoresOld = scores;
	
	scores = addNewRects(2, scores);
	
	for (int i = 0; i < 16; i++) {
		sf::Vector2f centerPos = sf::Vector2f(rects[i].getPosition().x + rects[i].getSize().x / 2, rects[i].getPosition().y + rects[i].getSize().y / 2);
		texts[i].setPosition(centerPos.x - texts[i].getGlobalBounds().width / 2, centerPos.y - texts[i].getGlobalBounds().height / 2);
	}
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					switch (event.key.code) {
						scoresOld = scores;
						case sf::Keyboard::Right:
							for (int i = 15; i >= 0; i--) {
								int needRect = 0;
								if (scores[i] != 0 && i % 4 != 3) {
									if (scores[i + 1] == 0) {
										needRect = 1;
										while (scores[i + needRect + 1] == 0 && (i + 1 + needRect) % 4 != 0) {
											needRect++;
										}
										scores[i + needRect] = scores[i];
										scores[i] = 0;
									}
									
									if (scores[i + needRect] == scores[i + needRect + 1] && (i + needRect + 2) % 4 != 1) {
										scores[i + needRect + 1] += scores[i + needRect];
										scores[i + needRect] = 0;
									} 
								}
							}
							if (scores != scoresOld)
								scores = addNewRects(1, scores);
							break;
						case sf::Keyboard::Left:
							scoresOld = scores;
							for (int i = 0; i < 16; i++) {
								int needRect = 0;
								if (scores[i] != 0 && (i + 1) % 4 != 1) {
									if (scores[i - 1] == 0) {
										needRect = 1;
										while (scores[i - needRect - 1] == 0 && (i - needRect) % 4 != 0) {
											needRect++;
										}
										scores[i - needRect] = scores[i];
										scores[i] = 0;
									}
									
									if (scores[i - needRect] == scores[i - needRect - 1] && (i - needRect - 2) % 4 != 0) {
										scores[i - needRect - 1] += scores[i - needRect];
										scores[i - needRect] = 0;
									} 
								}
							}
							if (scores != scoresOld)
								scores = addNewRects(1, scores);
							break;
						case sf::Keyboard::Up:
							scoresOld = scores;
							for (int i = 0; i < 16; i++) {
								int needRect = 0;
								if (scores[i] != 0 && i + 1 > 4) {
									if (scores[i - 4] == 0) {
										needRect = 4;
										while (scores[i - needRect - 4] == 0 && i - needRect > 4) {
											needRect += 4;
										}
										scores[i - needRect] = scores[i];
										scores[i] = 0;
									}
									
									if (scores[i - needRect] == scores[i - needRect - 4]) {
										scores[i - needRect - 4] += scores[i - needRect];
										scores[i - needRect] = 0;
									} 
								}
							}
							if (scores != scoresOld)
								scores = addNewRects(1, scores);
							break;
						case sf::Keyboard::Down:
							scoresOld = scores;
							for (int i = 15; i >= 0; i--) {
								int needRect = 0;
								if (scores[i] != 0 && i + 1 < 13) {
									if (scores[i + 4] == 0) {
										needRect = 4;
										while (scores[i + needRect + 4] == 0 && (i + needRect + 1) < 13) {
											needRect += 4;
										}
										scores[i + needRect] = scores[i];
										scores[i] = 0;
									}
									
									if (scores[i + needRect] == scores[i + needRect + 4]) {
										scores[i + needRect + 4] += scores[i + needRect];
										scores[i + needRect] = 0;
									} 
								}
							}
							if (scores != scoresOld)
								scores = addNewRects(1, scores);
							break;
					}
			}
		}
		
		window.clear(sf::Color(255, 255, 255));
		sf::RectangleShape bg(sf::Vector2f(600, 600));
		bg.setFillColor(sf::Color(190, 174, 158));
		window.draw(bg);
		
		for (int i = 0; i < 16; i++) {
			switch (scores[i]) {
				case 0:
					rects[i].setFillColor(sf::Color(216, 206, 196));
					break;
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
			if (scores[i] != 0) {
				texts[i].setColor(sf::Color(121, 112, 99));
				texts[i].setStyle(sf::Text::Bold);
				texts[i].setString(std::to_string(scores[i]));
			} else if (scores[i] < 16) {
				texts[i].setFillColor(sf::Color(216, 206, 196));
				texts[i].setString(std::to_string(scores[i]));
			} else {
				texts[i].setFillColor(sf::Color(255, 246, 230));
				texts[i].setString(std::to_string(scores[i]));
				window.draw(texts[i]);
			}
			window.draw(texts[i]);
		}
		
		window.display();
	}
	
	return 0;
}