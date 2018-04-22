#include "Table/TableViewer.h"

TableViewer::TableViewer(pTableModel model): ComponentViewer(pComponentModel(model))
{

}

TableViewer::~TableViewer()
{
    //dtor
}

void TableViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);



	ComponentViewer::RenderEnd(target);
}

pTableModel TableViewer::Owner()
{
    return pTableModel(ComponentViewer::Owner());
}

void TableViewer::SetOwner(pTableModel owner)
{
    ComponentViewer::SetOwner(owner);
}
