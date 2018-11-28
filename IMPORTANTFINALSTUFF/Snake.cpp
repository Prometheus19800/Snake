#include "Snake.h"

Snek::Snek(std::vector<PixelSprite*> SNEKBODY)//snek constructor
{
	this->body = SNEKBODY;//setting body vector to the provided vector
	this->head = body[0];
}

Snek::Snek()
{
}

std::vector<PixelSprite*> Snek::getBody()
{
	return this->body;
}

PixelSprite * Snek::getBody(int e)
{
	return this->body[e];
}

void Snek::moveUP()
{
	this->lastPositionX = this->body[0]->GetPosition().X;
	this->lastPositionY = this->body[0]->GetPosition().Y - this->body[0]->GetSize().Y - 1;

	this->body[0]->SetPosition(this->body[0]->GetPosition().X, this->body[0]->GetPosition().Y - 1);

}

void Snek::moveDOWN()
{
	this->lastPositionX = this->body[0]->GetPosition().X;
	this->lastPositionY = this->body[0]->GetPosition().Y + this->body[0]->GetSize().Y + 1;
	this->body[0]->SetPosition(this->body[0]->GetPosition().X, this->body[0]->GetPosition().Y + 1);
}

void Snek::moveLEFT()
{
	this->lastPositionX = this->body[0]->GetPosition().X - this->body[0]->GetSize().X - 1;
	this->lastPositionY = this->body[0]->GetPosition().Y;
	this->body[0]->SetPosition(this->body[0]->GetPosition().X - 1, this->body[0]->GetPosition().Y);
}

void Snek::moveRIGHT()
{
	this->lastPositionX = this->body[0]->GetPosition().X + this->body[0]->GetSize().X + 1;
	this->lastPositionY = this->body[0]->GetPosition().Y;
	this->body[0]->SetPosition(this->body[0]->GetPosition().X + 1, this->body[0]->GetPosition().Y);
}


void Snek::follow()
{
	int placeHolder;
	//for (auto x : this->body) {
	//	x
	//}
}

int Snek::getLastPositionX()
{
	return this->lastPositionX;
}

int Snek::getLastPositionY()
{
	return this->lastPositionY;
}

bool Snek::getDirection(char DIR)
{

	switch (DIR) {

	case 'U':
		this->down = false;
		this->left = false;
		this->right = false;
		return this->up = true;
		break;
	case 'D':
		this->up = false;
		this->left = false;
		this->right = false;
		return this->down = true;
		break;
	case 'L':
		this->down = false;
		this->up = false;
		this->right = false;
		return this->left = true;
		break;
	case 'R':
		this->down = false;
		this->left = false;
		this->up = false;
		return this->right = true;
		break;


	}

}

void Snek::getDir()
{
	if(this->up)
		this->moveUP();
	else if (this->down)
		this->moveDOWN();
	else if (this->left)
		this->moveLEFT();
	else if (this->right)
		this->moveRIGHT();
	

}