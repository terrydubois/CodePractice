// following this tutorial: https://www.youtube.com/watch?v=0E0UBphVRhY

#include <iostream>
#include <cstring>
#include <cmath>
#include <chrono>
#include <thread>
#include <cstdio>

using namespace std;

float A, B, C;
const float cubeWidth = 75;
const int width = 80, height = 44;
float zBuffer[width * height];
char buffer[width * height];
int bgASCIICode = ' ';
int distFromCam = 150;
float K1 = 40;
float x, y, z;
float sinA, sinB, sinC, cosA, cosB, cosC;
float oneOverZ;
int xp, yp;
int idx;
int frame = 0;

float calcX(int i, int j, int k) {
    return j * sinA * sinB * cosC
        - k * cosA * sinB * cosC
        + j * cosA * sinC
        + k * sinA * sinC
        + i * cosB * cosC;
}

float calcY(int i, int j, int k) {
    return j * cosA * cosC
        + k * sinA * cosC
        - j * sinA * sinB
        * sinC + k * cosA
        * sinB * sinC
        - i * cosB * sinC;
}

float calcZ(int i, int j, int k) {
    return k * cosA * cosB
        - j * sinA * cosB
        + i * sinB;
}

void calculatePoint(float i, float j, float k, char ch) {
    x = calcX(i, j, k);
    y = calcY(i, j, k);
    z = calcZ(i, j, k) + distFromCam;
    oneOverZ = 1 / z;

    // calculate projection of pointk
    xp = (int) (width / 2 + K1 * oneOverZ * x * 2);
    yp = (int) (height / 2 + K1 * oneOverZ * y);

    idx = xp + yp * width;
    if (idx >= 0 && idx <width * height) {
        if (oneOverZ > zBuffer[idx]) {
            zBuffer[idx] = oneOverZ;
            buffer[idx] = ch;
        }
    }
}

void drawLine(char ch, float x1, float y1, float z1, float x2, float y2, float z2) {
    for (float percent = 0; percent <= 1; percent += 0.025) {
        float _x = x1 + (x2 - x1) * percent;
        float _y = y1 + (y2 - y1) * percent;
        float _z = z1 + (z2 - z1) * percent;
        calculatePoint(_x, _y, _z, ch);
    }
}

float sinNormalized(int x) {
    return (sin(x * 0.1) / 2) + 0.5;
}

int main() {

    // clear the screen (C++ equivalent of "\x1b[2J")
    cout << "\033[2J";

    // hides the cursor (to make cursor show again, use "\033[?25h")
    cout << "\033[?25l";

    while (true) {
        memset(buffer, bgASCIICode, width * height);
        memset(zBuffer, 0, width * height * 4);

        // calculate sin and cos of each angle
        sinA = sin(A);
        sinB = sin(B);
        sinC = sin(C);
        cosA = cos(A);
        cosB = cos(B);
        cosC = cos(C);

        // calculate points on each surface
        float mCubeWidth = cubeWidth * 0.5;//sinNormalized(frame);
        for (float i = -mCubeWidth / 2; i < mCubeWidth / 2; i += 0.15) {
            for (float j = -mCubeWidth / 2; j < mCubeWidth / 2; j += 0.15) {
                calculatePoint(i, j, -mCubeWidth / 2, '@');
                calculatePoint(mCubeWidth / 2, j, i, '$');
                calculatePoint(-mCubeWidth / 2, j, -i, '~');
                calculatePoint(-i, j, mCubeWidth / 2, '#');
                calculatePoint(i, -mCubeWidth / 2, -j, ';');
                calculatePoint(i, mCubeWidth / 2, j, '+');
            }
        }
        

        drawLine('@',
            -cubeWidth / 2, -cubeWidth / 2, -cubeWidth / 2,
            cubeWidth / 2, -cubeWidth / 2, -cubeWidth / 2
        );

        drawLine('$',
            cubeWidth / 2, -cubeWidth / 2, -cubeWidth / 2,
            cubeWidth / 2, cubeWidth / 2, -cubeWidth / 2
        );

        drawLine('~',
            -cubeWidth / 2, cubeWidth / 2, -cubeWidth / 2,
            -cubeWidth / 2, -cubeWidth / 2, -cubeWidth / 2
        );
        
        drawLine('+',
            -cubeWidth / 2, cubeWidth / 2, cubeWidth / 2,
            -cubeWidth / 2, cubeWidth / 2, -cubeWidth / 2
        );

        drawLine('#',
            -cubeWidth / 2, -cubeWidth / 2, cubeWidth / 2,
            -cubeWidth / 2, -cubeWidth / 2, -cubeWidth / 2
        );

        drawLine('&',
            cubeWidth / 2, cubeWidth / 2, cubeWidth / 2,
            cubeWidth / 2, cubeWidth / 2, -cubeWidth / 2
        );

        drawLine('!',
            cubeWidth / 2, -cubeWidth / 2, cubeWidth / 2,
            cubeWidth / 2, -cubeWidth / 2, -cubeWidth / 2
        );

        drawLine(';',
            cubeWidth / 2, cubeWidth / 2, -cubeWidth / 2,
            -cubeWidth / 2, cubeWidth / 2, -cubeWidth / 2
        );

        drawLine('+',
            -cubeWidth / 2, cubeWidth / 2, cubeWidth / 2,
            cubeWidth / 2, cubeWidth / 2, cubeWidth / 2
        );

        drawLine('#',
            -cubeWidth / 2, -cubeWidth / 2, cubeWidth / 2,
            cubeWidth / 2, -cubeWidth / 2, cubeWidth / 2
        );

        drawLine('!',
            cubeWidth / 2, -cubeWidth / 2, cubeWidth / 2,
            cubeWidth / 2, cubeWidth / 2, cubeWidth / 2
        );

        drawLine('$',
            -cubeWidth / 2, cubeWidth / 2, cubeWidth / 2,
            -cubeWidth / 2, -cubeWidth / 2, cubeWidth / 2
        );

        // move terminal cursor to top-left corner
        cout << "\033[H";

        // print out chars to screen from buffer
        for (int k = 0; k < width * height; k++) {

            // change the color of the character
            switch (buffer[k]) {
                case '@':
                    cout << "\033[31m";
                    break;
                case '$':
                    cout << "\033[32m";
                    break;
                case '~':
                    cout << "\033[33m";
                    break;
                case '#':
                    cout << "\033[34m";
                    break;
                case ';':
                    cout << "\033[35m";
                    break;
                case '+':
                    cout << "\033[36m";
                    break;
            }
            putchar(k % width ? buffer[k] : 10);
        }

        // increment angles A, B, and C
        A += 0.02;
        B += 0.02;
        C = 0.01;

        // delay between frames
        this_thread::sleep_for(chrono::microseconds(20000));

        frame++;
    }

    return 0;
}