#include <assert.h>
#include <iostream>
#include "BatteryManagementSystem.h"

using namespace std;

int main() {
    BatteryManagementSystem batterymanagementsystem;
    assert(batterymanagementsystem.BatteryisOK(25, 70, 0.7) == true);
    assert(batterymanagementsystem.BatteryisOK(50, 85, 0) == false);
    return 0;
}
