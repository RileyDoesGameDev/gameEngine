#include "PickUp.h"
#include "Player.h"

void PickUp::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Player")
	{
		dynamic_cast<Player*>(actor)->SetFireModifier(1);
		m_destroyed = true;
	}
}     