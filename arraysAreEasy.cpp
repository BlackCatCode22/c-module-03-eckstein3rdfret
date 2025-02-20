#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    string User_response;

    cout << "Are you ready for your 3x3 cube to be generated?\n";
    cin >> User_response;
    cout << "Here we go anyways!\n";

    int data_values = 0;
    int my_3x3cube [3][3][3];

    time_t current_time = time(nullptr);
    srand((unsigned) current_time);

    for (int x = 0; x < 3; x++) {
        cout << "Layer " << x+1 << " of cube\n";
        for (int y = 0; y < 3; y++) {
            cout << "Row " << y+1 << " of cube\n";
            cout << "data points created!\n";
            for (int z= 0; z <3; z++) {
                int random_number = rand() % 10;
                my_3x3cube[x][y][z] = random_number;
                data_values++;
                cout << my_3x3cube[x][y][z] << " ";
            }
            cout << "\n";
        }
    }
    cout << "Cube Finished!\n";
    cout << "This is how many data values are created:" << data_values << "\n";

    cout << "Here is the layout of your cube by layers!\n";

    for (int x = 0; x < 3; x++) {
        cout << "Layer " << x+1 << " of cube\n";
        for (int y = 0; y < 3; y++) {
            for (int z= 0; z <3; z++) {
                cout << my_3x3cube[x][y][z] << " ";
            }
            cout << "\n";
        }
    }


    return 0;
}