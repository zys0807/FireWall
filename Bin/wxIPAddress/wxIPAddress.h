#ifndef WXIPADDRESS_H
#define WXIPADDRESS_H

#include "wx/wx.h"


class wxIPAddress : public wxControl
{
public:
    wxIPAddress(){Init();};
    virtual ~wxIPAddress();
    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
                long style = 0, const wxValidator valid = wxDefaultValidator, const wxString& name = wxControlNameStr) ;

    wxIPAddress(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
                long style = 0, const wxValidator valid = wxDefaultValidator, const wxString& name = wxControlNameStr) {Init(); Create(parent);};

    bool Init() ;
    wxSize DoGetBestSize() ;

protected:

private:
};

#endif // WXIPADDRESS_H
