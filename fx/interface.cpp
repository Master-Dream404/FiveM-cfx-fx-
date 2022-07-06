#include "interface.h"

#include <Windows.h>

namespace fx
{
	intptr_t findFirstImpl(const guid_t& iid, guid_t* clsid)
	{
		static intptr_t(*CoreFxFindFirstImpl)(const guid_t & iid, guid_t * clsid) =
			(decltype(CoreFxFindFirstImpl))GetProcAddress(GetModuleHandle(L"CoreRT.dll"), "CoreFxFindFirstImpl");

		return CoreFxFindFirstImpl(iid, clsid);
	}

	int32_t findNextImpl(intptr_t findHandle, guid_t* clsid)
	{
		static int32_t(*CoreFxFindNextImpl)(intptr_t findHandle, guid_t * clsid) =
			(decltype(CoreFxFindNextImpl))GetProcAddress(GetModuleHandle(L"CoreRT.dll"), "CoreFxFindNextImpl");

		return CoreFxFindNextImpl(findHandle, clsid);
	}

	void findImplClose(intptr_t findHandle)
	{
		static void(*CoreFxFindImplClose)(intptr_t findHandle) =
			(decltype(CoreFxFindImplClose))GetProcAddress(GetModuleHandle(L"CoreRT.dll"), "CoreFxFindImplClose");

		return CoreFxFindImplClose(findHandle);
	}

	uint32_t createObjectInstance(const guid_t& guid, const guid_t& iid, void** objectRef)
	{
		static uint32_t(*CoreFxCreateObjectInstance)(const guid_t & guid, const guid_t & iid, void** objectRef) =
			(decltype(CoreFxCreateObjectInstance))GetProcAddress(GetModuleHandle(L"CoreRT.dll"), "CoreFxCreateObjectInstance");

		return CoreFxCreateObjectInstance(guid, iid, objectRef);
	}
} // fx