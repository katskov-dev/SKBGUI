#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Table/TableModel.h>
#include <SFML/Graphics.hpp>

class TableController: public ComponentController
{
    public:
        TableController(pTableModel model);
        virtual ~TableController();
        virtual bool Handle(sf::Event event);
		virtual pTableModel Owner();
        virtual void SetOwner(pTableModel owner);

    protected:

    private:
};
