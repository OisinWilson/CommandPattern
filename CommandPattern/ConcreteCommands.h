/// <summary>
/// @Author : Oisin Wilson
/// </summary>

#pragma once

#include "CommandInterface.h"
#include <iostream>

//Command list for each input

class QOutput : public Command
{
public:
	virtual void execute() { std::cout << "Q"; }
};

class WOutput : public Command
{
public:
	virtual void execute() { std::cout << "W"; }
};

class EOutput : public Command
{
public:
	virtual void execute() { std::cout << "E"; }
};

class ROutput : public Command
{
public:
	virtual void execute() { std::cout << "R"; }
};

class TOutput : public Command
{
public:
	virtual void execute() { std::cout << "T"; }
};

class YOutput : public Command
{
public:
	virtual void execute() { std::cout << "Y"; }
};

class UndoOutput : public Command
{
public:
	virtual void execute() { std::cout << "\b \b"; }
};

class RedoOutput : public Command
{
public:
	virtual void execute() {}
};