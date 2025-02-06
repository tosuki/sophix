#ifndef FRAME_H
#define FRAME_H

typedef struct {
    unsigned int borderWidth;
    unsigned long borderColor;
    unsigned long backgroundColor;
} WindowFrame;

WindowFrame createWindowFrame(unsigned int borderWidth, unsigned long borderColor, unsigned long backgroundColor);

#endif
