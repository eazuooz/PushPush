#include "GameObject.h"

GameObject::GameObject()
	: mPos()
	, mCh('\0')
{

}

GameObject::~GameObject()
{
}

DIRECTION GameObject::Move(DIRECTION inputDir, Pos& pos)
{
	DIRECTION dir = inputDir;
	switch (dir)
	{
	case DIRECTION::UP:
	{
		pos.y -= 1;
		dir = DIRECTION::UP;
	}
	break;

	case DIRECTION::LEFT:
	{
		pos.x -= 1;
		dir = DIRECTION::LEFT;
	}
	break;

	case DIRECTION::DOWN:
	{
		pos.y += 1;
		dir = DIRECTION::DOWN;
	}
	break;

	case DIRECTION::RIGHT:
	{
		pos.x += 1;
		dir = DIRECTION::RIGHT;
	}
	break;

	default:
		break;
	}

	return dir;
}

DIRECTION GameObject::Move(char ch, Pos& pos)
{
	DIRECTION dir = DIRECTION::NONE;
	switch (ch)
	{
	case 'W':
	{
		pos.y -= 1;
		dir = DIRECTION::UP;
	}
	break;

	case 'A':
	{
		pos.x -= 1;
		dir = DIRECTION::LEFT;
	}
	break;

	case 'S':
	{
		pos.y += 1;
		dir = DIRECTION::DOWN;
	}
	break;

	case 'D':
	{
		pos.x += 1;
		dir = DIRECTION::RIGHT;
	}
	break;

	default:
		break;
	}

	return dir;
}
