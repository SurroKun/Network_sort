#include "Network.h"
void testaddress()
{
    string A, B;
    cout << "Введіть Мережу\n"; cin>>A ;
    cout << "Введіть Адресу\n"; cin>>B;

    cout<< A << " & " << B << " = " << Network(A).test(Address(B));
    cout<<endl<<endl;
    cout << "192.168.5.1   in 192.168.5.85/24 = ";
    cout << Network("192.168.5.85/24").test(Address("192.168.5.1"  ));
    cout << endl;
    cout << "191.168.5.254 in 192.168.5.85/24 = ";
    cout << Network("192.168.5.85/24").test(Address("191.168.5.254"));
    cout << endl;
    cout << "192.168.5.254 in 192.168.5.85/24 = ";
    cout << Network("192.168.5.85/24").test(Address("192.168.5.254"));
    cout << endl;
    cout << "192.168.4.254 in 192.168.5.85/24 = ";
    cout << Network("192.168.5.85/24").test(Address("192.168.4.254"));
    cout << endl;

    cout << "2001:0db8:abcd:0012:0000:0000:0000:0000 in 2001:db8:abcd:12:0:0:0:0/64 = ";
    cout << Network("2001:db8:abcd:12:0:0:0:0/64").test(Address("2001:0db8:abcd:0012:0000:0000:0000:0000"));
    cout << endl;
    cout << "2001:0db8:abcd:0012:ffff:ffff:ffff:ffff in 2001:db8:abcd:12:0:0:0:0/64 = ";
    cout << Network("2001:db8:abcd:12:0:0:0:0/64").test(Address("2001:0db8:abcd:0012:ffff:ffff:ffff:ffff"));
    cout << endl;
    cout << "2001:0db8:abcd:0011:ffff:ffff:ffff:ffff in 2001:db8:abcd:12:0:0:0:0/64 = ";
    cout << Network("2001:db8:abcd:12:0:0:0:0/64").test(Address("2001:0db8:abcd:0011:ffff:ffff:ffff:ffff"));
    cout << endl;
    cout << "2001:0db8:abcd:0013:0000:0000:0000:0000 in 2001:db8:abcd:12:0:0:0:0/64 = ";
    cout << Network("2001:db8:abcd:12:0:0:0:0/64").test(Address("2001:0db8:abcd:0013:0000:0000:0000:0000"));
    cout << endl;

}

