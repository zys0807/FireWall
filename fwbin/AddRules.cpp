///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "AddRules.h"

///////////////////////////////////////////////////////////////////////////

AddRules::AddRules( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 5, 4, 0, 0 );
	
	m_staticText51 = new wxStaticText( this, wxID_ANY, _("规则名称"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	gSizer1->Add( m_staticText51, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	tcRuleName = new wxTextCtrl( this, ID_TC_RULENAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( tcRuleName, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, _("规则类型"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	gSizer1->Add( m_staticText10, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	rbIP = new wxRadioButton( this, ID_RD_IP, _("IP地址"), wxDefaultPosition, wxDefaultSize, 0 );
	rbIP->SetValue( true ); 
	bSizer21->Add( rbIP, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	rbDomain = new wxRadioButton( this, ID_RD_DOMAIN, _("域名"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( rbDomain, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	gSizer1->Add( bSizer21, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	stRemoteIP = new wxStaticText( this, wxID_ANY, _("远程IP地址"), wxDefaultPosition, wxDefaultSize, 0 );
	stRemoteIP->Wrap( -1 );
	gSizer1->Add( stRemoteIP, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	tcRemoteIP = new wxTextCtrl( this, ID_TC_REMOTEIP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !tcRemoteIP->HasFlag( wxTE_MULTILINE ) )
	{
	tcRemoteIP->SetMaxLength( 15 );
	}
	#else
	tcRemoteIP->SetMaxLength( 15 );
	#endif
	gSizer1->Add( tcRemoteIP, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	stRemotePort = new wxStaticText( this, wxID_ANY, _("远程端口"), wxDefaultPosition, wxDefaultSize, 0 );
	stRemotePort->Wrap( -1 );
	gSizer1->Add( stRemotePort, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	tcRemoteIPPort = new wxTextCtrl( this, ID_TC_REMOTEIPPORT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !tcRemoteIPPort->HasFlag( wxTE_MULTILINE ) )
	{
	tcRemoteIPPort->SetMaxLength( 5 );
	}
	#else
	tcRemoteIPPort->SetMaxLength( 5 );
	#endif
	gSizer1->Add( tcRemoteIPPort, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText81 = new wxStaticText( this, wxID_ANY, _("远程域名"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	gSizer1->Add( m_staticText81, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	tcRemoteDomain = new wxTextCtrl( this, ID_TC_REMOTEDOMAIN, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tcRemoteDomain->Enable( false );
	
	gSizer1->Add( tcRemoteDomain, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText91 = new wxStaticText( this, wxID_ANY, _("远程域名端口"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	gSizer1->Add( m_staticText91, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	tcRemoteDomainPort = new wxTextCtrl( this, ID_TC_REMOTEDOMAINPORT, _("80"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !tcRemoteDomainPort->HasFlag( wxTE_MULTILINE ) )
	{
	tcRemoteDomainPort->SetMaxLength( 5 );
	}
	#else
	tcRemoteDomainPort->SetMaxLength( 5 );
	#endif
	tcRemoteDomainPort->Enable( false );
	
	tcRemoteDomainPort->SetValidator( wxTextValidator( wxFILTER_NUMERIC, &iLocalPort ) );
	
	gSizer1->Add( tcRemoteDomainPort, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("本地程序"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	gSizer1->Add( m_staticText4, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	fpProcessName = new wxFilePickerCtrl( this, ID_FP_FILEPATH, wxEmptyString, _("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_SMALL );
	gSizer1->Add( fpProcessName, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, _("本地端口"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gSizer1->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	tcLocalPort = new wxTextCtrl( this, IP_TC_LOCALPORT, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( tcLocalPort, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, _("方向"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	gSizer1->Add( m_staticText9, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString ciDirectionChoices[] = { _("出站"), _("进站"), _("双向") };
	int ciDirectionNChoices = sizeof( ciDirectionChoices ) / sizeof( wxString );
	ciDirection = new wxChoice( this, ID_CC_DIR, wxDefaultPosition, wxDefaultSize, ciDirectionNChoices, ciDirectionChoices, 0 );
	ciDirection->SetSelection( 0 );
	gSizer1->Add( ciDirection, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, _("状态"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	gSizer1->Add( m_staticText8, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString ciRuleStatusChoices[] = { _("允许"), _("拒绝"), _("忽略") };
	int ciRuleStatusNChoices = sizeof( ciRuleStatusChoices ) / sizeof( wxString );
	ciRuleStatus = new wxChoice( this, ID_CC_RULESTATUS, wxDefaultPosition, wxDefaultSize, ciRuleStatusNChoices, ciRuleStatusChoices, 0 );
	ciRuleStatus->SetSelection( 0 );
	gSizer1->Add( ciRuleStatus, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer2->Add( gSizer1, 4, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 1, 6, 0, 0 );
	
	
	gSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	btNewRule = new wxButton( this, ID_BT_NEWRULE, _("新建规则"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( btNewRule, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	btSaveRule = new wxButton( this, ID_BT_SAVERULE, _("保存"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( btSaveRule, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	btExplain = new wxButton( this, ID_BT_EXPLAIN, _("说明"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( btExplain, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	btClose = new wxButton( this, ID_BT_CLOSE, _("关闭"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( btClose, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	gSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizer3->Add( gSizer3, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );
	
	this->Centre( wxBOTH );
}

AddRules::~AddRules()
{
}
