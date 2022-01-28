/************************************************************************************//**
* \file         main.h
* \brief        Application header file.
*
****************************************************************************************/
#ifndef MAIN_H
#define MAIN_H

/****************************************************************************************
* Include files
****************************************************************************************/
#include "mainwindow.h"
#include "Grid.h"
#include <wx/wxprec.h>
#include <wx/grid.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

/****************************************************************************************
* Class definitions
****************************************************************************************/
/** \brief Application class. */
class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
};
    
class MyFrame : public wxFrame
{
public:
    MyFrame();
    wxGrid* grid = new wxGrid( this, wxID_ANY, wxPoint(0, 0), wxSize(485, 300));
    wxGrid* grid2 = new wxGrid( this, wxID_ANY, wxPoint(80, 325), wxSize(400, 60));
    Griglia* griglia;

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnWrite(wxGridEvent& event);
};

enum
{
    ID_Hello = 1
};

MyFrame::MyFrame()
        : wxFrame(NULL, wxID_ANY, "SpreadSheet", wxDefaultPosition, wxSize(550,500))
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    grid->CreateGrid(10, 5);
    grid->SetGridLineColour(*wxBLACK);

    grid2->CreateGrid(1, 5);
    grid2->SetGridLineColour(*wxBLACK);
    grid2->SetRowLabelSize(0);
    for(int i = 0; i < 4; i++)
        grid2->SetReadOnly(0, i, true);
    grid2->SetColLabelValue(0, "SUM");
    grid2->SetColLabelValue(1, "MAX");
    grid2->SetColLabelValue(2, "MIN");
    grid2->SetColLabelValue(3, "PROD");
    grid2->SetColLabelValue(4, "MEAN");
    grid2->SetLabelBackgroundColour(*wxGREEN);

    griglia = new Griglia(grid, grid2);
    Observer* obs = new Observer(griglia);
    

    CreateStatusBar();
    SetStatusText("This is a SpreadSheet!");
    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    grid->Bind(wxEVT_GRID_CELL_CHANGED, &MyFrame::OnWrite, this);
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
    griglia->setGridValue(event.GetRow(), event.GetCol(), wxAtof(grid->GetCellValue(event.GetRow(),event.GetCol())));
}

#endif /* MAIN_H */
/*********************************** end of main.h *************************************/

