#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Table/TableModel.h>
#include <Table/TableViewer.h>
#include <Table/TableController.h>

class Table: public Component
{
    public:
        Table();
        ~Table();
        virtual pTableModel Model();
        virtual void SetModel(pTableModel model);
        virtual pTableViewer Viewer();
        virtual void SetViewer(pTableViewer viewer);
        virtual pTableController Controller();
        virtual void SetController(pTableController controller);
    private:

};
