#ifndef __CUBE__
#define __CUBE__
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Textbox.h"

class  Cube : public sf::Drawable, sf::Transformable
{
public:
	sf::VertexArray m_vertices;
	sf::VertexArray m_points;
	sf::VertexArray m_lines;
	sf::Color m_color;
	sf::Vector2f m_pos;
	bool m_isTransparent{false};
	sf::Font aFont;
	TextBox* makeTxt() { return new TextBox(22, sf::Color(sf::Color(255, 255, 255, 255)), true, aFont, { 100.f, 100.f }); }
	TextBox* currTextBox{ nullptr };
public:
	Cube(sf::Color color, sf::Vector2f pos, sf::Vector2u size) 
		: m_color(color)
		, m_pos(pos)
	{
		m_points.clear();
		m_points.setPrimitiveType(sf::Points);
		m_points.resize((size_t)5546);//((float)size.x * (float)size.y * (1912.f/4096.f)) * 4 + 64);
		m_vertices.clear();
		m_vertices.setPrimitiveType(sf::PrimitiveType::Quads);
		m_vertices.resize(12);
		m_lines.clear();
		m_lines.setPrimitiveType(sf::Lines);
		m_lines.resize(4 * 2);  // 3 lines of two points


		
		

		int x = (int)m_pos.x;
		int accumulator = 0;
		float j = ((m_pos.y + (size.y / 3.f)) - m_pos.y) / (m_pos.x + (size.x / 2.f) - m_pos.x);
		
		std::cout << j << std::endl;


		j *= size.x;
		std::cout << j << std::endl;
		int initialHeight = (int)j;
		


		for (int y = (int)(size.y / 3.f) + m_pos.y; y >= (int)m_pos.y; y--)
		{
			
			for (int i = 0; i <= initialHeight; i++, accumulator +=2)
			{
				m_points[accumulator].position = sf::Vector2f{ (float)x , (float)y + (float)i };
				m_points[accumulator].color = m_color;
				m_points[accumulator + 1].position = sf::Vector2f{ (float)x + 1 , (float)y + (float)i };
				m_points[accumulator + 1].color = m_color;
				
			}
			initialHeight += 2;
			x += 2;
		}
			initialHeight -= 2;
			x -= 2;
			
		for (int y = (int)m_pos.y; y < (int)(size.y / 3.f) + (int)m_pos.y; y++)
		{

			for (int i = 0; i < initialHeight + 1; i++, accumulator += 2)
			{
				m_points[accumulator].position = sf::Vector2f{ (float)x , (float)y + (float)i };
				m_points[accumulator].color = m_color;
				m_points[accumulator+1].position = sf::Vector2f{ (float)x + 1 , (float)y + (float)i };
				m_points[accumulator+1].color = m_color;

			}
			

			initialHeight -= 2;
			x += 2;
		}
		initialHeight += 2;
		x -= 2;


		
		m_vertices[4].position = { m_pos.x + size.x - (size.x / 3.f), m_pos.y + (2.f * (size.y / 3.f))};
		m_vertices[5].position = { m_pos.x + ((size.x - (size.x / 3.f)) * 2),  m_pos.y + (size.y / 3.f) };
		m_vertices[6].position = { m_pos.x + ((size.x - (size.x / 3.f)) * 2),  m_pos.y + (size.y / 3.f) + j};
		m_vertices[7].position = { m_pos.x + size.x - (size.x / 3.f) , m_pos.y + (2.f * (size.y / 3.f)) + j };
	
		m_vertices[8].position = { m_pos.x, m_pos.y + (size.y / 3.f) + j };
		m_vertices[9].position = { m_pos.x , m_pos.y + (size.y / 3.f) };
		m_vertices[10].position = { m_pos.x + size.x - (size.x / 3.f) , m_pos.y + (2.f * (size.y / 3.f))  };
		m_vertices[11].position = { m_pos.x + size.x - (size.x / 3.f)  , m_pos.y + (2.f * (size.y / 3.f)) + j };

		m_vertices[0].position = { m_pos.x , m_pos.y + (size.y / 3.f) };
		m_vertices[1].position = { m_pos.x + size.x * (2 / 3.f), m_pos.y };
		m_vertices[2].position = { m_pos.x + ((size.x - (size.x / 3.f)) * 2) , m_pos.y + (size.y / 3.f)  };
		m_vertices[3].position = { m_pos.x + size.x - (size.x / 3.f) , m_pos.y + (2.f * (size.y / 3.f))  };

		



		m_color = sf::Color(sf::Color(100,100,100,0));


	    //m_color.a = (sf::Uint8)255;
	
		m_vertices[4].color = m_color;

		

		m_vertices[5].color = m_color;

		m_color.a += 100;
		m_vertices[6].color = m_color;

		

		m_vertices[7].color = m_color;
		

		m_color = sf::Color(sf::Color(20, 20, 20, 180));

		//m_color.a = (sf::Uint8)255;
		m_vertices[8].color = m_color;
		m_vertices[9].color = m_color;
		m_vertices[10].color = m_color;
		m_vertices[11].color = m_color;
		

		m_color = sf::Color(sf::Color(50, 100, 50, 200));


		//m_color.a = (sf::Uint8)255;
		m_vertices[0].color = m_color;
		m_vertices[1].color = m_color;

		m_color.a -= 150;
		m_vertices[2].color = m_color;
		m_vertices[3].color = m_color;

		std::cout << m_vertices.getVertexCount() << std::endl;
		std::cout << m_points.getVertexCount() << std::endl;
		std::cout << accumulator << std::endl;


		m_lines[0].position = { m_pos.x, m_pos.y + (size.y / 3.f)};
		m_lines[1].position = { m_pos.x + size.x - (size.x / 3.f), m_pos.y + (2.f * (size.y / 3.f)) };

		m_lines[2].position = { m_pos.x + size.x - (size.x / 3.f), m_pos.y + (2.f * (size.y / 3.f))  };
		m_lines[3].position = { m_pos.x + ((size.x - (size.x / 3.f)) * 2) , m_pos.y + (size.y / 3.f)  };

		m_lines[4].position = { m_pos.x + size.x - (size.x / 3.f), m_pos.y + (2.f * (size.y / 3.f)) };
		m_lines[5].position = { m_pos.x + size.x - (size.x / 3.f), m_pos.y + (2.f * (size.y / 3.f)) + j };

		m_lines[6].position = { m_pos.x + size.x - (size.x / 3.f), m_pos.y + (2.f * (size.y / 3.f))  };
		m_lines[7].position = { m_pos.x + size.x - (size.x / 3.f), m_pos.y + (2.f * (size.y / 3.f)) + j  };


		m_lines[0].color = sf::Color::Black;
		m_lines[1].color = sf::Color::Black;

		m_lines[2].color = sf::Color::Black;
		m_lines[3].color = sf::Color::Black;

		m_lines[4].color = sf::Color::Black;
		m_lines[5].color = sf::Color::Black;

		m_lines[6].color = sf::Color::Black;
		m_lines[7].color = sf::Color::Black;

		aFont.loadFromFile("fonts/Roboto.ttf");

	
		
	}

	void move(const sf::Vector2f& moveAmt)
	{
		m_pos.x += moveAmt.x;
		m_pos.y += moveAmt.y;

		this->move(m_pos);

		
	}
	void recolor()
	{
		m_vertices[0].color = m_color;
		m_vertices[1].color = m_color;
		m_vertices[2].color = m_color;
		m_vertices[3].color = m_color;
		m_vertices[4].color = m_color;
		m_vertices[5].color = m_color;
		m_vertices[6].color = m_color;
		m_vertices[7].color = m_color;
		m_vertices[8].color = m_color;
		m_vertices[9].color = m_color;
		m_vertices[10].color = m_color;
		m_vertices[11].color = m_color;

		return;
	}
	
	void draw(sf::RenderTarget& window, sf::RenderStates states) const override
	{
	

		window.draw(m_points);

		window.draw(m_vertices);

		window.draw(m_lines);


	}

	void lookThrough(bool isTransparent = false)
	{
		if (isTransparent)
		{
			m_color.a = 50;
		}
		else
		{
			m_color.a = 180;
		}
		recolor();
	}

	void Toggle(sf::Color newColor = sf::Color::Transparent)
	{
		this->m_color = newColor;
		this->recolor();
	}


	void update(float dt, const sf::RenderWindow& window)
	{
		sf::Vector2f m_mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);
		sf::FloatRect hitBox({ m_pos.x, m_pos.y, 128, 64 });
		if (hitBox.contains(m_mousePos))
		{
			//  User is hovering over the cube, ditch all its panels alpha values;
			
			lookThrough(true);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
			{
			
				Toggle();

			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{

				Toggle(sf::Color(this->m_color.r + 1 % 255, this->m_color.g + 1 % 255, this->m_color.b + 1 % 255, this->m_color.a + 1 % 255));
				
				if (!currTextBox)
					currTextBox = makeTxt();

				

			}

			
		}
		else
		{
			lookThrough(false);
		}
		
	}
	~Cube()
	{
		if (currTextBox)
			delete currTextBox;
	}
};

#endif
