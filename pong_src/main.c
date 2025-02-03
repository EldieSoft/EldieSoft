#include <stdio.h>
#include "raylib.h"

#define SCREEN_W 400
#define SCREEN_H 400

struct Ball{
	Vector2 position;
	Vector2 speed;
	float radius;
}Ball;

typedef struct Paddle{
	Rectangle box;
	Vector2 position;
	Vector2 size;
	int points;

}Paddle;

struct Ball ball = { 0 };
Paddle player = { 0 };
Paddle opp = { 0 };

void Update(void);
void Logic(void);
void Input(void);

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SetTargetFPS(60);

	// Create the window and OpenGL context
	InitWindow(SCREEN_W, SCREEN_H, "PONG");
	
	ball.position = (Vector2) { SCREEN_W/2, SCREEN_H/2 };
	ball.speed = (Vector2) { 4.0f, 4.0f };
	ball.radius = 10;

	player.size = (Vector2) { 15, 100 };
	player.position = (Vector2) { 20, SCREEN_H/2 - player.size.y/2};
	player.points = 0;
	//player.box = (Rectangle){player.position.x, player.position.y, player.size.x, player.size.y};

	opp.size = (Vector2) { 15, 100 };
	opp.position = (Vector2) { 360, SCREEN_H/2 - opp.size.y/2};
	opp.points = 0;

	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		player.box = (Rectangle) {player.position.x, player.position.y, player.size.x, player.size.y};
		opp.box = (Rectangle) {opp.position.x, opp.position.y, opp.size.x, opp.size.y};
		// drawing
		BeginDrawing();
			ClearBackground(BLACK);
			DrawCircleV(ball.position, ball.radius, WHITE);
			DrawRectangleV(player.position, player.size, WHITE);
			DrawRectangleRec(player.box, WHITE);
			DrawRectangleRec(opp.box, WHITE);

			DrawText(TextFormat("%d", player.points), 100, 20, 20, WHITE);
			DrawText(TextFormat("%d", opp.points), 300, 20, 20, WHITE);
		EndDrawing();
		Logic();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}

void Logic(){

	//input logic
	if (IsKeyDown(KEY_W)){
		player.position.y-=8;
	}
	if (IsKeyDown(KEY_S)){
		player.position.y+=8;
	}
	if (IsKeyDown(KEY_UP)){
		opp.position.y-=8;
	}
	if (IsKeyDown(KEY_DOWN)){
		opp.position.y+=8;
	}

	if (IsKeyPressed(KEY_A))
		player.points--;
	if (IsKeyPressed(KEY_D))
		player.points++;
	if (IsKeyPressed(KEY_LEFT))
		opp.points--;
	if (IsKeyPressed(KEY_RIGHT))
		opp.points++;

	//collision logic
	if (player.position.y <= 0 )
		player.position.y = 0;
	if (player.position.y >= SCREEN_H - player.size.y)
		player.position.y = SCREEN_H - player.size.y;
	if (opp.position.y <= 0)
		opp.position.y = 0;
	if (opp.position.y >= SCREEN_H - opp.size.y)
		opp.position.y = SCREEN_H - opp.size.y;

	//TODO: add ball colision logic
	

	ball.position.x += ball.speed.x; ball.position.y += ball.speed.y;
	if ((ball.position.x >= (SCREEN_W - ball.radius))) {
		player.points++; 
		ball.position = (Vector2){SCREEN_W/2, SCREEN_H/2};
		ball.speed.x *= -1.0f;
	}
	if ((ball.position.x <= ball.radius)) {
		opp.points++;
		ball.position = (Vector2){SCREEN_W/2, SCREEN_H/2};
		ball.speed.x *= -1.0f;
	}
	if ((ball.position.y >= (SCREEN_H - ball.radius)) || (ball.position.y <= ball.radius)) ball.speed.y *= -1.0f;

	if ((CheckCollisionCircleRec(ball.position, ball.radius, player.box)) || (CheckCollisionCircleRec(ball.position, ball.radius, opp.box)))
		ball.speed.x *= -1.0f;
}
