#include "Types.h"

namespace AL
{
	Color::Color(const float r, const float g, const float b)
	{
		Set(r, g, b);
	}

	Color::Color(const float r, const float g, const float b, const float a)
	{
		Set(r, g, b, a);
	}

	void Color::Set(const float r, const float g, const float b)
	{
		(*this).r = r;
		(*this).g = g;
		(*this).b = b;
	}

	void Color::Set(const float r, const float g, const float b, const float a)
	{
		(*this).r = r;
		(*this).g = g;
		(*this).b = b;
		(*this).a = a;
	}

	Vector2::Vector2(const float x, const float y)
	{
		(*this).x = x;
		(*this).y = y;
	}

	float Vector2::Distance(const Vector2& vec2) const
	{
		float dx = vec2.x - x;
		float dy = vec2.y - y;

		// TODO!
		// FaseInvSqrt로 변경하기
		return sqrt(dx * dx + dy * dy);
	}

	void Vector2::Normalize()
	{
		float n = x * x + y * y;
		if (n == 1.0f)
			return;

		n = sqrt(n);
		if (n < 2e-37f)
			return;

		n = 1.0f / n;
		x *= n;
		y *= n;
	}

	void Vector2::Set(float x, float y)
	{
		(*this).x = x;
		(*this).y = y;
	}

	void Vector2::Set(Vector2 vector)
	{
		(*this).x = vector.x;
		(*this).y = vector.y;
	}

	Vector2 Vector2::GetNormalized()
	{
		Vector2 temp = *this;
		temp.Normalize();
		return temp;
	}

	float Time::deltaTime = 0.f;
	float Time::smoothDeltaTime = (1.f / 60.f);
	float Time::time = 0.f;
	float Time::timeScale = 1.f;
}
