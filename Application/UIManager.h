#pragma once

#include <Core.h>

class UIManager : public Singleton<UIManager>
{
public:
	UIManager() = default;
	virtual ~UIManager() = default;

	void Init(Node* const parent);
	void AddScore(int const value);

private:
	int _scoreValue;
	Label* _score;
};