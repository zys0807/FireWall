#ifndef APP_H
#define APP_H

#include "wx/wx.h"
#include "Rules.h"


class App : public wxApp
{
    public:
        /** Default constructor */
        App();
        /** Default destructor */
        virtual ~App();
bool OnInit() ;
    protected:

    private:
};

#endif // APP_H
