#include "Core.h"
#include "Collider.h"

namespace AL
{
	Collider::Collider()
	{
		SetRect(0.f, 0.f, 0.f, 0.f, Vector2::Zero(), Vector2::One());
	}

	Collider & Collider::operator=(const Collider & collider)
	{
		SetRect(collider._origin, collider._size, collider._pivot, collider._scale);
		return *this;
	}

	void Collider::SetRect(float x, float y, float width, float height, Vector2 pivot, Vector2 _scale)
	{
		_origin.x = x;
		_origin.y = y;
		_size.x = width * pivot.x * _scale.x;
		_size.y = height * pivot.y * _scale.y;
	}

	void Collider::SetRect(Vector2 position, float width, float height, Vector2 pivot, Vector2 _scale)
	{
		_origin = position;
		_size.x = width * pivot.x * _scale.x;
		_size.y = height * pivot.y * _scale.y;
	}

	void Collider::SetRect(Vector2 position, Vector2 size, Vector2 pivot, Vector2 _scale)
	{
		_origin = position;
		_size = size * pivot * _scale;
	}

	float Collider::GetMaxX() const
	{
		return _origin.x + _size.x;
	}

	float Collider::GetMaxY() const
	{
		return _origin.y + _size.y;
	}

	float Collider::GetMinX() const
	{
		return _origin.x - _size.x;
	}

	float Collider::GetMinY() const
	{
		return _origin.y - _size.y;
	}

	float Collider::GetMidX() const
	{
		return _origin.x;
	}

	float Collider::GetMidY() const
	{
		return _origin.y;
	}

	bool Collider::IsAABB(Collider collider)
	{
		if (collider.GetMaxX() < GetMinX() ||
			collider.GetMinX() > GetMaxX() ||
			collider.GetMaxY() < GetMinY() ||
			collider.GetMinY() > GetMaxY())
			return false;
		return true;
	}
}
