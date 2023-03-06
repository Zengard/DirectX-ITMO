#pragma once

#include "export.h"
#include "Game.h"
#include "TriangleComponent.h"

class Pong;

class Ball : public TriangleComponent {
private:
	float radius = 0.05f;
	float initialSpeed = 0.01f;

	Pong* game;

public:

	float speed = 1.0f;
	float x;
	float y;

	DirectX::SimpleMath::Vector3 direction;
	
	void setPosition(float x1, float y1) {
		x = x1;
		y = y1;
	};
	
	Ball(Pong* game_, TriangleComponentParameters circle);

	void SetDirection();
	
	// void Update(ID3D11DeviceContext* context) override;
};

class Bar : public TriangleComponent {
private:

	Pong* game;
	bool isLeft;

public:
	Bar();
	Bar(Pong* game_, TriangleComponentParameters rect, bool isLeft_);

	float xPos;
	float yPos;
	
	void setPosition(float x, float y) {
		xPos = x;
		yPos = y;
	};

	// void Update(ID3D11DeviceContext* context) override;
};

class Pong : public Game {
private:
	ID3D11DeviceContext* context;
	Ball* ball;
	Bar* bar1;
	Bar* bar2;
	
	int scoreLeft;
	int scoreRight;
	float velocity;
	
	void Init();
	
	TriangleComponentParameters PrepareRect(float xOff, float yOff);
	TriangleComponentParameters PrepareCircle(float xOff, float yOff);
	
public:
	int redLight = 0;

	void Run();
	void Reset();
	void PrintScore();
	void Update() override;
	
	Pong();
};