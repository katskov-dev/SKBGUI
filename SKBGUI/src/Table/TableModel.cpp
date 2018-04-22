#include "Table/TableModel.h"

TableModel::TableModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    __rowCount = 1;
    __colCount = 1;
    __colWidth.resize(1);
    __colWidth[0] = 100;
    __rowHeight.resize(1);
    __rowHeight[0] = 25;
    //SetColCount(3);
    //SetRowCount(2);
    CreateCells();
    Update();
    UpdateSize();
    __class = "Table";

}

TableModel::~TableModel()
{
    DestroyCells();
}

void TableModel::SetRowCount(int rowCount)
{
    DestroyCells();
    __rowCount = rowCount;
    __rowHeight.resize(rowCount);

    for (int i = 0; i < __rowCount; i++){
         __rowHeight[i] = 25;
    }

    CreateCells();
    UpdateSize();

}

void TableModel::SetColCount(int colCount)
{
    DestroyCells();
    __colCount = colCount;
    __colWidth.resize(colCount);
    for (int i = 0; i < __colCount; i++){
        __colWidth[i] =  100;
    }
    CreateCells();
    UpdateSize();
}

int TableModel::RowCount()
{
    return __rowCount;
}

int TableModel::ColCount()
{
    return __colCount;
}

int TableModel::RowHeight(int index)
{
    return __rowHeight[index];
}

int TableModel::ColWidth(int index)
{
    return __colWidth[index];
}

void TableModel::SetRowHeight(int row, int height)
{
    __rowHeight[row] = height;
    UpdateCellsSize();
    UpdateSize();
}

void TableModel::SetColWidth(int col, int width)
{
    __colWidth[col] = width;

    UpdateCellsSize();
    UpdateSize();
}

pEdit TableModel::Cell(int row, int col)
{
    return __cell[row][col];
}

void TableModel::DestroyCells()
{
    for (int row = 0; row < RowCount(); row++){
        for (int col = 0; col < ColCount(); col++){

           Delete(__cell[row][col]);

        }
    }
}

void TableModel::CreateCells()
{
    __cell.resize(RowCount());
    for (int i = 0; i < RowCount(); i++){
        __cell[i].resize(ColCount());
    }

    for (int row = 0; row < RowCount(); row++){
        for (int col = 0; col < ColCount(); col++){
            pEdit edit = new Edit();
            edit->Model()->SetSize(ColWidth(col), RowHeight(row));
            sf::Vector2f coord; coord.x = 0; coord.y = 0;
            for (int i = 0; i < col; i++)
                coord.x += ColWidth(i);
            for (int i = 0; i < row; i++)
                coord.y += RowHeight(i);
            edit->Model()->SetLocalCoord(coord);
            //edit->Model()->SetVisibleOutline(false);
            __cell[row][col] = edit;
            Add(edit);
        }
    }
}

void TableModel::Update()
{
    DestroyCells();
    CreateCells();
    UpdateSize();
}

void TableModel::UpdateSize()
{
    sf::Vector2f size = sf::Vector2f(0, 0);
    for (int i = 0; i <RowCount(); i++){
        size.y += RowHeight(i);
    }
    for (int i = 0; i <ColCount(); i++){
        size.x += ColWidth(i);
    }
    SetSize(size);

}

void TableModel::UpdateCellsSize()
{
    sf::Vector2f offset = sf::Vector2f(0,0);
    for (int row = 0; row < RowCount(); row++){
        offset.x = 0;
        for (int col = 0; col < ColCount(); col++){
            __cell[row][col]->Model()->SetLocalCoord(offset);
            __cell[row][col]->Model()->SetSize(ColWidth(col), RowHeight(row));
            offset.x += ColWidth(col);
        }
        offset.y += RowHeight(row);

    }
}
