#include <iostream>

using namespace std;

#include "main.h"

void main()
{
    float xComponents[2] = { 0.0f, 0.0f };
    float yComponents[2] = { 0.0f, 0.0f };

    for(int i = 0; i < 2; i++)
    {
        cout << "Please enter the X component of vector " << (i + 1) << ": ";
        cin >> xComponents[i];

        cout << "Please enter the Y component of vector " << (i + 1) << ": ";
        cin >> yComponents[i];

        cout << std::endl;
    }

    Vector2 v_a = Vector2(xComponents[0], yComponents[0]);
    Vector2 v_b = Vector2(xComponents[1], yComponents[1]);

    cout << "The distance between " << v_a << " and " << v_b << " is " << GetDistanceBetweenPoints(v_a, v_b) << endl;
    
}