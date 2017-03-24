#pragma once

#include "Types.h"
#include "Node.h"
#include "Texture.h"
#include <string>

namespace AL
{
	class Sprite : public Node
	{
	public:
		Sprite();
		Sprite(const std::wstring);
		virtual ~Sprite();

		void Update() override;
		void Draw() override;

		void SetTexture2D(const std::wstring);
		Texture2D* GetTexture2D() { return _texture2D; }

		void SetPivot(const Vector2 pivot) { _pivot = pivot; }
		void SetPivot(const float x, const float y) { _pivot.Set(x, y); }
		Vector2 GetPivot() { return _pivot; }

		void SetColor(const Color color) { _color = color; }
		void SetColor(const float r, const float g, const float b) { _color.Set(r, g, b); }
		void SetColor(const float r, const float g, const float b, const float a) { _color.Set(r, g, b, a); }
		Color GetColor() { return _color; }

	private:
		bool IsCulling();

	private:
		Vector2 _pivot;
		Color _color;
		Texture2D* _texture2D;

		Collider _collider;
	};
}