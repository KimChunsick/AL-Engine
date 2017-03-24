#pragma once

#include <iostream>
#include <cstdarg>
#include "Types.h"

namespace AL
{
	class ALLog
	{
	public:
		static void Print(Vector2 log, ...);
	
	private:
		void SetPrint(FILE* out, va_list list);
	};
}