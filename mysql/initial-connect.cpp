#include "mysql.h"

using ::std::cout;
using ::std::endl;
using namespace mysqlx;

int main(int argc, const char *argv[]) try {

    const char* env_user;
    const char* env_pswd;
    if (argc > 2) {
        env_user = argv[1];
        env_pswd = argv[2];
    } else {
        env_user = "root";
        env_pswd = NULL;
    }

    // cout << env_user << '\n' << env_pswd;

    // const char *url = "mysqlx://" + env_user + ":" + env_pswd + "@localhost:33060";

    // cout << "Creating session on " << url << " ..." << endl;

    Session sess("localhost", 33060, env_user, env_pswd);

    cout << "Session accepted, creating collection..." << endl;

    Schema sch = sess.getSchema("bank_of_kovalov");
    Table transactions = sch.getTable("transactions", true);

    RowResult row = transactions.select().execute();

    std::cout << row.fetchOne().get(1);

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
