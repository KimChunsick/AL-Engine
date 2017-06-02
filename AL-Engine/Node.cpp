#include "Node.h"

namespace AL
{
	Node::Node() :
		_tag(0),
		_isActive(true),
		_isVisible(true),
		_rotation(0.0f),
		_scale(Vector2::One()),
		_position(Vector2::Zero()),
		_parent(nullptr),
		_localDepth(0),
		_globalDepth(0),
		_name("")
	{
		SetAutoRelease();
	}

	Node::~Node()
	{
		for (auto it : _children)
			it->Release();
	}

	void Node::Update()
	{
		for (auto it = _children.begin(); it != _children.end(); it++)
		{
			if ((*it)->_isActive)
				(*it)->Visit();
		}
	}

	void Node::AddChild(Node * child)
	{
		child->_parent = this;
		child->Retain();
		_children.push_back(child);
	}

	void Node::RemoveChild(Node * child)
	{
		_children.remove(child);
	}

	void Node::Visit()
	{
		if (!_children.empty())
		{
			for (auto it = _children.begin(); it != _children.end(); it++)
			{
				if ((*it))
				{
					if ((*it)->_isActive)
						(*it)->Visit();
					else
						continue;
				}
				else
					break;
			}
			Update();
		}
		else
		{
			Update();
		}
	}

	const D3DXMATRIX Node::GetMatrix() const
	{
		D3DXMATRIX m;
		D3DXMatrixIdentity(&m);
		D3DXMatrixTransformation2D(&m, nullptr, 0, &_scale, nullptr, _rotation, &_position);

		if (_parent)
			m *= _parent->GetMatrix();

		return m;
	}
}