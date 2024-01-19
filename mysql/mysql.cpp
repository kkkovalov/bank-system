#include "mysql.h"

using namespace mysqlx;

Session mSQL::getSession() try {

    const char *env_user = "bank_admin";
    const char *env_pswd = "Rewq31+-";

    Session sess("localhost", 33060, env_user, env_pswd);

    return sess;

} catch (const mysqlx::Error &err) {
    throw std::runtime_error("MySQLX Error: " + std::string(err.what()));
} catch (const std::exception &ex) {
    throw std::runtime_error("STD Exception: " + std::string(ex.what()));
} catch (const char *ex) { throw std::runtime_error("Exception: " + std::string(ex)); };

bool mSQL::createAccount(uint64_t id, std::string name, std::tm date_of_birth) {

    Session currSess{getSession()};

    Schema bank = currSess.getSchema("bank_of_kovalov");
    Table accounts = bank.getTable("accounts", true);
    std::stringstream ss;
    ss << std::put_time(&date_of_birth, "%Y-%m-%d");
    std::string mysqlDateString = ss.str();

    Result row = accounts.insert().values(id, name, mysqlDateString).execute();

    return true;
};
