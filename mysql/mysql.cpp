#include "mysql.h"

using namespace mysqlx;

Session getSession() try {

    const char *env_user = "bank_admin";
    const char *env_pswd = "Rewq123+-";

    Session sess("localhost", 33060, env_user, env_pswd);

    return sess;

    std::cout << "Session accepted." << '\n';

    // Schema sch = sess.getSchema("bank_of_kovalov");
    // Table transactions = sch.getTable("transactions", true);

    // RowResult row = transactions.select().execute();

    // std::cout << row.fetchOne().get(1);

} catch (const mysqlx::Error &err) {
    cout << "ERROR: " << err << endl;
    return 1;
} catch (std::exception &ex) {
    cout << "STD EXCEPTION: " << ex.what() << endl;
    return 1;
} catch (const char *ex) {
    cout << "EXCEPTION: " << ex << endl;
    return 1;
}
