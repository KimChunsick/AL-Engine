#pragma once

#include "Node.h"



namespace AL
{
	//TODO : fix codination setting
	class Collider
	{
	public:
		Collider();
		~Collider() {}

		Collider& operator= (const Collider& collider);

		void SetRect(float x, float y, float width, float height, Vector2 pivot, Vector2 _scale);
		void SetRect(Vector2 position, float width, float height, Vector2 pivot, Vector2 _scale);
		void SetRect(Vector2 position, Vector2 size, Vector2 pivot, Vector2 _scale);
		float GetMaxX() const;
		float GetMaxY() const;
		float GetMinX() const;
		float GetMinY() const;
		float GetMidX() const;
		float GetMidY() const;

		bool IsAABB(Collider collision);

		Vector2 GetRigin() { return _origin; }
		Vector2 GetSize() { return _size; }

	private:
		Vector2 _origin;
		Vector2 _size;
		Vector2 _pivot;
		Vector2 _scale;
	};
}