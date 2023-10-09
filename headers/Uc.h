#include <string>
#include <vector>
using namespace std;

class Uc
{
public:
    Uc();
    Uc(const string &UcCode);
    string getUcCode();

private:
    string UcCode;
};
