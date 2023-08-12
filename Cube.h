#ifndef __CUBE__
#define __CUBE__
#include <iostream>
#include <SFML/Graphics.hpp>

struct Cube : public sf::Drawable, sf::Transformable
{
private:
	sf::VertexArray m_vertices;
	
	sf::Color m_color;
	sf::Vector2f m_pos;
public:
	Cube(sf::Color color, sf::Vector2f pos, sf::Vector2u size) 
		: m_color(color)
		, m_pos(pos)
	{
		m_vertices.clear();
		m_vertices.setPrimitiveType(sf::PrimitiveType::LineStrip);
		m_vertices.resize(7);

		m_vertices[0].position = { m_pos.x + (size.x / 2.f), m_pos.y + 0.f };
		m_vertices[1].position = { m_pos.x + size.x, m_pos.y + size.y / 3.f };
		m_vertices[2].position = { m_pos.x + size.x, m_pos.y + 2.f * size.y / 3.f };
		m_vertices[3].position = { m_pos.x + (size.x / 2.f), m_pos.y + size.y };
		m_vertices[4].position = { m_pos.x + 0.f, m_pos.y + 2.f * (size.y / 3.f) };
		m_vertices[5].position = { m_pos.x + 0.f, m_pos.y + size.y / 3.f };
		m_vertices[6].position = { m_pos.x + (size.x / 2.f), m_pos.y + 0.f };

		m_vertices[0].color = color;
		m_vertices[1].color = color;
		m_vertices[2].color = color;
		m_vertices[3].color = color;
		m_vertices[4].color = color;
		m_vertices[5].color = color;
		m_vertices[6].color = color;

		


		std::cout << m_vertices.getVertexCount() << std::endl;
	}


	void draw(sf::RenderTarget& window, sf::RenderStates states) const override
	{
		
		window.draw(m_vertices);
	}
};

#endif
