#pragma once

#include "DXUT\Core\DXUT.h"
#include "Types.h"
#include "Ref.h"
#include <list>
#include <string>

namespace AL
{
	class Node : public Ref
	{
	private:
		int					_tag;
		int					_localDepth;
		int					_globalDepth;
		bool				_isActive;
		bool				_isVisible;
		float				_rotation;

		Vector2				_scale;
		Vector2				_position;
		Node*				_parent;
		std::string			_name;
		std::list<Node*>	_children;

	public:
		Node();
		virtual ~Node();

		virtual void Update();
		virtual void Draw() {}
		virtual void Init() {}

		void AddChild(Node* child);
		void RemoveChild(Node* child);
		void Visit();
		const D3DXMATRIX GetMatrix() const;

		void SetTag(const int tag) { _tag = tag; }
		const int GetTag() const { return _tag; }

		void SetDepth(const int depth) { SetGlobalDepth(depth); }
		const int GetDepth() const { return _localDepth; }

		void SetGlobalDepth(const int depth) { _globalDepth = depth; }
		const int GetGlobalDepth() const { return _globalDepth; }

		void SetLocalDepth(const int depth) { _localDepth = depth; }
		const int GetLocalDepth() const { return _localDepth; }

		void SetActive(const bool active) { _isActive = active; }
		const bool IsActive() const { return _isActive; }

		void SetVisible(const bool visible) { _isVisible = visible; }
		const bool IsVisible() const { return _isVisible; }

		void SetRotation(const float rotation) { _rotation = rotation; }
		void AddRotation(const float rotation) { _rotation += rotation; }
		const float GetRotation() const { return _rotation; }

		void SetScale(const Vector2 scale) { _scale = scale; }
		void SetScale(const float x, const float y) { _scale.Set(x, y); }
		void AddScale(const Vector2 scale) { _scale.x += scale.x; _scale.y += scale.y; }
		void AddScale(const float x, const float y) { _scale.x += x; _scale.y += y; }
		const Vector2 GetScale() const { return _scale; }

		void SetScaleX(const float x) { _scale.x = x; }
		void AddScaleX(const float x) { _scale.x += x; }
		const float GetScaleX() const { return _scale.x; }

		void SetScaleY(const float y) { _scale.y = y; }
		void AddScaleY(const float y) { _scale.y += y; }
		const float GetScaleY() const { return _scale.y; }

		void SetPosition(const Vector2 position) { _position = position; }
		void SetPosition(const float x, const float y) { _position.Set(x, y); }
		void AddPosition(const Vector2 position) { _position.x += position.x; _position.y += position.y; }
		void AddPosition(const float x, const float y) { _position.x += x; _position.y += y; }
		const Vector2 GetPosition() const { return _position; }

		void SetPositionX(const float x) { _position.x = x; }
		void AddPositionX(const float x) { _position.x += x; }
		const float GetPositionX() const { return _position.x; }

		void SetPositionY(const float y) { _position.y = y; }
		void AddPositionY(const float y) { _position.y += y; }
		const float GetPositionY() const { return _position.y; }

		void SetParent(Node* parent) { _parent = parent; }
		const Node* GetParent() const { return _parent; }

		void SetName(const std::string name) { _name = name; }
		const std::string GetName() const { return _name; }

		const std::list<Node*> GetChildren() const { return _children; }
	
	private:
		void RemoveChildRecursive(Node* child);
	
	};
}