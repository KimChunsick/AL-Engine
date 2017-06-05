#include "UIManager.h"

void UIManager::Init(Node* const parent)
{
	_scoreValue = 0;
	_score = new Label();
	_score->Init(L"Score : 0", 30, 60, LABEL_TYPE::NORMAL, false, LABEL_QUALITY::NORMAL, L"Fade to grey");
	_score->SetPosition(Director::GetInstance()->GetScreenSize().x * 0.5f, 20);
	_score->SetFormat(LABEL_ALIGHN::RIGHR);
	_score->SetGlobalDepth(10000);
	parent->AddChild(_score);
	_parent = parent;
}

void UIManager::AddScore(int value)
{
	_scoreValue += value;
	TCHAR temp[100];
	wsprintf(temp, L"Score : %d", _scoreValue);
	_score->SetText(temp);
}

void UIManager::Release()
{
	_parent->RemoveChild(_score);
	
	ReleaseInstance();
}
