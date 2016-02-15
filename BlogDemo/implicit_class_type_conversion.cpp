#include <iostream>
#include <string>
using namespace std;
 
class Sales_item {
    string isbn;
    int page;
public:
    // default argument for page is 200
    Sales_item(const string &book, const int p = 200) : isbn(book), page(p) { }
    Sales_item() { }
    // isbn is same as item or not
    bool same_isbn(const Sales_item &item) {
        return isbn == item.isbn;
    }
};
 
int main() {
    Sales_item item("9-999-99999-9");
    Sales_item other("1-111-11111-1");
    cout << item.same_isbn(other) << endl;
    // ok: compare item and other
    string null_book = "9-999-99999-9";
    cout << item.same_isbn(null_book) << endl;
    // ok: builds a Sales_item and isbn equal to null_book
    cout << item.same_isbn(string("9-999-99999-9")) << endl;
    // ok: "9-999-99999-9" is converted into string,
    //     builds a Sales_item and isbn equal to the string
    cout << item.same_isbn(Sales_item("9-999-99999-9", 600)) << endl;
    // ok: builds a Sales_item with 200 pages explicitly
    // cout << one.same_isbn("9-999-99999-9") << endl;
    // error: "9-999-99999-9" is a char string but could not convert into Sales_item automatically
    return 0;
}
