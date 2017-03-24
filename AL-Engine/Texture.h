#pragma once

#include "DXUT\Core\DXUT.h"
#include <list>
#include "Types.h"
#include "Ref.h"

namespace AL
{
	class Texture2D : public Ref
	{
	public:
		Texture2D();
		virtual ~Texture2D();

		void Release() override;

	public:
		std::wstring fileName;
		D3DXIMAGE_INFO info;
		LPDIRECT3DTEXTURE9 texture;
	};

	class TextureManager : public Singleton<TextureManager>
	{
	public:
		TextureManager() {}
		virtual ~TextureManager() {}
		
		Texture2D* LoadTexture(const std::wstring);
		std::list<Texture2D*> GetTexturePool();
		void AddTexturePool(Texture2D*);
		void RemoveTexture(Texture2D*);
		void Drain();

	private:
		std::list<Texture2D*> _texturePool;
	};
}