
// DeviceSimulatorDoc.h : interface of the CDeviceSimulatorDoc class
//


#pragma once


class CDeviceSimulatorSrvrItem;

class CDeviceSimulatorDoc : public COleServerDoc
{
protected: // create from serialization only
	CDeviceSimulatorDoc() noexcept;
	DECLARE_DYNCREATE(CDeviceSimulatorDoc)

// Attributes
public:
	CDeviceSimulatorSrvrItem* GetEmbeddedItem()
		{ return reinterpret_cast<CDeviceSimulatorSrvrItem*>(COleServerDoc::GetEmbeddedItem()); }

// Operations
public:

// Overrides
protected:
	virtual COleServerItem* OnGetEmbeddedItem();
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CDeviceSimulatorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual CDocObjectServer* GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite);

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
