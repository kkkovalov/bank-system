#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
  private:
    std::string m_id{""};

  protected:
    std::string m_name{""};
    std::string m_timestamp{""};

  public:
    User(std::string name) : m_name{name} {};
};

#endif
