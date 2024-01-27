#include "mysql.h"

using namespace mysqlx;

Table mSQL::getAccountsTable() try {

    const char *env_user = "bank_admin";
    const char *env_pswd = "Rewq31+-";

    Session sess("localhost", 33060, env_user, env_pswd);

    Schema bank = sess.getSchema("bank_of_kovalov");

    return bank.getTable("accounts", true);

} catch (const mysqlx::Error &err) {
    throw std::runtime_error("MySQLX Error: " + std::string(err.what()));
} catch (const std::exception &ex) {
    throw std::runtime_error("STD Exception: " + std::string(ex.what()));
} catch (const char *ex) { throw std::runtime_error("Exception: " + std::string(ex)); };

void mSQL::createAccount(uint64_t id, std::string name, std::tm date_of_birth) {

    Table accounts{mSQL::getAccountsTable()};
    std::stringstream ss;
    ss << std::put_time(&date_of_birth, "%Y-%m-%d");
    std::string mysqlDateString = ss.str();

    Result row = accounts.insert().values(id, name, mysqlDateString).execute();

    std::cout << "Success! Welcome to the Bank of Kovalov, " + name + "\n";
};

Column mSQL::depositFunds(uint64_t id, double deposit_amount) {
    Table accounts{mSQL::getAccountsTable()};
    std::string where_id = "id=" + id;
    RowResult row = accounts.select().where(where_id).execute();
    Column current_funds = row.getColumn(4);
    // current_funds += deposit_amount;
    // accounts.update().set("funds", current_funds).where(where_id).execute();
    return current_funds;
};

double mSQL::withdrawFunds(uint64_t id, double withdraw_amount){

};
