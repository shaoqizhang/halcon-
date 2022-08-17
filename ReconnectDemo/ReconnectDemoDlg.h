
// BasicDemoDlg.h : header file
//

#pragma once
#include "afxwin.h" 

#include <stdio.h>

#include "MyCamera.h"

// ch:���Ⱥ궨�� | en:Length macro definition
#define MAX_BUF_SIZE            (2560*1920*6)
#define MAX_XML_FILE_SIZE       (1024*1024*3)

// ch:���������붨�� | en:Function return code definition
typedef int Status;
#define STATUS_OK               0
#define STATUS_ERROR            -1

// CBasicDemoDlg dialog
class CBasicDemoDlg : public CDialog
{
// Construction
public:
	CBasicDemoDlg(CWnd* pParent = NULL);	// Standard constructor

// Dialog Data
	enum { IDD = IDD_BasicDemo_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

// ch:�ؼ���Ӧ���� | en:Control corresponding variable
private:
    // ch:��ʼ�� | en:Initialization
    CButton m_ctrlOpenButton;                   // ch:���豸 | en:Open device
    CButton m_ctrlCloseButton;                  // ch:�ر��豸 | en:Close device

    // ch:ͼ��ɼ� | en:Image Acquisition
    CButton m_ctrlContinusModeRadio;            // ch:����ģʽ | en:Continus Mode
    CButton m_ctrlTriggerModeRadio;             // ch:����ģʽ | en:Trigger mode
    CButton m_ctrlStartGrabbingButton;          // ch:��ʼץͼ | en:Start grabbing
    CButton m_ctrlStopGrabbingButton;           // ch:����ץͼ | en:Stop grabbing

    // ch:�豸��ʾ������ | en:Device display drop-down box
    CComboBox m_ctrlDeviceCombo;                // ch:ö�ٵ����豸 | en:Enumerated device
    int     m_nDeviceCombo;

// ch:�ڲ����� | en:Built-in function
private:
    // ch:�ʼʱ�Ĵ��ڳ�ʼ�� | en:Window initialization
    Status DisplayWindowInitial(void);          // ch:��ʾ���ʼ��,�ʼ�ĳ�ʼ�� | en:Display window initialization
    void ShowErrorMsg(CString csMessage, int nErrorNum);

    // ch:��ť������ʹ�� | en:Button bright dark enable
    Status EnableWindowWhenClose(void);         // ch:�ر�ʱ�İ�ť��ɫ���൱���ʼ��ʼ�� | en:Button color when Close, equivalent to the initialization
    Status EnableWindowWhenOpenNotStart(void);  // ch:���´��豸��ťʱ�İ�ť��ɫ | en:Button color when click Open 
    Status EnableWindowWhenStart(void);         // ch:���¿�ʼ�ɼ�ʱ�İ�ť��ɫ | en:Button color when click Start
    Status EnableWindowWhenStop(void);          // ch:���½����ɼ�ʱ�İ�ť��ɫ | en:Button color when click Stop
    
    // ch:��ʼ��������� | en:Initialization
    Status OpenDevice(void);                    // ch:����� | en:Open Device

    // ch:���á���ȡ�������� | en:Set and get parameters operation
    Status SetTriggerMode(void);                // ch:���ô���ģʽ | en:Set Trigger Mode
    Status GetTriggerMode(void);

    // ch:�ر����ٲ��� | en:Close and deatroy operation
    Status CloseDevice(void);                   // ch:�ر��豸 | en:Close Device
    Status DestroyHandle(void);                 // ch:�����豸 | en:Destroy device

    static void __stdcall ReconnectDevice(unsigned int nMsgType, void* pUser);

    //static unsigned int __stdcall ReconnectThread(void* pUser);

    //void ReconnectProcess();

private:
    BOOL  m_bRetStatus;                         // ch:��ʾ��������״̬ | en:Indicate function return status
    BOOL  m_bCreateDevice;                      // ch:�Ƿ񴴽��豸 | en:Whether to create device
    BOOL  m_bOpenDevice;                        // ch:�Ƿ���豸 | en:Whether to open device
    BOOL  m_bStartGrabbing;                     // ch:�Ƿ�ʼץͼ | en:Whether to start grabbing
    int   m_nTriggerMode;                       // ch:����ģʽ | en:Trigger Mode

    CMyCamera*      m_pcMyCamera;               // ch:CMyCamera��װ�˳��ýӿ� | en:CMyCamera packed commonly used interface
    HWND  m_hwndDisplay;                        // ch:��ʾ��� | en:Display Handle
    MV_CC_DEVICE_INFO_LIST m_stDevList;
    MV_CC_DEVICE_INFO m_stDevInfo;

    unsigned char*  m_pBufForSaveImage;         // ch:���ڱ���ͼ��Ļ��� | en:Buffer to save image
    unsigned int    m_nBufSizeForSaveImage;

    unsigned char*  m_pBufForDriver;            // ch:���ڴ�������ȡͼ��Ļ��� | en:Buffer to get image from driver
    unsigned int    m_nBufSizeForDriver;

public:
    afx_msg void OnBnClickedEnumButton();               // ch:�����豸 | en:Find Devices
    afx_msg void OnBnClickedOpenButton();               // ch:���豸 | en:Open Devices
    afx_msg void OnBnClickedCloseButton();              // ch:�ر��豸 | en:Close Devices
   
    // ch:ͼ��ɼ� | en:Image Acquisition
    afx_msg void OnBnClickedContinusModeRadio();        // ch:����ģʽ | en:Continus Mode
    afx_msg void OnBnClickedTriggerModeRadio();         // ch:����ģʽ | en:Trigger Mode
    afx_msg void OnBnClickedStartGrabbingButton();      // ch:��ʼ�ɼ� | en:Start Grabbing
    afx_msg void OnBnClickedStopGrabbingButton();       // ch:�����ɼ� | en:Stop Grabbing
    virtual BOOL PreTranslateMessage(MSG* pMsg);

public:    
    afx_msg void OnClose();                             // ch:���Ͻ��˳� | en:Exit from upper right corner

};
