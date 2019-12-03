
#include "pch.h"

#include "VssSnapshotManagement.h"
#include "VssDifferentialSoftwareSnapshotManagement.h"

namespace Alphaleonis { namespace Win32 { namespace Vss
{
	VssSnapshotManagement::VssSnapshotManagement()
	{
		::IVssSnapshotMgmt *pMgmt = 0;
		CheckCom(CoCreateInstance(CLSID_VssSnapshotMgmt, NULL, CLSCTX_ALL, IID_IVssSnapshotMgmt, (void**)&(pMgmt)));		
		m_snapshotMgmt = pMgmt;
	}


	VssSnapshotManagement::~VssSnapshotManagement()
	{
		this->!VssSnapshotManagement();
	}

	VssSnapshotManagement::!VssSnapshotManagement()
	{
		if (m_snapshotMgmt != 0)
		{
			m_snapshotMgmt->Release();
			m_snapshotMgmt = 0;
		}

		if (m_IVssSnapshotMgmt2 != 0)
		{
			m_IVssSnapshotMgmt2->Release();
			m_IVssSnapshotMgmt2 = 0;
		}
	}

	IVssDifferentialSoftwareSnapshotManagement^ VssSnapshotManagement::GetDifferentialSoftwareSnapshotManagementInterface()
	{
		// software-provider id is {b5946137-7b9f-4925-af80-51abd60b20d5}
		const VSS_ID ProviderId = { 0xb5946137, 0x7b9f, 0x4925, { 0xaf,0x80,0x51,0xab,0xd6,0xb,0x20,0xd5 } };
		IVssDifferentialSoftwareSnapshotMgmt* pDiffMgmt;
		CheckCom(m_snapshotMgmt->GetProviderMgmtInterface(ProviderId, IID_IVssDifferentialSoftwareSnapshotMgmt, (IUnknown**)&pDiffMgmt));
		return gcnew VssDifferentialSoftwareSnapshotManagement(pDiffMgmt);
	}

	Int64 VssSnapshotManagement::GetMinDiffAreaSize()
	{
		LONGLONG llMinDiffAreaSize;
		CheckCom(RequireIVssSnapshotMgmt2()->GetMinDiffAreaSize(&llMinDiffAreaSize));
		return llMinDiffAreaSize;
	}

}
}}