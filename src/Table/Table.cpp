#include <Table/Table.h>


Table::Table()
{
    SetModel(new TableModel());
    SetViewer(new TableViewer(Model()));
    SetController(new TableController(Model()));
}

Table::~Table()
{

}

pTableModel Table::Model()
{
    return pTableModel(__model);
}

void Table::SetModel(pTableModel model)
{
    __model = model;
}

pTableViewer Table::Viewer()
{
    return pTableViewer(__viewer);
}

void Table::SetViewer(pTableViewer viewer)
{
    __viewer = viewer;
}

pTableController Table::Controller()
{
    return pTableController(__controller);
}

void Table::SetController(pTableController controller)
{
    __controller = controller;
}

