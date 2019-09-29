/// <summary>
/// @Author : Oisin Wilson
/// </summary>

#pragma once

#include"CommandManager.h"
#include"CommandInterface.h"
#include"ConcreteCommands.h"

#include<stack>
#include<SFML/Graphics.hpp>


class InputHandeler
{
public:

	void inputHandle();

private:

	// handles the action the input should complete
	CommandManager m_manager;

	// each button used
	Command* buttonQ = new QOutput();
	Command* buttonW = new WOutput();
	Command* buttonE = new EOutput();
	Command* buttonR = new ROutput();
	Command* buttonT = new TOutput();
	Command* buttonY = new YOutput();
	Command* buttonBackSpace = new UndoOutput();
	Command* buttonTab = new RedoOutput();

	// bools so theres one input per key release 
	bool m_keyStatePressed[8] = { false, false, false, false, false, false, false, false };
};


void InputHandeler::inputHandle()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !m_keyStatePressed[0])
	{
		m_keyStatePressed[0] = true;
		m_manager.add(buttonQ);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && m_keyStatePressed[0])
	{
		m_keyStatePressed[0] = false;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !m_keyStatePressed[1])
	{
		m_keyStatePressed[1] = true;
		m_manager.add(buttonW);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_keyStatePressed[1])
	{
		m_keyStatePressed[1] = false;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !m_keyStatePressed[2])
	{
		m_keyStatePressed[2] = true;
		m_manager.add(buttonE);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E) && m_keyStatePressed[2])
	{
		m_keyStatePressed[2] = false;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !m_keyStatePressed[3])
	{
		m_keyStatePressed[3] = true;
		m_manager.add(buttonR);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::R) && m_keyStatePressed[3])
	{
		m_keyStatePressed[3] = false;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && !m_keyStatePressed[4])
	{
		m_keyStatePressed[4] = true;
		m_manager.add(buttonT);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::T) && m_keyStatePressed[4])
	{
		m_keyStatePressed[4] = false;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && !m_keyStatePressed[5])
	{
		m_keyStatePressed[5] = true;
		m_manager.add(buttonY);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && m_keyStatePressed[5])
	{
		m_keyStatePressed[5] = false;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !m_keyStatePressed[6])
	{
		m_keyStatePressed[6] = true;
		m_manager.add(buttonBackSpace);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && m_keyStatePressed[6])
	{
		m_keyStatePressed[6] = false;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && !m_keyStatePressed[7])
	{
		m_keyStatePressed[7] = true;
		m_manager.add(buttonTab);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && m_keyStatePressed[7])
	{
		m_keyStatePressed[7] = false;
	}
}