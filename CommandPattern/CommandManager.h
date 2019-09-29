/// <summary>
/// @Author : Oisin Wilson
/// </summary>

#pragma once

#include"ConcreteCommands.h"
#include <stack>

class CommandManager
{
public:
	virtual void add(Command* t_input);
	virtual void remove();
	virtual void execute();

private:
	std::stack<Command*> m_commands;
	std::stack<Command*> m_redoCommands;

};

void CommandManager::add(Command* t_input)
{
	//push onto stack then execute
	m_commands.push(t_input);
	execute();
}

void CommandManager::remove()
{
	//pop from stack
	m_commands.pop();
}

void CommandManager::execute()
{
	if (typeid(*m_commands.top()) != typeid(UndoOutput) && typeid(*m_commands.top()) != typeid(RedoOutput))
	{	// if normal key inputed
		m_commands.top()->execute();	//execute top of normal stack
		while (!m_redoCommands.empty())
		{	//empty redo stack
			m_redoCommands.pop();
		}
	}
	else if (typeid(*m_commands.top()) == typeid(UndoOutput))
	{	// if undo command is entered
		if (m_commands.size() > 1)
		{	//
			m_commands.top()->execute();	//move cursor back
			m_commands.pop();	// pop command from stack
			m_redoCommands.push(m_commands.top());	//put removed command to the redo stack
			m_commands.pop();	// pop undone comand from stack
		}
		else
		{
			m_commands.pop();	//if only undo command entered, remove from stack
		}
	}
	else
	{	// if redo command is entered
		if (!m_redoCommands.empty())
		{
			m_commands.pop();	// pop last command
			m_redoCommands.top()->execute();	//redo most recently undone command
			m_commands.push(m_redoCommands.top());	// move command from the redo stack to command stack 
			m_redoCommands.pop();	// pop redone command from redo stack
		}
		else
		{
			m_commands.pop();	//if only redo command entered, remove from stack
		}
	}
}