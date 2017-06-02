#pragma once

#include "Node.h"



namespace AL
{
	class Collider
	{
	public:
		Collider();
		~Collider() {}

		Collider& operator= (const Collider& collider);

		//void SetRect(float x, float y, float width, float height, Vector2 pivot, Vector2 _scale);
		void SetRect(const Vector2 position, const float width, const float height, const Vector2 pivot, const Vector2 scale);
		void SetRect(const Vector2 position, const Vector2 size, const Vector2 pivot, const Vector2 scale);
		const float GetMaxX() const;
		const float GetMaxY() const;
		const float GetMinX() const;
		const float GetMinY() const;
		const float GetMidX() const;
		const float GetMidY() const;

		bool IsAABB(Collider collision);

		Vector2 GetRigin() { return _origin; }
		Vector2 GetSize() { return _size; }

	private:
		Vector2 _origin;
		Vector2 _size;
	};
}