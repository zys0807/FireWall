///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __ADDRULES_H__
#define __ADDRULES_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/valtext.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/filepicker.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class AddRules
///////////////////////////////////////////////////////////////////////////////
class AddRules : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			ID_TC_RULENAME = 1000,
			ID_RD_IP,
			ID_RD_DOMAIN,
			ID_TC_REMOTEIP,
			ID_TC_REMOTEIPPORT,
			ID_TC_REMOTEDOMAIN,
			ID_TC_REMOTEDOMAINPORT,
			ID_FP_FILEPATH,
			IP_TC_LOCALPORT,
			ID_CC_DIR,
			ID_CC_RULESTATUS,
			ID_BT_NEWRULE,
			ID_BT_SAVERULE,
			ID_BT_EXPLAIN,
			ID_BT_CLOSE
		};
		
		wxStaticText* m_staticText51;
		wxTextCtrl* tcRuleName;
		wxStaticText* m_staticText10;
		wxRadioButton* rbIP;
		wxRadioButton* rbDomain;
		wxStaticText* stRemoteIP;
		wxTextCtrl* tcRemoteIP;
		wxStaticText* stRemotePort;
		wxTextCtrl* tcRemoteIPPort;
		wxStaticText* m_staticText81;
		wxTextCtrl* tcRemoteDomain;
		wxStaticText* m_staticText91;
		wxTextCtrl* tcRemoteDomainPort;
		wxStaticText* m_staticText4;
		wxFilePickerCtrl* fpProcessName;
		wxStaticText* m_staticText5;
		wxTextCtrl* tcLocalPort;
		wxStaticText* m_staticText9;
		wxChoice* ciDirection;
		wxStaticText* m_staticText8;
		wxChoice* ciRuleStatus;
		wxButton* btNewRule;
		wxButton* btSaveRule;
		wxButton* btExplain;
		wxButton* btClose;
	
	public:
		int iLocalPort; 
		
		AddRules( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("规则增加及修改"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AddRules();
	
};

#endif //__ADDRULES_H__
