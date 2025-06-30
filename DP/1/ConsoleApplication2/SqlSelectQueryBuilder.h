#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

class SqlSelectQueryBuilder {
public:
  
    SqlSelectQueryBuilder& AddColumn(const string& column)           // ���������� �������
    {
        columns_.push_back(column);
        return *this;
    }
       
    SqlSelectQueryBuilder& AddColumns(const vector<string>& columns) noexcept  // ��������� �������
    {
        for (const auto& col : columns) 
        {
            columns_.push_back(col);
        }
        return *this;
    }
   
    SqlSelectQueryBuilder& AddFrom(const string& table_name)        // ��������� ������� 
    {
        table_ = table_name;
        return *this;
    }
   
    SqlSelectQueryBuilder& AddWhere(const string& column, const string& value)     // ���������� ������� WHERE
    {
        where_conditions_.push_back({ column, value });
        return *this;
    }

  
    SqlSelectQueryBuilder& AddWhere(const map<std::string, std::string>& kv) noexcept   // ��������� ������� WHERE 
    {
        for (const auto& pair : kv) {
            where_conditions_.push_back({ pair.first, pair.second });
        }
        return *this;
    }
   
    string BuildQuery() const                    // ������
    {
        ostringstream query;       
        query << "SELECT ";                          // ������ ������

        if (columns_.empty()) 
        {
            query << "*";
        }
        else {
            for (size_t i = 0; i < columns_.size(); ++i) 
            {
                query << columns_[i];
                if (i != columns_.size() - 1) 
                {
                    query << ", ";
                }
            }
        }
              
        query << " FROM " << table_;            // From
               
        if (!where_conditions_.empty())         //Where
        {
            query << " WHERE ";
            for (size_t i = 0; i < where_conditions_.size(); ++i) 
            {
                const auto& cond = where_conditions_[i];
                query << cond.first << "=" << cond.second;
                if (i != where_conditions_.size() - 1)
                {
                    query << " AND ";
                }
            }
        }
       
        query << ";";                   //����� ������
        return query.str();
    }

private:
    vector<string> columns_;
    string table_ = "default_table";       // �� ���������
    vector<pair<string, string>> where_conditions_;
};
