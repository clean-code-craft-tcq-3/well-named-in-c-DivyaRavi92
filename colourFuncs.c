#include <stdio.h>
#include <assert.h>
#include "colourTypes.h"
#include "colorCfg.h"

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
}
int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}
ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

void testNumberToPair(int pairNumber,enum MajorColor expectedMajor,enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}
void testPairToNumber(enum MajorColor major,enum MinorColor minor,int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}
void referenceManual()
{
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    for(int colorPairCount = 1; colorPairCount < MAX_COLORPAIR_NAME_CHARS; colorPairCount++)
    {
         ColorPair colorPair = GetColorFromPairNumber(colorPairCount);
         ColorPairToString(&colorPair, colorPairNames);
    }
}
