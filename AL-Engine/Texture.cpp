#include "Core.h"
#include "Texture.h"

namespace AL
{
	Texture2D::Texture2D()
	{
		this->Retain();
	}

	Texture2D::~Texture2D()
	{
	}

	void Texture2D::Release()
	{
		--_refCount;

		if (_refCount == 0)
		{
			TextureManager::GetInstance()->RemoveTexture(this);
			delete this;
		}
	}
	
	Texture2D * TextureManager::LoadTexture(const std::wstring fileName)
	{
		for (auto texture : _texturePool)
		{
			if (texture->fileName == fileName)
			{
				texture->Retain();
				return texture;
			}
		}

		auto route = L"../Resources/" + fileName;
		LPDIRECT3DTEXTURE9 temp;
		Texture2D* texture = new Texture2D();
		texture->fileName = fileName;

		auto isFail = D3DXCreateTextureFromFileEx(DXUTGetD3D9Device(), route.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 1, 0,
			D3DFORMAT::D3DFMT_A8B8G8R8, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, &texture->info, nullptr, &texture->texture);

		if (FAILED(isFail))
		{
			std::wcout << L"CAN'T LOAD : " << route.c_str() << std::endl;
			return nullptr;
		}
		else
		{
			std::wcout << L"LOAD : " << route.c_str() << std::endl;
			_texturePool.push_back(texture);
			return texture;
		}
	}

	std::list<Texture2D*> TextureManager::GetTexturePool()
	{
		return _texturePool;
	}

	void TextureManager::AddTexturePool(Texture2D * texture2d)
	{
		_texturePool.push_back(texture2d);
	}

	void TextureManager::RemoveTexture(Texture2D * texture2d)
	{
		_texturePool.remove(texture2d);
	}

	void TextureManager::Drain()
	{
		for (auto it : _texturePool)
		{
			SAFE_RELEASE(it->texture);
			SAFE_DELETE(it);
		}
		_texturePool.clear();
	}
}