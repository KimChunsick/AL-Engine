#pragma once

#include "Node.h"

namespace AL
{
	enum class LABEL_TYPE : int
	{
		NORMAL = FW_DONTCARE,
		MEDIUM = FW_MEDIUM,
		REGULAR = FW_REGULAR,

		THIN = FW_THIN,
		LIGHT = FW_LIGHT,
		ULTRA_LIGHT = FW_ULTRALIGHT,
		
		SEMI_BOLD = FW_SEMIBOLD,
		BOLD = FW_BOLD,
		ULTRA_BOLD = FW_ULTRABOLD,
		HEABY = FW_HEAVY,
	};

	enum class LABEL_QUALITY : int
	{
		NORMAL = DEFAULT_QUALITY,
		DRAFT = DRAFT_QUALITY,
		PROOF = PROOF_QUALITY,
	};

	class Label : public Node
	{
	private:
		std::wstring _text;
		Color _color;
		LPD3DXFONT _font;
		unsigned int _width;
		unsigned int _height;

	public:
		Label() : _font(nullptr), _text(L""), _color(Color::White()), _width(0), _height(0) { }
		Label(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality);
		Label(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality, const Color color);
		Label(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality, const std::wstring fontName);
		Label(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality, const std::wstring fontName, const Color color);
		
		virtual ~Label() 
		{
			Renderer::GetInstance()->RemoveRenderTarget(this);
			SAFE_RELEASE(_font);
		}

		void Init(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality);
		void Init(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality, const Color color);
		void Init(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality, const std::wstring fontName);
		void Init(const std::wstring text, const unsigned int width, const unsigned int height, const LABEL_TYPE type, bool isItalic, const LABEL_QUALITY quality, const std::wstring fontName, const Color color);

		void Draw() override;

		void SetText(const std::wstring text) { _text = text; }
		const std::wstring GetText() { return _text; }
	
		void SetColor(const Color color) { _color = color; }
		const Color GetColor() const { return _color; }
	};
}