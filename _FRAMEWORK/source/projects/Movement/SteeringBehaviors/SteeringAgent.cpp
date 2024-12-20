#include "stdafx.h"
#include "SteeringAgent.h"
#include "Steering/SteeringBehaviors.h"

void SteeringAgent::Update(float dt)
{

	if(m_pSteeringBehavior)
	{
		auto output = m_pSteeringBehavior->CalculateSteering(dt, this);

		//Linear Movement
		//***************
		auto linVel = GetLinearVelocity();
		auto steeringForce = output.LinearVelocity - linVel;
		auto acceleration = steeringForce / GetMass();		

		if(m_RenderDebug)
		{
			/*DEBUGRENDERER2D->DrawDirection(GetPosition(), acceleration, acceleration.Magnitude(), { 0, 1, 1 ,0.5f }, 0.40f);
			DEBUGRENDERER2D->DrawDirection(GetPosition(), linVel, linVel.Magnitude(), { 1, 0, 1 ,0.5f }, 0.40f);*/
		}
		SetLinearVelocity(linVel + (acceleration*dt));

		//Angular Movement
		//****************
		if(m_AutoOrient)
		{
			auto desiredOrientation = Elite::VectorToOrientation(GetLinearVelocity());
			SetRotation(desiredOrientation);
		}
		else
		{
			if (output.AngularVelocity > m_MaxAngularSpeed)
				output.AngularVelocity = m_MaxAngularSpeed;
			SetAngularVelocity(output.AngularVelocity);
		}
	}

	m_OldPosition = GetPosition(); // store current position before updating to a new position
}

void SteeringAgent::Render(float dt)
{
	//Use Default Agent Rendering
	BaseAgent::Render(dt);
}

Elite::Vector2 SteeringAgent::GetOldPosition() const
{
	return m_OldPosition;
}

int SteeringAgent::GetCurrentCellIndex() const 
{
	return m_CurrentCellIndex;
}

void SteeringAgent::SetCurrentCellIndex(int idx)
{ 
	m_CurrentCellIndex = idx;
}

float SteeringAgent::GetMaxLinearSpeed() const 
{ 
	return m_MaxLinearSpeed;
}

void SteeringAgent::SetMaxLinearSpeed(float maxLinSpeed) 
{ 
	m_MaxLinearSpeed = maxLinSpeed;
}

float SteeringAgent::GetMaxAngularSpeed() const 
{
	return m_MaxAngularSpeed; 
}

void SteeringAgent::SetMaxAngularSpeed(float maxAngSpeed) 
{ 
	m_MaxAngularSpeed = maxAngSpeed;
}

bool SteeringAgent::IsAutoOrienting() const 
{ 
	return m_AutoOrient; 
}

void SteeringAgent::SetAutoOrient(bool autoOrient)
{
	m_AutoOrient = autoOrient;
}

Elite::Vector2 SteeringAgent::GetDirection() const
{ 
	return GetLinearVelocity().GetNormalized(); 
}

void SteeringAgent::SetSteeringBehavior(ISteeringBehavior* pBehavior) 
{ 
	m_pSteeringBehavior = pBehavior;
}

ISteeringBehavior* SteeringAgent::GetSteeringBehavior() const
{ 
	return m_pSteeringBehavior; 
}

void SteeringAgent::SetDebugRenderingEnabled(bool isEnabled) 
{ 
	m_RenderDebug = isEnabled; 
}

bool SteeringAgent::GetDebugRenderingEnabled() const 
{ 
	return m_RenderDebug; 
}
