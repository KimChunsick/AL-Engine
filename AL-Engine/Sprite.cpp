#include "Core.h"
#include "Sprite.h"

namespace AL
{
	Sprite::Sprite() :
		_pivot(Vector2::Half()),
		_color(Color::White()),
		_texture2D(nullptr)
	{
		D3DXCreateSprite(DXUTGetD3D9Device(), &Director::sprite);
	}

	Sprite::Sprite(const std::wstring path) :
		_pivot(Vector2::Half()),
		_color(Color::White()),
		_texture2D(nullptr)
	{
		_texture2D = TextureManager::GetInstance()->LoadTexture(path);
		D3DXCreateSprite(DXUTGetD3D9Device(), &Director::sprite);
		Renderer::GetInstance()->AddRenderTarget(this);
	}

	Sprite::~Sprite()
	{
		Renderer::GetInstance()->RemoveRenderTarget(this);
	}

	void Sprite::Update()
	{
	}

	void Sprite::Draw()
	{
		if (!IsActive())
			return;

		if (!IsVisible())
			return;

		if (IsCulling())
			return;

		if (_texture2D == nullptr)
			return;

		Director::sprite->Begin(D3DXSPRITE_ALPHABLEND);
		Director::sprite->SetTransform(&GetMatrix());

		D3DXVECTOR3 center(_texture2D->info.Width * _pivot.x, _texture2D->info.Height * _pivot.y, 0.f);

		Director::sprite->Draw(_texture2D->texture, nullptr, &center, nullptr, _color);
		Director::sprite->End();
	}

	void Sprite::SetTexture2D(const std::wstring path)
	{
		_texture2D = TextureManager::GetInstance()->LoadTexture(path);
		Renderer::GetInstance()->AddRenderTarget(this);
	}

	void Sprite::SetPerfectCollider()
	{
		if (_texture2D != nullptr)
			_collider.SetRect(GetPosition(), Vector2(_texture2D->info.Width, _texture2D->info.Height), _pivot, GetScale());
	}

	bool Sprite::IsCulling()
	{
		Collider screenCollider;
		screenCollider.SetRect(Director::GetInstance()->GetScreenSize() * 0.5f, Director::GetInstance()->GetScreenSize(), Vector2::Half(), Vector2::One());

		if (screenCollider.IsAABB(_collider))
			return false;

		return true;
	}
}