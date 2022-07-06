#include "component.h"

#include <Windows.h>

namespace fx
{
	ComponentRegistryImpl* ComponentRegistry::get_impl()
	{
		static ComponentRegistryImpl* (*CoreGetComponentRegistry)() =
			(decltype(CoreGetComponentRegistry))GetProcAddress(GetModuleHandle(L"CoreRT.dll"), "CoreGetComponentRegistry");

		return CoreGetComponentRegistry();
	}
} // fx