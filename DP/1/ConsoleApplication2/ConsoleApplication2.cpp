#include <iostream>
#include <cassert>
#include "SqlSelectQueryBuilder.h"
using namespace std;

int main()
{
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere({ {"id", "42"}, {"name", "John"} });

    assert(query_builder.BuildQuery() == "SELECT name, phone FROM students WHERE id=42 AND name=John;");    //Проверяем

    cout << query_builder.BuildQuery() << endl;       //Вывод на экран

}
