#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Edit/Edit.h>
#include <vector>


class TableModel: public ComponentModel
{
    public:
        TableModel();
        virtual ~TableModel();
        void SetRowCount(int rowCount);
        void SetColCount(int colCount);
        int RowCount();
        int ColCount();
        int RowHeight(int index);
        int ColWidth(int index);
        void SetRowHeight(int row, int height);
        void SetColWidth(int col, int width);
        pEdit Cell(int row, int col);
        void Update();


    protected:

    private:
        int __rowCount;
        int __colCount;
        std::vector<int> __rowHeight;
        std::vector<int> __colWidth;
        std::vector < std::vector < pEdit >> __cell;
        void DestroyCells();
        void CreateCells();
        void UpdateSize();
        void UpdateCellsSize();


};
