
// SrvrItem.h : interface of the CDeviceSimulatorSrvrItem class
//

#pragma once

class CDeviceSimulatorSrvrItem : public CDocObjectServerItem
{
	DECLARE_DYNAMIC(CDeviceSimulatorSrvrItem)

// Constructors
public:
	CDeviceSimulatorSrvrItem(CDeviceSimulatorDoc* pContainerDoc);

// Attributes
	CDeviceSimulatorDoc* GetDocument() const
		{ return reinterpret_cast<CDeviceSimulatorDoc*>(CDocObjectServerItem::GetDocument()); }

// Overrides
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);

// Implementation
public:
	~CDeviceSimulatorSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

