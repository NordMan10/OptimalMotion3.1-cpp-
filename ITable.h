#pragma once
class ITable
{
    void AddRow(TableRow &tableData);

    void RemoveRow(int id);

    void UpdateRow(int id, TableRow &newRow);

    void Reset();
};

