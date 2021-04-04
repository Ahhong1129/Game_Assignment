#include "Particle.h"
#include"Level1.h"
Particle::Particle()
{
}

Particle::~Particle()
{
	
}

void Particle::cut(D3DXVECTOR2 startPosition, int width, int height)
{
	isInUse = true;
	position = startPosition;
	int angle = rand() % 360;

	cut_rect.left = rand() % (width - 6);
	cut_rect.top = rand() % (height - 6);
	cut_rect.right = cut_rect.left + 6;
	cut_rect.bottom = cut_rect.top + 6;

	position.x += 100;
	position.y += 100;

	D3DXVECTOR2 direction;
	direction.x = sin(angle / 90.0 * 3.142);
	direction.y = -cos(angle / 90.0* 3.142);
	D3DXVec2Normalize(&direction, &direction);
	alpha = 255;
	velocity = direction * 400;
}

void Particle::update()
{
	if (isInUse) {
		velocity.y += 400 / 60.0f;
		position += (velocity / 60.0f);
		alpha -= (255 / 60.0f);
		alpha = max(alpha, 0);
	}
	else if (position.x > 400 || position.x < 0 || position.y < 0 || position.y > 300) {
		isInUse = false;
	}
		
}

void Particle::draw(LPD3DXSPRITE sprite, LPDIRECT3DTEXTURE9 texture)
{
	float backPos = position.y;
	D3DXVECTOR2 particleOnScreen = position;
	particleOnScreen.y = position.y + backPos;
	if (isInUse) {
		D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &particleOnScreen);
		sprite->SetTransform(&mat);
		sprite->Draw(texture, &cut_rect, NULL, NULL, D3DCOLOR_ARGB((int)alpha, 255, 255, 255));
	}
}

