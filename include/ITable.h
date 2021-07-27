#pragma once
class ITable
{
public:

    virtual void AddRow(TableRow& tableData) = 0;

    virtual void RemoveRow(int id) = 0;

    virtual void UpdateRow(int id, TableRow& newRow) = 0;

    virtual void Reset() = 0'
};

