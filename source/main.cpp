/************************************************************************************//**
* \file         main.cpp
* \brief        Application source file.
*
****************************************************************************************/

/****************************************************************************************
* Include files
****************************************************************************************/
#include "main.h"
#include "mainwindow.h"
#include "observer.h"
#include <wx/wxprec.h>
#include <wx/grid.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

/****************************************************************************************
* Macro definitions
****************************************************************************************/
/* Macro which creates the application instance and starts it. */
//IMPLEMENT_APP(MyApp)


/************************************************************************************//**
** \brief     Called upon application initialization. 
** \return    True if the initialization was successful. False if anything failed, which
**            prevents the application from continuing.
**
****************************************************************************************/

class MyFrame : public wxFrame
{
public:
    MyFrame(Observer o);
    std::vector<Observer*> observers;
    wxGrid* grid = new wxGrid( this, wxID_ANY, wxPoint( 0, 0 ), wxSize( 420, 300 ) );
    wxGrid* grid2 = new wxGrid( this, wxID_ANY, wxPoint( 0, 350 ), wxSize( 400, 100 ) );
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnWrite(wxGridEvent& event);

    void attach(Observer* o){
        observers.push_back(o);
    }
    void notify(){
        for(int i = 0; i < observers.size(); i++){
            observers[i]->Update(*grid, *grid2);
        }
    }
};

enum
{
    ID_Hello = 1
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Observer* OBS = new Observer();
    MyFrame *frame = new MyFrame(*OBS);

    frame->Show(true);
    return true;
}

/*bool MyApp::OnInit()
{
  
  MainWindow *mainWindow = new MainWindow(wxT("Prova"), 640, 480);
  mainWindow->Show(true);

  return true;
} */

MyFrame::MyFrame(Observer o)
        : wxFrame(NULL, wxID_ANY, "SpreadSheet", wxDefaultPosition, wxSize(450,500))
{
    this->attach(&o);
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    
    grid->CreateGrid( 10, 4 );
    grid->SetGridLineColour(*wxBLACK);

    
    grid2->CreateGrid( 1, 5 );
    grid2->SetGridLineColour(*wxBLACK);
    grid2->SetRowLabelSize(0);
    for(int i = 0; i < 5; i++){
        grid2->SetReadOnly(0, i, true);
    }
    grid2->SetColLabelValue(0, "SUM");
    grid2->SetColLabelValue(1, "MEAN");
    grid2->SetColLabelValue(2, "MAX");
    grid2->SetColLabelValue(3, "MIN");
    grid2->SetColLabelValue(4, "PROD");

    CreateStatusBar();
    SetStatusText("This is a SpreadSheet!");
    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    grid->Bind(wxEVT_GRID_CELL_CHANGED, &MyFrame::OnWrite, this);

    //observers[0].Update(*grid, *grid2);
}



void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a SpreadSheet created by Giovanni Casini",
                 "About This Program", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Welcome on this SpreadSheet!");
}

void MyFrame::OnWrite(wxGridEvent& event)
{
    notify();
}

 /*** end of OnInit ***/
/*********************************** end of main.cpp ***********************************/
