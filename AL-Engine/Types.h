#pragma once
#include "DXUT\Core\DXUT.h"

namespace AL
{
	template <class T>
	class Singleton
	{
	public:
		Singleton() = default;
		virtual ~Singleton() = default;

		static T* GetInstance()
		{
			if (_instance == nullptr)
				_instance = new T();
			return _instance;
		}

		static void ReleaseInstance()
		{
			SAFE_DELETE(_instance);
		}

	private:
		static T* _instance;
	};
	template <class T> T* Singleton<T>::_instance = nullptr;

	template <typename T>
	T Lerp(T began, T end, float time)
	{
		return (began + ((T)(end - began) * time));
	}
	
	class Vector2 : public D3DXVECTOR2
	{
	public:
		Vector2() = default;
		Vector2(const float x, const float y);

		static const Vector2 Zero() { return Vector2(0, 0); }
		static const Vector2 Half() { return Vector2(0.5f, 0.5f); }
		static const Vector2 One() { return Vector2(1, 1); }

		static const Vector2 Right() { return Vector2(1, 0); }
		static const Vector2 Left() { return Vector2(-1, 0); }
		static const Vector2 Up() { return Vector2(0, 1); }
		static const Vector2 Down() { return Vector2(0, -1); }

		inline const Vector2& operator=(const D3DXVECTOR2& vector2)
		{
			x = vector2.x;
			y = vector2.y;
		}

		inline const Vector2 operator * (Vector2 vector2) const
		{
			Vector2 temp;
			temp.x = x * vector2.x;
			temp.y = y * vector2.y;
			return temp;
		}

		inline const Vector2 operator * (float value) const
		{
			Vector2 temp;
			temp.x = x * value;
			temp.y = y * value;
			return temp;
		}

		inline const Vector2 operator / (Vector2 vector2) const
		{
			Vector2 temp;
			temp.x = x / vector2.x;
			temp.y = y / vector2.y;
			return temp;
		}

		inline const Vector2 operator / (float value) const
		{
			Vector2 temp;
			temp.x = x / value;
			temp.y = y / value;
			return temp;
		}

		inline static const Vector2 Lerping(const Vector2 began, const Vector2 end, const float time)
		{
			return Vector2(Lerp(began.x, end.x, time), Lerp(began.y, end.y, time));
		}
		
		inline const Vector2 Lerping(const Vector2 other, const float time)
		{
			Vector2 me = *this;
			return Vector2(Lerp(me.x, other.x, time), Lerp(me.y, other.y, time));
		}
		
		void Normalize();
		void Set(float x, float y);
		float Distance(const Vector2&) const;
		
		Vector2 GetNormalized();
	};

	class Color : public D3DXCOLOR
	{
	public:
		Color() = default;
		Color(const float r, const float g, const float b);
		Color(const float r, const float g, const float b, const float a);

		static const Color White() { return Color(1.f, 1.f, 1.f, 1.f); }
		static const Color Black() { return Color(0.f, 0.f, 0.f, 1.f); }
		static const Color Red() { return Color(1.f, 0.f, 0.f, 1.f); }
		static const Color Green() { return Color(0.f, 1.f, 0.f, 1.f); }
		static const Color Blue() { return Color(0.f, 0.f, 1.f, 1.f); }

		inline const Color& operator=(const D3DXCOLOR& color)
		{
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}

		inline static const Color Lerping(const Color began, const Color end, float time)
		{
			return Color(Lerp(began.r, end.r, time), Lerp(began.g, end.g, time),
						 Lerp(began.b, end.b, time), Lerp(began.a, end.a, time));
		}

		inline const Color Lerping(const Color other, float time)
		{
			Color me = *this;
			return Color(Lerp(me.r, other.r, time), Lerp(me.g, other.g, time),
						 Lerp(me.b, other.b, time), Lerp(me.a, other.a, time));
		}

		void Set(const float r, const float g, const float b);
		void Set(const float r, const float g, const float b, const float a);
	};

	class Time
	{
	public:
		Time() = default;
		virtual ~Time() = default;

	public:
		static float deltaTime;
		static float smoothDeltaTime;
		static float time;
		static float timeScale;
	};
}