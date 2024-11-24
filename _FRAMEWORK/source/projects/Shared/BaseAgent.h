#ifndef BASE_AGENT_H
#define BASE_AGENT_H

class BaseAgent
{
public:
	BaseAgent(float radius = 1.f);
	virtual ~BaseAgent();

	virtual void Update(float dt);
	virtual void Render(float dt);

	//Functions
	void TrimToWorld(float worldBounds, bool isWorldLooping = true) const;
	void TrimToWorld(const Elite::Vector2& bottomLeft, const Elite::Vector2& topRight, bool isWorldLooping = true) const;

	//Get - Set
	Elite::Vector2 GetPosition() const;
	void SetPosition(const Elite::Vector2& pos) const;

	float GetRotation() const;
	void SetRotation(float rot) const;

	Elite::Vector2 GetLinearVelocity() const;
	void SetLinearVelocity(const Elite::Vector2& linVel) const;

	float GetAngularVelocity() const;
	void SetAngularVelocity(float angVel) const;
	
	float GetMass() const;
	void SetMass(float mass) const;

	const Elite::Color& GetBodyColor() const;
	void SetBodyColor(const Elite::Color& col);

	Elite::RigidBodyUserData GetUserData() const;
	void SetUserData(Elite::RigidBodyUserData userData);

	float GetRadius() const { return m_Radius; }

protected:
	RigidBody* m_pRigidBody = nullptr;
	float m_Radius = 1.f;
	Elite::Color m_BodyColor = { 1,1,0,1 };

private:

	//C++ make the class non-copyable
	BaseAgent(const BaseAgent&) {};
	BaseAgent& operator=(const BaseAgent&) {};
};
#endif