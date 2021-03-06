//
//  Common.h
//  SudokuSolver
//
//  Created by Denis Lebedev on 12/6/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <OpenCV/opencv2/imgproc/imgproc_c.h>
#import <OpenCV/opencv2/objdetect/objdetect.hpp>

typedef struct  
{
    double r, g, b;    /* Channel intensities between 0.0 and 1.0 */
} rgb_color;

typedef enum {
    kPixelTypeNormal,
    kPixelTypeArc,
    kPixelTypeEnd,
    kPixelTypeNode3,
    kPixelTypeNode4,
    kPixelTypeNode5,
    kPixelTypeUndefined,
} kPixelType;

typedef struct charStruct {
    kPixelType features[10];
    int value;
    unsigned char isRecognized;
    int g1;
    int g2;
    int g3;
} charStruct;

void AdaptiveThreshold(IplImage *source, IplImage *dest, int size);
void GetSubImage(IplImage *source, IplImage *dest, CvRect roiRect);
IplImage *rotateImage(const IplImage *img, int angle);
CvPoint intersectionBetweenLines(CvPoint p1, CvPoint p2, CvPoint p3, CvPoint p4);
void detectSudokuBoundingBox(IplImage *image, CvPoint box[]);
IplImage* cropImage(IplImage *source);
IplImage* cropGarbageFromTopAndBottom(IplImage *source);
void splitVerticalLineIntoDigits(IplImage *source, IplImage *array[9]);
void splitSudokuIntoVerticalStripes(IplImage *source, IplImage *stripes[9]);
void thinImage(IplImage *source, IplImage *destination);

IplImage *closeImage(IplImage *source);
void SSDebugOutput(IplImage *source);

charStruct SSRezognizeNumericCharacter(IplImage *source);