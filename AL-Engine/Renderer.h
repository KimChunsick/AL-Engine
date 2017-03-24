#pragma once

#include "Types.h"
#include "Node.h"
#include <list>

namespace AL
{
	/*
	TODO : Remove Renderer
		   Draw Recurvely
	*/
	class Renderer : public Singleton<Renderer>
	{
	public:
		virtual ~Renderer() { }

		void Render();
		void AddRenderTarget(Node* node);
		void RemoveRenderTarget(Node* node);

	private:
		void Sort();
		void RenderTargets();

	private:
		std::list<Node*> _renderTargets;
	};
}