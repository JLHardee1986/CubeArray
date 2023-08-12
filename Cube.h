#ifndef __CUBE__
#define __CUBE__
#include <iostream>
#include <SFML/Graphics.hpp>

struct Cube : public sf::Drawable, sf::Transformable
{
private:
	sf::VertexArray m_vertices;
	sf::VertexArray m_points;
	sf::Color m_color;
	sf::Vector2f m_pos;
public:
	Cube(sf::Color color, sf::Vector2f pos, sf::Vector2u size) 
		: m_color(color)
		, m_pos(pos)
	{
		m_points.clear();
		m_points.setPrimitiveType(sf::Points);
		m_points.resize((size_t)((float)size.x * (float)size.y * (1912.f/4096.f)) * 4);
		m_vertices.clear();
		m_vertices.setPrimitiveType(sf::PrimitiveType::Quads);
		m_vertices.resize(12);
		
		
		
		int x = (int)m_pos.x;
		int accumulator = 0;
		float j = ((m_pos.y + (size.y / 3.f)) - m_pos.y) / (m_pos.x + (size.x / 2.f) - m_pos.x);
		
		std::cout << j << std::endl;


		j *= size.x;
		std::cout << j << std::endl;
		int initialHeight = (int)j;
		
		for (int y = (int)(size.y / 3.f) + m_pos.y; y >= (int)m_pos.y; y--)
		{
			
			for (int i = 0; i < initialHeight; i++, accumulator +=2)
			{
				m_points[accumulator].position = sf::Vector2f{ (float)x , (float)y + (float)i };
				m_points[accumulator].color = sf::Color::Blue;
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

			for (int i = 0; i < initialHeight; i++, accumulator += 2)
			{
				m_points[accumulator].position = sf::Vector2f{ (float)x , (float)y + (float)i };
				m_points[accumulator].color = sf::Color::Green;
				m_points[accumulator+1].position = sf::Vector2f{ (float)x + 1 , (float)y + (float)i };
				m_points[accumulator+1].color = m_color;

			}
			

			initialHeight -= 2;
			x += 2;
		}
		initialHeight += 2;
		x -= 2;
		m_vertices[0].position = { m_pos.x - 1.25f, m_pos.y + (size.y / 3.f) + 0.25f};
		m_vertices[1].position = { m_pos.x + size.x * (2 / 3.f), m_pos.y -2 };
		m_vertices[2].position = { m_pos.x + ((size.x - (size.x / 3.f)) * 2) - 0.75f , m_pos.y + (size.y / 3.f) - 1 };
		m_vertices[3].position = { m_pos.x + size.x - (size.x / 3.f), m_pos.y + (2.f * (size.y / 3.f)) + 0.5f - 10};

		m_vertices[4].position = { m_pos.x + size.x - (size.x / 3.f) , m_pos.y + (2.f * (size.y / 3.f))  - 0.55f};
		m_vertices[5].position = { m_pos.x + ((size.x - (size.x / 3.f)) * 2)  - 1 ,  m_pos.y + (size.y / 3.f) -1.35f};
		m_vertices[6].position = { m_pos.x + ((size.x - (size.x / 3.f)) * 2)  - 1.15f,  m_pos.y + (size.y / 3.f) + j -1 };
		m_vertices[7].position = { m_pos.x + size.x - (size.x / 3.f) - 0.05f , m_pos.y + (2*(size.y / 3.f)) + j - 0.25f};
		
		m_vertices[8].position = { m_pos.x - 1, m_pos.y + (size.y / 3.f) + j - 1 };
		m_vertices[9].position = { m_pos.x - 1, m_pos.y + (size.y / 3.f) };
		m_vertices[10].position = { m_pos.x + size.x - (size.x / 3.f) + .15f, m_pos.y + (2.f * (size.y / 3.f)) - 0.55f  };
		m_vertices[11].position = { m_pos.x + size.x - (size.x / 3.f) + 0.45f , m_pos.y + (2 * (size.y / 3.f)) + j - 0.25f  };
		
		m_color.a = (sf::Uint8)30;
		m_vertices[0].color = m_color;
		m_vertices[1].color = m_color;
		m_vertices[2].color = m_color;
		m_vertices[3].color = m_color;


		m_color.a = (sf::Uint8)180;
		m_vertices[4].color = m_color;
		m_vertices[5].color = m_color;
		m_vertices[6].color = m_color;
		m_vertices[7].color = m_color;
		

		m_color.a = (sf::Uint8)150;
		m_vertices[8].color = m_color;
		m_vertices[9].color = m_color;
		m_vertices[10].color = m_color;
		m_vertices[11].color = m_color;
		



		std::cout << m_vertices.getVertexCount() << std::endl;
		std::cout << m_points.getVertexCount() << std::endl;
		std::cout << accumulator << std::endl;

	}


	void draw(sf::RenderTarget& window, sf::RenderStates states) const override
	{
		
		window.draw(m_points);
		window.draw(m_vertices);

	}
};

#endif
