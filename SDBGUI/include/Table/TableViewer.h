#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Table/TableModel.h>
#include <SFML/Graphics.hpp>

class TableViewer: public ComponentViewer
{
    public:
        TableViewer(pTableModel model);
        virtual ~TableViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pTableModel Owner();
        virtual void SetOwner(pTableModel owner);
    protected:

    private:


};
