#pragma once
#include "GameState.h"
#include "GGraphic.h"
#include"Particle.h"
#include<d3d9.h>
#include<d3dx9.h>
#include<vector>
#include"Sound.h"

class Level1 : public GameState
{
private:
	D3DXVECTOR3 vPosition;
	LPDIRECT3DTEXTURE9 particle_texture;
	LPDIRECT3DTEXTURE9 background_texture;
	LPDIRECT3DTEXTURE9 finish_texture;
	LPDIRECT3DTEXTURE9 texture_car;
	LPDIRECT3DTEXTURE9 texture_rock;
	LPDIRECT3DTEXTURE9 texture_block;
	LPDIRECT3DTEXTURE9 texture_coin;
	LPD3DXFONT time_font;
	LPD3DXFONT end_font;
	LPD3DXSPRITE sprite;
	D3DXMATRIX mat;
	RECT finishRect;
	RECT timeRect;
	RECT endRect;
	RECT rock_rect;
	RECT truck_rect;
	RECT block_rect;
	RECT coin_rect;
	D3DXVECTOR2 rock_position[12];
	D3DXVECTOR2 block_position[12];
	D3DXVECTOR2 coin_position;
	RECT car_spriteRect;
	D3DXVECTOR2 background_position[2];
	D3DXVECTOR2 mainCar_position;
	D3DXVECTOR2 finish_position;
	D3DXVECTOR2 timer_position;
	D3DXVECTOR2 scaling;
	D3DXVECTOR2 direction;
	D3DXVECTOR2 mainCarSize;
	D3DXVECTOR2 rockSize;
	D3DXVECTOR2 finishSize;
	D3DXVECTOR2 blockSize;
	D3DXVECTOR2 coinSize;
	std::vector<Particle*>particleList;
	Sound* sound;
	int mainCarCurrentFrame;
	float animationRate;
	float animationTimer;
	int animationRow;
	bool isMainCarMoving;
	float speed;
	float countDownTimer;
	int distance;
	bool startCount = false;
	bool start;
	float bgLength;
public: 
	Level1();
	~Level1();
	void startParticleSystem();
	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
	
};


