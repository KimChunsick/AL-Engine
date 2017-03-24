#pragma once
#include "DXUT\Core\DXUT.h"

namespace AL
{
	template <class T>
	class Singleton
	{
	public:
		Singleton() {}
		virtual ~Singleton() {}

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
		Vector2() {}
		Vector2(float x, float y);

		static Vector2 Zero() { return Vector2(0, 0); }
		static Vector2 Half() { return Vector2(0.5f, 0.5f); }
		static Vector2 One() { return Vector2(1, 1); }

		static Vector2 Right() { return Vector2(1, 0); }
		static Vector2 Left() { return Vector2(-1, 0); }
		static Vector2 Up() { return Vector2(0, 1); }
		static Vector2 Down() { return Vector2(0, -1); }

		inline Vector2& operator=(const D3DXVECTOR2& vector2)
		{
			x = vector2.x;
			y = vector2.y;
		}

		inline Vector2 operator * (Vector2 vector2) const
		{
			Vector2 temp;
			temp.x = x * vector2.x;
			temp.y = y * vector2.y;
			return temp;
		}

		inline Vector2 operator * (float value) const
		{
			Vector2 temp;
			temp.x = x * value;
			temp.y = y * value;
			return temp;
		}

		inline Vector2 operator / (Vector2 vector2) const
		{
			Vector2 temp;
			temp.x = x / vector2.x;
			temp.y = y / vector2.y;
			return temp;
		}

		inline Vector2 operator / (float value) const
		{
			Vector2 temp;
			temp.x = x / value;
			temp.y = y / value;
			return temp;
		}

		inline static Vector2 Lerping(const Vector2 began, const Vector2 end, float time)
		{
			return Vector2(Lerp(began.x, end.x, time), Lerp(began.y, end.y, time));
		}
		
		inline Vector2 Lerping(const Vector2 other, float time)
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
		Color(float r, float g, float b);
		Color(float r, float g, float b, float a);

		static Color White() { return Color(1.f, 1.f, 1.f, 1.f); }
		static Color Black() { return Color(0.f, 0.f, 0.f, 1.f); }
		static Color Red() { return Color(1.f, 0.f, 0.f, 1.f); }
		static Color Green() { return Color(0.f, 1.f, 0.f, 1.f); }
		static Color Blue() { return Color(0.f, 0.f, 1.f, 1.f); }

		inline Color& operator=(const D3DXCOLOR& color)
		{
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
		}

		inline static Color Lerping(const Color began, const Color end, float time)
		{
			return Color(Lerp(began.r, end.r, time), Lerp(began.g, end.g, time),
						 Lerp(began.b, end.b, time), Lerp(began.a, end.a, time));
		}

		inline Color Lerping(const Color other, float time)
		{
			Color me = *this;
			return Color(Lerp(me.r, other.r, time), Lerp(me.g, other.g, time),
						 Lerp(me.b, other.b, time), Lerp(me.a, other.a, time));
		}

		void Set(float r, float g, float b);
		void Set(float r, float g, float b, float a);
	};

	class Time
	{
	public:
		Time();
		~Time();

	public:
		static float deltaTime;
		static float smoothDeltaTime;
		static float time;
		static float timeScale;
	};
}