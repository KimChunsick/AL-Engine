#include "Core.h"
#include "Collider.h"

namespace AL
{
	Collider::Collider() : _size(Vector2::Zero()), _origin(Vector2::Zero())
	{ }

	Collider & Collider::operator=(const Collider & collider)
	{
		this->_origin = collider._origin;
		this->_size = collider._size;
		return *this;
	}

	/*void Collider::SetRect(float x, float y, float width, float height, Vector2 pivot, Vector2 scale)
	{
		_origin.x = x;
		_origin.y = y;
		_size.x = width * pivot.x * scale.x;
		_size.y = height * pivot.y * scale.y;
	}*/

	void Collider::SetRect(const Vector2 position, const float width, const float height, const Vector2 pivot, const Vector2 scale)
	{
		_origin = position;
		_size.x = width * pivot.x * scale.x;
		_size.y = height * pivot.y * scale.y;
	}

	void Collider::SetRect(const Vector2 position, const Vector2 size, const Vector2 pivot, const Vector2 scale)
	{
		_origin = position;
		_size = size * pivot * scale;
	}

	const float Collider::GetMaxX() const
	{
		return _origin.x + _size.x;
	}

	const float Collider::GetMaxY() const
	{
		return _origin.y + _size.y;
	}

	const float Collider::GetMinX() const
	{
		return _origin.x - _size.x;
	}

	const float Collider::GetMinY() const
	{
		return _origin.y - _size.y;
	}

	const float Collider::GetMidX() const
	{
		return _origin.x;
	}

	const float Collider::GetMidY() const
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
