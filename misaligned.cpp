#include <iostream>
#include <assert.h>

int ComputedColorCode(int majorColor, int minorColor)
{
    return (majorColor *5 + minorColor);
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << ComputedColorCode(i,j) << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert(ComputedColorCode(0,0) == 1)
    std::cout << "All is well (maybe!)\n";
    return 0;
}
