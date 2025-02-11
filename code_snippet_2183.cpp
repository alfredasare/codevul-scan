#include <odbc.h>

//...

int wkbConvCircularStringToShape(wkbObj *w, shapeObj *shape)
{
    //...

    /* Prepare a statement to execute */
    ODBCPrepare(stmt, "SELECT * FROM table WHERE geom =?");
    ODBCBindParameter(stmt, 1, SQL_C_CHAR, SQL_VARCHAR, SQL_NULLDATA, 0, 0, NULL, 0, NULL);
    ODBCExecute(stmt);

    //...
}