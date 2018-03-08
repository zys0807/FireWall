///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __RULESLIST_H__
#define __RULESLIST_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class RulesList
///////////////////////////////////////////////////////////////////////////////
class RulesList : public wxFrame 
{
	private:
	
	protected:
		enum
		{
			ID_BTN_START_STOP_SERVICE = 2000,
			ID_BTN_RULE_UP,
			ID_BTN_RULE_DOWN,
			ID_BTN_ADD_RULE,
			ID_BTN_MODIFT_RULES,
			ID_BTN_DEL_RULE,
			ID_BTN_SETTINGS,
			ID_BTN_EXIT,
			ID_FILE_OPEN,
			ID_FILE_SAVE,
			ID_FILE_EXIT,
			ID_EDIT_ADDRULE,
			ID_EDIT_DELRULE,
			ID_TOOLS_START_STOP_SERVICE,
			ID_TOOLS_SETTINGS,
			ID_HELP_HELP,
			ID_HELP_ABOUT
		};
		
		wxGrid* grRulesList;
		wxButton* btStartServer;
		wxButton* btRuleUp;
		wxButton* btRuleDown;
		wxButton* btAddRules;
		wxButton* btModifyRules;
		wxButton* btDeleteRules;
		wxButton* btSettings;
		wxButton* btExit;
		wxStatusBar* m_statusBar1;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu2;
		wxMenu* m_menu4;
		wxMenu* m_menu3;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnStartService( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRuleUp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRuleDown( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddRules( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnModifyRules( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteRules( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSystemSettings( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		RulesList( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("规则列表"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 740,522 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~RulesList();
	
};

#endif //__RULESLIST_H__
