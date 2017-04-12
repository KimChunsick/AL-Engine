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
	public:
		Node();
		virtual ~Node();

		virtual void Update();
		virtual void Draw() {}
		virtual void Init() {}

		void AddChild(Node* child);
		void RemoveChild(Node* child);
		void Visit();
		D3DXMATRIX GetMatrix();

		void SetTag(const int tag) { _tag = tag; }
		int GetTag() { return _tag; }

		void SetDepth(const int depth) { SetGlobalDepth(depth); }
		int GetDepth() { return _localDepth; }

		void SetGlobalDepth(const int depth) { _globalDepth = depth; /*Renderer::GetInstance()->RefreshDepthList();*/ }
		int GetGlobalDepth() { return _globalDepth; }

		void SetLocalDepth(const int depth) { _localDepth = depth; /*Renderer::GetInstance()->RefreshDepthList();*/ }
		int GetLocalDepth() { return _localDepth; }

		void SetActive(const bool active) { _isActive = active; }
		bool IsActive() { return _isActive; }

		void SetVisible(const bool visible) { _isVisible = visible; }
		bool IsVisible() { return _isVisible; }

		void SetRotation(const float rotation) { _rotation = rotation; }
		void AddRotation(const float rotation) { _rotation += rotation; }
		float GetRotation() { return _rotation; }

		void SetScale(const Vector2 scale) { _scale = scale; }
		void SetScale(const float x, const float y) { _scale.Set(x, y); }
		void AddScale(const Vector2 scale) { _scale.x += scale.x; _scale.y += scale.y; }
		void AddScale(const float x, const float y) { _scale.x += x; _scale.y += y; }
		Vector2 GetScale() { return _scale; }

		void SetScaleX(const float x) { _scale.x = x; }
		void AddScaleX(const float x) { _scale.x += x; }
		float GetScaleX() { return _scale.x; }

		void SetScaleY(const float y) { _scale.y = y; }
		void AddScaleY(const float y) { _scale.y += y; }
		float GetScaleY() { return _scale.y; }

		void SetPosition(const Vector2 position) { _position = position; }
		void SetPosition(const float x, const float y) { _position.Set(x, y); }
		void AddPosition(const Vector2 position) { _position.x += position.x; _position.y += position.y; }
		void AddPosition(const float x, const float y) { _position.x += x; _position.y += y; }
		Vector2 GetPosition() { return _position; }

		void SetPositionX(const float x) { _position.x = x; }
		void AddPositionX(const float x) { _position.x += x; }
		float GetPositionX() { return _position.x; }

		void SetPositionY(const float y) { _position.y = y; }
		void AddPositionY(const float y) { _position.y += y; }
		float GetPositionY() { return _position.y; }

		void SetParent(Node* parent) { _parent = parent; }
		Node* GetParent() { return _parent; }

		void SetName(const std::string name) { _name = name; }
		std::string GetName() { return _name; }

		std::list<Node*> GetChildren() { return _children; }
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
		
	};
}