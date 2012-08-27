#include <stdio.h>

#include "glfw.h"
#include "StateEngine.h"
#include "GameState.h"
#include "IntroState.h"

IntroState IntroState::m_IntroState;

void IntroState::Init()
{
	printf("IntroState initialized\n");
}

void IntroState::Destroy()
{
	printf("IntroState Destroyed\n");
}

void IntroState::Pause()
{

}

void IntroState::Resume()
{

}

void IntroState::HandleEvent(StateEngine* state)
{

}

void IntroState::Update(StateEngine* state, double dt)
{
	m_rotation += dt * 50;
}

void IntroState::Draw(StateEngine* state)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen AND depth, it's a flag (fancy eh?)
	glLoadIdentity(); // Reset modelview matrix

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -7.0f);
	glRotatef(m_rotation, 1.0f, 0.5f, 0.0f); // Rotate the cube on the X and Y axis
	glBegin(GL_QUADS);
	// TOP
	glColor3f(0.0f, 1.0f, 0.0f); // Green
	glVertex3f( 1.0f, 1.0f,-1.0f); // Top Right
	glVertex3f(-1.0f, 1.0f,-1.0f); // Top Left
	glVertex3f(-1.0f, 1.0f, 1.0f); // Bottom Left
	glVertex3f( 1.0f, 1.0f, 1.0f); // Bottom Right
	// Bottom
	glColor3f(1.0f, 0.5f, 0.0f); // Orange
	glVertex3f( 1.0f,-1.0f, 1.0f);
	glVertex3f(-1.0f,-1.0f, 1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f( 1.0f,-1.0f,-1.0f);
	// Front
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex3f( 1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f,-1.0f, 1.0f);
	glVertex3f( 1.0f,-1.0f, 1.0f);
	// Back
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex3f( 1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);
	glVertex3f( 1.0f, 1.0f,-1.0f);
	// Left
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f, 1.0f);
	// Right
	glColor3f(1.0f, 0.0f, 1.0f); // Violet
	glVertex3f( 1.0f, 1.0f,-1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
	glVertex3f( 1.0f,-1.0f, 1.0f);
	glVertex3f( 1.0f,-1.0f,-1.0f);
	glEnd();
	glPopMatrix();

	state->m_glRender->Enable2D();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 0, 0);
	glVertex2d(0, 0);
	glColor3ub(0, 255, 0);
	glVertex2d(100, 0);
	glColor3ub(0, 0, 255);
	glVertex2d(50, 50);
	glEnd();
	state->m_glRender->Disable2D();
}