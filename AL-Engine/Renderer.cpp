#include "Core.h"
#include "Renderer.h"

namespace AL
{
	void Renderer::Render()
	{
		Sort();
		RenderTargets();
	}

	void Renderer::Sort()
	{
		_renderTargets.sort([=](Node* node1, Node* node2) {return node1->GetLocalDepth() < node2->GetLocalDepth(); });
		_renderTargets.sort([=](Node* node1, Node* node2) {return node1->GetGlobalDepth() < node2->GetGlobalDepth(); });
	}

	void Renderer::RenderTargets()
	{
		for (Node* node : _renderTargets)
		{
			node->Draw();
		}
	}

	void Renderer::AddRenderTarget(Node * node)
	{
		if (std::find(_renderTargets.begin(), _renderTargets.end(), node) != _renderTargets.end())
			return;

		_renderTargets.push_back(node);
		Sort();
	}

	void Renderer::RemoveRenderTarget(Node * node)
	{
		_renderTargets.remove(node);
	}
}