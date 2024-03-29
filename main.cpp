#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MyList.h"
#include "MyArrayList.h"
#include "Address.h"
#include "test.cpp"
using namespace std;
int main() {
    srand(time(NULL));
    int help, help2;
    cout<< "Тип данних" << endl<< "1 - int"<<endl<<"2 - double"<<endl<<"3 - string"<<endl<< "4 - Address"<< endl<< "5 - Тест принадлежності адреси до мережі"<<endl<< "6 - выход"<<endl;
    while(help!=6){
        cin>>help;
        switch (help) {
            case 1: {
                system("clear");
                MyList<int> *myList;
                myList = new MyArrayList<int>();
                myList->fill(15, [] { return 10 + rand() % 90; });
                cout << myList->toString() << endl;
                cout << "Какая сортировка?" << endl<<"1 - Quicksort"<< endl<<"2 - Mergesort"<<endl<<"3 - Insertsort"<<endl;
                cin >> help2;
                switch (help2) {
                    case 3: {
                        myList->insertionSort();
                        cout << "sorted with insert sort:" << endl;
                        cout << myList->toString() << endl;
                        cout << endl;
                        break;
                    }
                    case 1: {
                        myList->quickSort();
                        cout << "sorted with quick sort:" << endl;
                        cout << myList->toString() << endl;
                        cout << endl;
                        break;
                    }
                    case 2: {
                        myList->mergeSort();
                        cout << "sorted with merge sort:" << endl;
                        cout << myList->toString() << endl;
                        cout << endl;
                        break;
                        default:
                            break;
                    }
                }
                delete(myList);
                break;
            }
            case 2: {
                MyList<double> *myDoubleList;
                myDoubleList = new MyArrayList<double>();
                myDoubleList->fill(10, [] { return (2 + rand() % 10) * 5.1; });
                cout << myDoubleList->toString() << endl;
                cout << "Какая сортировка?" << endl<<"1 - Quicksort"<< endl<<"2 - Mergesort"<<endl<<"3 - Insertsort"<<endl;
                cin >> help2;
                switch (help2) {
                    case 2: {
                        myDoubleList->mergeSort();
                        cout << "Відсортовано merge sort" << endl;
                        cout << myDoubleList->toString() << endl;
                        break;
                    }
                    case 1: {
                        myDoubleList->quickSort();
                        cout << "Відсортовано quicksort" << endl;
                        cout << myDoubleList->toString() << endl;
                        break;
                    }
                    case 3: {
                        myDoubleList->insertionSort();

                        cout << "Відсортовано insert sort" << endl;
                        cout << myDoubleList->toString() << endl;

                        break;
                    }
                    default: {
                        break;
                    }
                }
                delete(myDoubleList);
                break;

            }
            case 3:{
                MyList<string> *myStringList;
                myStringList = new MyArrayList<string>();

                myStringList->add("Aezakmi");
                myStringList->add("qwert1");
                myStringList->add("xyz");
                myStringList->add("rtyuiodfghjk");
                myStringList->add("tgbyh");

                myStringList->setComparator([](string a, string b) {
                    return (int) (a.length() - b.length());
                });

                cout << myStringList->toString() << endl;
                cout << "Какая сортировка?" << endl<<"1 - Quicksort"<< endl<<"2 - Mergesort"<<endl<<"3 - Insertsort"<<endl;
                cin >> help2;
                switch (help2) {
                    case 1: {
                        myStringList->quickSort();

                        cout << "Відсортовано quicksort" << endl;
                        cout << myStringList->toString() << endl;

                        cout << endl;
                        break;
                    }
                    case 2: {
                        myStringList->mergeSort();

                        cout << "Відсортовано merge sort" << endl;
                        cout << myStringList->toString() << endl;

                        cout << endl;
                        break;
                    }
                    case 3: {
                        myStringList->insertionSort();

                        cout << "Відсортовано insert sort" << endl;
                        cout << myStringList->toString() << endl;

                        cout << endl;
                        break;
                    }
                    default: {
                        break;
                    }
                }
                delete(myStringList);
            }
            case 4: {
                int s;
                MyList<Address> *MyAddressList;
                MyAddressList = new MyArrayList<Address>();
                MyAddressList->add(Address("192.168.111.1"));
                MyAddressList->add(Address("192.168.121.1"));
                MyAddressList->add(Address("192.168.111.2"));
                s = MyAddressList->getSize();
                for (int i = 0; i < s; ++i) {
                    cout << Address(MyAddressList->get(i)).toString() << " ";
                }
                cout << "Какая сортировка?" << endl<<"1 - Quicksort"<< endl<<"2 - Mergesort"<<endl<<"3 - Insertsort"<<endl;
                cin >> help2;
                switch (help2) {
                    case 1: {
                            MyAddressList->quickSort();

                            cout << "Відсортовано quicksort" << endl;
                            s = MyAddressList->getSize();
                            for (int i = 0; i < s; ++i) {
                                cout << Address(MyAddressList->get(i)).toString() << " ";
                            }

                            cout << endl;
                            break;
                        }
                    case 2: {
                        MyAddressList->mergeSort();
                        cout << "Відсортовано merge sort" << endl;
                        s = MyAddressList->getSize();
                        for (int i = 0; i < s; ++i) {
                            cout << Address(MyAddressList->get(i)).toString() << " ";
                        }
                        cout << endl;
                        break;
                        }
                        case 3: {
                       MyAddressList->insertionSort();
                       cout << "Відсортовано insert sort" << endl;
                       s = MyAddressList->getSize();
                       for (int i = 0; i < s; ++i) {
                            cout << Address(MyAddressList->get(i)).toString() << " ";
                       }
                       cout << endl;
                       break;
                       }
                       default:
                           break;
                }
                delete(MyAddressList);
            break;
            }
            case 5: {
                testaddress();
                break;
                }
            default:
                    break;
            }
        }
    }