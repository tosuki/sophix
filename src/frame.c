#include "./frame.h"

WindowFrame createWindowFrame(
    unsigned int borderWidth,
    unsigned long borderColor,
    unsigned long backgroundColor
) {
    WindowFrame frame;

    frame.backgroundColor = backgroundColor;
    frame.borderColor = borderColor;
    frame.borderWidth = borderWidth;

    return frame;
}
