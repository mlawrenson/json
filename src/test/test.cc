#include <iostream>
#include "json/json.hh"

using namespace std;
using namespace JSON;

int main(int argc, char** argv)
{
    // Load JSON file
    if (argc > 1)
    {
      cout << argv[1] << endl;
      Value v = parse_file(argv[1]);
      cout << v << endl;
      cout << "---" << endl;
    }

    // Build object programmatically
    Object obj;

    obj["foo"] = true;
    obj["bar"] = 3LL;
    obj["bar"] = 3L;
    obj["bar"] = 3;

    Object o;
    o["failure"] = true;
    o["success"] = "no way";

    obj["baz"] = o;

    Array a;
    a.push_back(true);
    a.push_back("asia");
    a.push_back("europa");
    a.push_back(55LL);
    a.push_back(3.12L);
    a.push_back(3.12);

    obj["beer"] = a;

    cout << "Pretty" << endl;
    cout << obj << endl;

    // Minify and test again
    minify();
    cout << "---" << endl;
    cout << "Minified" << endl;
    cout << obj << endl;

    // Pretty and test again
    pretty();
    cout << "---" << endl;
    cout << "Pretty" << endl;
    cout << obj << endl;

    return 0;
}
