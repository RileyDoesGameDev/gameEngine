#include "Bullet.h"

void Bullet::Update(float dt)
{

	//create paricle trall
	/*particl::Data data
	{
		m_transform.position,
		Vector2{1,0}. rotation(randomMath::TwoPi))*50,
		randomf(0.5f, 2.0f),
		255,255,255,255.
	}
	*/

	m_velocity = Vector2(1, 0).Rotate(m_transform.rotation);
	// add wrap
}

void Bullet::OnCollision(Actor* actor)
{

}
