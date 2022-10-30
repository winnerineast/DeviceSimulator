
// CntrItem.h : interface of the CDeviceSimulatorCntrItem class
//

#pragma once

class CDeviceSimulatorDoc;
class CDeviceSimulatorView;

class CDeviceSimulatorCntrItem : public COleDocObjectItem
{
	DECLARE_SERIAL(CDeviceSimulatorCntrItem)

// Constructors
public:
	CDeviceSimulatorCntrItem(CDeviceSimulatorDoc* pContainer = nullptr);
		// Note: pContainer is allowed to be null to enable IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-null document pointer

// Attributes
public:
	CDeviceSimulatorDoc* GetDocument()
		{ return reinterpret_cast<CDeviceSimulatorDoc*>(COleDocObjectItem::GetDocument()); }
	CDeviceSimulatorView* GetActiveView()
		{ return reinterpret_cast<CDeviceSimulatorView*>(COleDocObjectItem::GetActiveView()); }

public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();

protected:
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	virtual BOOL OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow);
	virtual BOOL CanActivate();

// Implementation
public:
	~CDeviceSimulatorCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

