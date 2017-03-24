#pragma once

#include "Node.h"

namespace AL
{
	class Scene : public Node
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void OnEnter() {};
		virtual void OnExit() {};
		virtual void Update() {};
	};
}