///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "RulesList.h"

///////////////////////////////////////////////////////////////////////////

RulesList::RulesList( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	grRulesList = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grRulesList->CreateGrid( 5, 7 );
	grRulesList->EnableEditing( true );
	grRulesList->EnableGridLines( true );
	grRulesList->EnableDragGridSize( false );
	grRulesList->SetMargins( 0, 0 );
	
	// Columns
	grRulesList->EnableDragColMove( false );
	grRulesList->EnableDragColSize( true );
	grRulesList->SetColLabelSize( 30 );
	grRulesList->SetColLabelValue( 0, _("规则名称") );
	grRulesList->SetColLabelValue( 1, _("本地进程") );
	grRulesList->SetColLabelValue( 2, _("进程端口") );
	grRulesList->SetColLabelValue( 3, _("远程IP") );
	grRulesList->SetColLabelValue( 4, _("远程端口") );
	grRulesList->SetColLabelValue( 5, _("方向") );
	grRulesList->SetColLabelValue( 6, _("状态") );
	grRulesList->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grRulesList->EnableDragRowSize( true );
	grRulesList->SetRowLabelSize( 80 );
	grRulesList->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grRulesList->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer1->Add( grRulesList, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	btStartServer = new wxButton( this, ID_BTN_START_STOP_SERVICE, _("启动服务"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( btStartServer, 0, wxALL|wxEXPAND, 5 );
	
	btRuleUp = new wxButton( this, ID_BTN_RULE_UP, _("规则上移"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( btRuleUp, 0, wxALL|wxEXPAND, 5 );
	
	btRuleDown = new wxButton( this, ID_BTN_RULE_DOWN, _("规则下移"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( btRuleDown, 0, wxALL|wxEXPAND, 5 );
	
	btAddRules = new wxButton( this, ID_BTN_ADD_RULE, _("增加规则..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( btAddRules, 0, wxALL|wxEXPAND, 5 );
	
	btModifyRules = new wxButton( this, ID_BTN_MODIFT_RULES, _("修改规则..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( btModifyRules, 0, wxALL|wxEXPAND, 5 );
	
	btDeleteRules = new wxButton( this, ID_BTN_DEL_RULE, _("删除规则"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( btDeleteRules, 0, wxALL|wxEXPAND, 5 );
	
	btSettings = new wxButton( this, ID_BTN_SETTINGS, _("设置..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( btSettings, 0, wxALL|wxEXPAND, 5 );
	
	btExit = new wxButton( this, ID_BTN_EXIT, _("退出"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( btExit, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* miFile_Open;
	miFile_Open = new wxMenuItem( m_menu1, ID_FILE_OPEN, wxString( _("打开规则文件(&O)...") ) + wxT('\t') + wxT("Ctrl+O"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( miFile_Open );
	
	wxMenuItem* miFile_Save;
	miFile_Save = new wxMenuItem( m_menu1, ID_FILE_SAVE, wxString( _("保存规则文件(&S)...") ) + wxT('\t') + wxT("Ctrl+S"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( miFile_Save );
	
	m_menu1->AppendSeparator();
	
	wxMenuItem* miFile_Exit;
	miFile_Exit = new wxMenuItem( m_menu1, ID_FILE_EXIT, wxString( _("退出(&E)") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( miFile_Exit );
	
	m_menubar1->Append( m_menu1, _("文件(&F)") ); 
	
	m_menu2 = new wxMenu();
	wxMenuItem* miEdit_AddRule;
	miEdit_AddRule = new wxMenuItem( m_menu2, ID_EDIT_ADDRULE, wxString( _("增加规则...") ) + wxT('\t') + wxT("Ctrl+A"), wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( miEdit_AddRule );
	
	wxMenuItem* miEdit_DelRule;
	miEdit_DelRule = new wxMenuItem( m_menu2, ID_EDIT_DELRULE, wxString( _("删除规则...") ) + wxT('\t') + wxT("Ctrl+D"), wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( miEdit_DelRule );
	
	m_menubar1->Append( m_menu2, _("编辑(&E)") ); 
	
	m_menu4 = new wxMenu();
	wxMenuItem* miTool_Start_Service;
	miTool_Start_Service = new wxMenuItem( m_menu4, ID_TOOLS_START_STOP_SERVICE, wxString( _("启动服务") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( miTool_Start_Service );
	
	wxMenuItem* miTool_StopService;
	miTool_StopService = new wxMenuItem( m_menu4, ID_TOOLS_START_STOP_SERVICE, wxString( _("停止服务") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( miTool_StopService );
	
	m_menu4->AppendSeparator();
	
	wxMenuItem* miTool_Settings;
	miTool_Settings = new wxMenuItem( m_menu4, ID_TOOLS_SETTINGS, wxString( _("设置...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( miTool_Settings );
	
	m_menubar1->Append( m_menu4, _("工具(&T)") ); 
	
	m_menu3 = new wxMenu();
	wxMenuItem* miHelp_Help;
	miHelp_Help = new wxMenuItem( m_menu3, ID_HELP_HELP, wxString( _("帮助...") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( miHelp_Help );
	
	wxMenuItem* miHelp_About;
	miHelp_About = new wxMenuItem( m_menu3, ID_HELP_ABOUT, wxString( _("关于...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( miHelp_About );
	
	m_menubar1->Append( m_menu3, _("帮助(&H)") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btStartServer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnStartService ), NULL, this );
	btRuleUp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnRuleUp ), NULL, this );
	btRuleDown->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnRuleDown ), NULL, this );
	btAddRules->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnAddRules ), NULL, this );
	btModifyRules->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnModifyRules ), NULL, this );
	btDeleteRules->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnDeleteRules ), NULL, this );
	btSettings->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnSystemSettings ), NULL, this );
	btExit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnExit ), NULL, this );
}

RulesList::~RulesList()
{
	// Disconnect Events
	btStartServer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnStartService ), NULL, this );
	btRuleUp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnRuleUp ), NULL, this );
	btRuleDown->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnRuleDown ), NULL, this );
	btAddRules->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnAddRules ), NULL, this );
	btModifyRules->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnModifyRules ), NULL, this );
	btDeleteRules->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnDeleteRules ), NULL, this );
	btSettings->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnSystemSettings ), NULL, this );
	btExit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RulesList::OnExit ), NULL, this );
	
}
