/*
Jeremy Clement
Student No: w1624746
*/

#include <math.h>						
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>	
#include <gl/freeglut.h>
#include <iostream>
#include <string>
#include <vector>

#ifdef WIN32
#include "gltools.h"
#include <windows.h>		
#include <gl\gl.h>			
#include <gl\glu.h>		
#include "glm.h"
#include <gl\glut.h>	

#endif

// Use the STL extension of C++
using namespace std;

//foward declare functions
void resetPerspectiveProjection();
void drawAngleWithScaledText(GLfloat scale);
void setOrthographicProjection();
void ChangeSize(int w, int h);
void RenderScene(void);
void RenderScene2(void);
void TimerFunc(int value);
void drawTexturedQuad(int image);
void GoMenu(int menuValue);

//std::string datatype = "PLANET";
int texture = 1;
int datatype = 1;
int overlay = 0;
int upButton = 0;
int downButton = 0;
int leftButton = 0;
int rightButton = 0;
int zoomSliderPosition = 255;
int DateSliderPosition = 245;
int texture2 = 1;
int datatype2 = 1;
int overlay2 = 0;
int upButton2 = 0;
int downButton2 = 0;
int leftButton2 = 0;
int rightButton2 = 0;
int zoomSliderPosition2 = 255;
int DateSliderPosition2 = 245;
int dimentions = 3;
int compare = 0;
int match = 0;
int same = 0;
int offset = 0;
int run = 0;
int Wwidth;
int Wheight;
int frame = 0, timeTot = 0, timebase = 0;

char frameRate[12];
#pragma mark - set projection

#define AOT0118 0
#define AOT0218 1
#define AOT0318 2
#define AOT0418 3
#define AOT0518 4
#define AOT0618 5
#define AOT0718 6
#define AOT0818 7
#define AOT0918 8
#define AOT1018 9
#define AOT1118 10
#define AOT1218 11

#define APR0115 12
#define APR0215 13
#define APR0315 14
#define APR0415 15
#define APR0515 16
#define APR0615 17
#define APR0715 18
#define APR0815 19
#define APR0915 20
#define APR1015 21
#define APR1115 22
#define APR1215 23

#define CM0115 24
#define CM0215 25
#define CM0315 26
#define CM0415 27
#define CM0515 28
#define CM0615 29
#define CM0715 30
#define CM0815 31
#define CM0915 32
#define CM1015 33
#define CM1115 34
#define CM1215 35

#define CF0118 36
#define CF0218 37
#define CF0318 38
#define CF0418 39
#define CF0518 40
#define CF0618 41
#define CF0718 42
#define CF0818 43
#define CF0918 44
#define CF1018 45
#define CF1118 46
#define CF1218 47 

#define COT0118 48
#define COT0218 49
#define COT0318 50
#define COT0418 51
#define COT0518 52
#define COT0618 53
#define COT0718 54
#define COT0818 55
#define COT0918 56
#define COT1018 57
#define COT1118 58
#define COT1218 59

#define CPR0118 60
#define CPR0218 61
#define CPR0318 62
#define CPR0418 63
#define CPR0518 64
#define CPR0618 65
#define CPR0718 66
#define CPR0818 67
#define CPR0918 68
#define CPR1018 69
#define CPR1118 70
#define CPR1218 71

#define BM0104 72
#define BM0204 73
#define BM0304 74
#define BM0404 75
#define BM0504 76
#define BM0604 77
#define BM0704 78
#define BM0804 79
#define BM0904 80
#define BM1004 81
#define BM1104 82
#define BM1204 83

#define OBT 84
#define OWT 85
#define OET 86

#define AU 87
#define AR 88
#define AD 89
#define AL 90
#define R 91
#define OBD 92
#define OBB 93
#define OBW 94
#define B3D 95
#define B2D 96
#define C 97
#define CO 98
#define E 99
#define S 100
#define L 101

#define AOTG 102
#define APRG 103
#define CMG 104
#define CFG 105
#define COTG 106
#define CPRG 107
#define BMG 108

#define TEXTURE_COUNT 109
GLuint  textures[TEXTURE_COUNT];

const char *textureFiles[TEXTURE_COUNT] = { "001 Aerosol Optical Thickness 2018 01.tga", "001 Aerosol Optical Thickness 2018 02.tga",
											"001 Aerosol Optical Thickness 2018 03.tga", "001 Aerosol Optical Thickness 2018 04.tga",
											"001 Aerosol Optical Thickness 2018 05.tga", "001 Aerosol Optical Thickness 2018 06.tga",
											"001 Aerosol Optical Thickness 2018 07.tga", "001 Aerosol Optical Thickness 2018 08.tga",
											"001 Aerosol Optical Thickness 2018 09.tga", "001 Aerosol Optical Thickness 2018 10.tga",
											"001 Aerosol Optical Thickness 2018 11.tga", "001 Aerosol Optical Thickness 2018 12.tga",

											"002 Aerosol Particle Radius 2015 01.tga", "002 Aerosol Particle Radius 2015 02.tga",
											"002 Aerosol Particle Radius 2015 03.tga", "002 Aerosol Particle Radius 2015 04.tga",
											"002 Aerosol Particle Radius 2015 05.tga", "002 Aerosol Particle Radius 2015 06.tga",
											"002 Aerosol Particle Radius 2015 07.tga", "002 Aerosol Particle Radius 2015 08.tga",
											"002 Aerosol Particle Radius 2015 09.tga", "002 Aerosol Particle Radius 2015 10.tga",
											"002 Aerosol Particle Radius 2015 11.tga", "002 Aerosol Particle Radius 2015 12.tga",

											"003 Carbon Monoxide 2016 01.tga", "003 Carbon Monoxide 2016 02.tga",
											"003 Carbon Monoxide 2016 03.tga", "003 Carbon Monoxide 2016 04.tga",
											"003 Carbon Monoxide 2016 05.tga", "003 Carbon Monoxide 2016 06.tga",
											"003 Carbon Monoxide 2016 07.tga", "003 Carbon Monoxide 2016 08.tga",
											"003 Carbon Monoxide 2016 09.tga", "003 Carbon Monoxide 2016 10.tga",
											"003 Carbon Monoxide 2016 11.tga", "003 Carbon Monoxide 2016 12.tga",

											"004 Cloud Fraction 2018 01.tga", "004 Cloud Fraction 2018 02.tga",
											"004 Cloud Fraction 2018 03.tga", "004 Cloud Fraction 2018 04.tga",
											"004 Cloud Fraction 2018 05.tga", "004 Cloud Fraction 2018 06.tga",
											"004 Cloud Fraction 2018 07.tga", "004 Cloud Fraction 2018 08.tga",
											"004 Cloud Fraction 2018 09.tga", "004 Cloud Fraction 2018 10.tga",
											"004 Cloud Fraction 2018 11.tga", "004 Cloud Fraction 2018 12.tga",

											"005 Cloud Optical Thickness 2018 01.tga", "005 Cloud Optical Thickness 2018 02.tga",
											"005 Cloud Optical Thickness 2018 03.tga", "005 Cloud Optical Thickness 2018 04.tga",
											"005 Cloud Optical Thickness 2018 05.tga", "005 Cloud Optical Thickness 2018 06.tga",
											"005 Cloud Optical Thickness 2018 07.tga", "005 Cloud Optical Thickness 2018 08.tga",
											"005 Cloud Optical Thickness 2018 09.tga", "005 Cloud Optical Thickness 2018 10.tga",
											"005 Cloud Optical Thickness 2018 11.tga", "005 Cloud Optical Thickness 2018 12.tga",

											"006 Cloud Particle Radius 2018 01.tga", "006 Cloud Particle Radius 2018 02.tga",
											"006 Cloud Particle Radius 2018 03.tga", "006 Cloud Particle Radius 2018 04.tga",
											"006 Cloud Particle Radius 2018 05.tga", "006 Cloud Particle Radius 2018 06.tga",
											"006 Cloud Particle Radius 2018 07.tga", "006 Cloud Particle Radius 2018 08.tga",
											"006 Cloud Particle Radius 2018 09.tga", "006 Cloud Particle Radius 2018 10.tga",
											"006 Cloud Particle Radius 2018 11.tga", "006 Cloud Particle Radius 2018 12.tga",

											"034 Blue Marble 2004 01.tga", "034 Blue Marble 2004 02.tga",
											"034 Blue Marble 2004 03.tga", "034 Blue Marble 2004 04.tga",
											"034 Blue Marble 2004 05.tga", "034 Blue Marble 2004 06.tga",
											"034 Blue Marble 2004 07.tga", "034 Blue Marble 2004 08.tga",
											"034 Blue Marble 2004 09.tga", "034 Blue Marble 2004 10.tga",
											"034 Blue Marble 2004 11.tga", "034 Blue Marble 2004 12.tga",

											"Outline Black.tga", "Outline White.tga", "Outline Empty.tga",

											"arrowUp.tga", "arrowRight.tga", "arrowDown.tga", "arrowLeft.tga", "Reset.tga",
											"OverlayButtonOff.tga" , "OverlayButtonBlack.tga", "OverlayButtonWhite.tga",
											"3Dbutton.tga" , "2Dbutton.tga" , "Compare.tga" , "CompareOff.tga" , "MakeSame.tga" ,
											"Seperate.tga" , "Link.tga" ,
	
											"001 Aerosol Optical Thickness Guide.tga" , "002 Aerosol Particle Radius Guide.tga" ,
											"003 Carbon Monoxide Guide.tga" , "004 Cloud Fraction Guide.tga" ,
											"005 Cloud Optical Thickness Guide.tga" , "006 Cloud Particle Radius Guide.tga" ,
											"034 Blue Marble Guide.tga" };

GLfloat moveForwardBack = 0;
GLfloat turnUpDown = 0;
GLfloat turnLeftRight = 0;
GLfloat turnUpDown2 = 0;
GLfloat turnLeftRight2 = 0;

GLfloat test = 0;

GLfloat  whiteLightBright[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat  redLight[] = { 1.0f, 0.0f, 0.0f, 1.0f };
GLfloat  whiteLightLessBright[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat	 lightPos[] = { 100.0f, 100.0f, 50.0f, 1.0f };

bool pickUp1 = false;
bool pickUp2 = false;
bool pickUp3 = false;
bool pickUp4 = false;
bool pickUp5 = false;

GLint iWidth, iHeight, iComponents;
GLenum eFormat;
GLbyte *pBytes0;

vector<GLfloat> points;
GLint xRaster = 25, x = 30;
GLint k, j;
GLint i = 0;
GLsizei y = 500, ww = 500;

//end of intialisation 

void resetPerspectiveProjection() {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

GLUquadricObj *quadricSphere;
GLUquadricObj *map;
void drawPlanet() {
	glEnable(GL_TEXTURE_2D);
	if (datatype == 1) {
		if (texture == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0118]);
		}
		else if (texture == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0218]);
		}
		else if (texture == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0318]);
		}
		else if (texture == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0418]);
		}
		else if (texture == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0518]);
		}
		else if (texture == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0618]);
		}
		else if (texture == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0718]);
		}
		else if (texture == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0818]);
		}
		else if (texture == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0918]);
		}
		else if (texture == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT1018]);
		}
		else if (texture == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT1118]);
		}
		else if (texture == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT1218]);
		}
	}
	else if (datatype == 2) {
		if (texture == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0115]);
		}
		else if (texture == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0215]);
		}
		else if (texture == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0315]);
		}
		else if (texture == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0415]);
		}
		else if (texture == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0515]);
		}
		else if (texture == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0615]);
		}
		else if (texture == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0715]);
		}
		else if (texture == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0815]);
		}
		else if (texture == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0915]);
		}
		else if (texture == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[APR1015]);
		}
		else if (texture == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[APR1115]);
		}
		else if (texture == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[APR1215]);
		}
	}
	else if (datatype == 3) {
		if (texture == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0115]);
		}
		else if (texture == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0215]);
		}
		else if (texture == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0315]);
		}
		else if (texture == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0415]);
		}
		else if (texture == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0515]);
		}
		else if (texture == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0615]);
		}
		else if (texture == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0715]);
		}
		else if (texture == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0815]);
		}
		else if (texture == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0915]);
		}
		else if (texture == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[CM1015]);
		}
		else if (texture == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[CM1115]);
		}
		else if (texture == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[CM1215]);
		}
	}
	else if (datatype == 4) {
		if (texture == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0118]);
		}
		else if (texture == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0218]);
		}
		else if (texture == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0318]);
		}
		else if (texture == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0418]);
		}
		else if (texture == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0518]);
		}
		else if (texture == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0618]);
		}
		else if (texture == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0718]);
		}
		else if (texture == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0818]);
		}
		else if (texture == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0918]);
		}
		else if (texture == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[CF1018]);
		}
		else if (texture == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[CF1118]);
		}
		else if (texture == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[CF1218]);
		}
	}
	else if (datatype == 5) {
		if (texture == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0118]);
		}
		else if (texture == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0218]);
		}
		else if (texture == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0318]);
		}
		else if (texture == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0418]);
		}
		else if (texture == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0518]);
		}
		else if (texture == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0618]);
		}
		else if (texture == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0718]);
		}
		else if (texture == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0818]);
		}
		else if (texture == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0918]);
		}
		else if (texture == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[COT1018]);
		}
		else if (texture == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[COT1118]);
		}
		else if (texture == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[COT1218]);
		}
	}
	else if (datatype == 6) {
		if (texture == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0118]);
		}
		else if (texture == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0218]);
		}
		else if (texture == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0318]);
		}
		else if (texture == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0418]);
		}
		else if (texture == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0518]);
		}
		else if (texture == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0618]);
		}
		else if (texture == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0718]);
		}
		else if (texture == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0818]);
		}
		else if (texture == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0918]);
		}
		else if (texture == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR1018]);
		}
		else if (texture == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR1118]);
		}
		else if (texture == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR1218]);
		}
	}
	else if (datatype == 7) {
		if (texture == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0104]);
		}
		else if (texture == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0204]);
		}
		else if (texture == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0304]);
		}
		else if (texture == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0404]);
		}
		else if (texture == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0504]);
		}
		else if (texture == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0604]);
		}
		else if (texture == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0704]);
		}
		else if (texture == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0804]);
		}
		else if (texture == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0904]);
		}
		else if (texture == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[BM1004]);
		}
		else if (texture == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[BM1104]);
		}
		else if (texture == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[BM1204]);
		}
	}

	glColor3f(0.4, 0.4, 0.4);
	quadricSphere = gluNewQuadric();
	gluQuadricDrawStyle(quadricSphere, GLU_FILL);
	gluQuadricNormals(quadricSphere, GLU_SMOOTH);
	gluQuadricOrientation(quadricSphere, GLU_OUTSIDE);
	gluQuadricTexture(quadricSphere, GL_TRUE);
	gluSphere(quadricSphere, 40.0f, 50, 35);
	glDisable(GL_TEXTURE_2D);
}

void drawPlanetOverlay() {
	glEnable(GL_TEXTURE_2D);

	if (overlay == 0) {
		glBindTexture(GL_TEXTURE_2D, textures[OET]);
	}
	else if (overlay == 1) {
		glBindTexture(GL_TEXTURE_2D, textures[OBT]);
	}
	else if (overlay == 2) {
		glBindTexture(GL_TEXTURE_2D, textures[OWT]);
	}

	glColor3f(0.0, 0.0, 0.0);
	quadricSphere = gluNewQuadric();
	gluQuadricDrawStyle(quadricSphere, GLU_FILL);
	gluQuadricNormals(quadricSphere, GLU_SMOOTH);
	gluQuadricOrientation(quadricSphere, GLU_OUTSIDE);
	gluQuadricTexture(quadricSphere, GL_TRUE);
	gluSphere(quadricSphere, 40.0003f, 50, 35);
	glDisable(GL_TEXTURE_2D);
}

void drawPlanet2() {
	glEnable(GL_TEXTURE_2D);
	if (datatype2 == 1) {
		if (texture2 == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0118]);
		}
		else if (texture2 == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0218]);
		}
		else if (texture2 == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0318]);
		}
		else if (texture2 == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0418]);
		}
		else if (texture2 == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0518]);
		}
		else if (texture2 == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0618]);
		}
		else if (texture2 == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0718]);
		}
		else if (texture2 == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0818]);
		}
		else if (texture2 == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT0918]);
		}
		else if (texture2 == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT1018]);
		}
		else if (texture2 == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT1118]);
		}
		else if (texture2 == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[AOT1218]);
		}
	}
	else if (datatype2 == 2) {
		if (texture2 == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0115]);
		}
		else if (texture2 == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0215]);
		}
		else if (texture2 == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0315]);
		}
		else if (texture2 == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0415]);
		}
		else if (texture2 == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0515]);
		}
		else if (texture2 == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0615]);
		}
		else if (texture2 == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0715]);
		}
		else if (texture2 == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0815]);
		}
		else if (texture2 == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[APR0915]);
		}
		else if (texture2 == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[APR1015]);
		}
		else if (texture2 == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[APR1115]);
		}
		else if (texture2 == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[APR1215]);
		}
	}
	else if (datatype2 == 3) {
		if (texture2 == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0115]);
		}
		else if (texture2 == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0215]);
		}
		else if (texture2 == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0315]);
		}
		else if (texture2 == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0415]);
		}
		else if (texture2 == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0515]);
		}
		else if (texture2 == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0615]);
		}
		else if (texture2 == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0715]);
		}
		else if (texture2 == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0815]);
		}
		else if (texture2 == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[CM0915]);
		}
		else if (texture2 == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[CM1015]);
		}
		else if (texture2 == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[CM1115]);
		}
		else if (texture2 == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[CM1215]);
		}
	}
	else if (datatype2 == 4) {
		if (texture2 == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0118]);
		}
		else if (texture2 == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0218]);
		}
		else if (texture2 == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0318]);
		}
		else if (texture2 == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0418]);
		}
		else if (texture2 == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0518]);
		}
		else if (texture2 == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0618]);
		}
		else if (texture2 == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0718]);
		}
		else if (texture2 == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0818]);
		}
		else if (texture2 == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[CF0918]);
		}
		else if (texture2 == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[CF1018]);
		}
		else if (texture2 == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[CF1118]);
		}
		else if (texture2 == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[CF1218]);
		}
	}
	else if (datatype2 == 5) {
		if (texture2 == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0118]);
		}
		else if (texture2 == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0218]);
		}
		else if (texture2 == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0318]);
		}
		else if (texture2 == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0418]);
		}
		else if (texture2 == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0518]);
		}
		else if (texture2 == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0618]);
		}
		else if (texture2 == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0718]);
		}
		else if (texture2 == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0818]);
		}
		else if (texture2 == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[COT0918]);
		}
		else if (texture2 == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[COT1018]);
		}
		else if (texture2 == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[COT1118]);
		}
		else if (texture2 == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[COT1218]);
		}
	}
	else if (datatype2 == 6) {
		if (texture2 == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0118]);
		}
		else if (texture2 == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0218]);
		}
		else if (texture2 == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0318]);
		}
		else if (texture2 == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0418]);
		}
		else if (texture2 == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0518]);
		}
		else if (texture2 == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0618]);
		}
		else if (texture2 == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0718]);
		}
		else if (texture2 == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0818]);
		}
		else if (texture2 == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR0918]);
		}
		else if (texture2 == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR1018]);
		}
		else if (texture2 == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR1118]);
		}
		else if (texture2 == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[CPR1218]);
		}
	}
	else if (datatype2 == 7) {
		if (texture2 == 1) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0104]);
		}
		else if (texture2 == 2) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0204]);
		}
		else if (texture2 == 3) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0304]);
		}
		else if (texture2 == 4) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0404]);
		}
		else if (texture2 == 5) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0504]);
		}
		else if (texture2 == 6) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0604]);
		}
		else if (texture2 == 7) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0704]);
		}
		else if (texture2 == 8) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0804]);
		}
		else if (texture2 == 9) {
			glBindTexture(GL_TEXTURE_2D, textures[BM0904]);
		}
		else if (texture2 == 10) {
			glBindTexture(GL_TEXTURE_2D, textures[BM1004]);
		}
		else if (texture2 == 11) {
			glBindTexture(GL_TEXTURE_2D, textures[BM1104]);
		}
		else if (texture2 == 12) {
			glBindTexture(GL_TEXTURE_2D, textures[BM1204]);
		}
	}

	glColor3f(0.4, 0.4, 0.4);
	quadricSphere = gluNewQuadric();
	gluQuadricDrawStyle(quadricSphere, GLU_FILL);
	gluQuadricNormals(quadricSphere, GLU_SMOOTH);
	gluQuadricOrientation(quadricSphere, GLU_OUTSIDE);
	gluQuadricTexture(quadricSphere, GL_TRUE);
	gluSphere(quadricSphere, 40.0f, 50, 35);
	glDisable(GL_TEXTURE_2D);
}

void drawPlanetOverlay2() {
	glEnable(GL_TEXTURE_2D);

	if (overlay2 == 0) {
		glBindTexture(GL_TEXTURE_2D, textures[OET]);
	}
	else if (overlay2 == 1) {
		glBindTexture(GL_TEXTURE_2D, textures[OBT]);
	}
	else if (overlay2 == 2) {
		glBindTexture(GL_TEXTURE_2D, textures[OWT]);
	}

	glColor3f(0.0, 0.0, 0.0);
	quadricSphere = gluNewQuadric();
	gluQuadricDrawStyle(quadricSphere, GLU_FILL);
	gluQuadricNormals(quadricSphere, GLU_SMOOTH);
	gluQuadricOrientation(quadricSphere, GLU_OUTSIDE);
	gluQuadricTexture(quadricSphere, GL_TRUE);
	gluSphere(quadricSphere, 40.0003f, 50, 35);
	glDisable(GL_TEXTURE_2D);
}

void drawTexturedQuad()
{
	//add some lighting normals for each vertex
	//draw the texture on the front
	glEnable(GL_TEXTURE_2D);
	// glFrontFace(GL_CW); //use glFrontFace(GL_CW) to texture the other side - not needed here as we set this elsewhere
	glColor3f(0.8, 0.8, 0.8);
	glEnable(GL_TEXTURE_2D);
	//bind the texture 
	glBindTexture(GL_TEXTURE_2D, textures[AOT0118]);
	glBegin(GL_QUADS);
	glVertex3f(2.0, 4.0, 0.0);
	glVertex3f(8.0, 4.0, 0.0);
	glVertex3f(8.0, 6.0, 0.0);
	glVertex3f(2.0, 6.0, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void setOrthographicProjection() {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, Wwidth, 0, Wheight);
	glScalef(1, -1, 1);
	glTranslatef(0, -Wheight, 0);
	glMatrixMode(GL_MODELVIEW);
}

void ChangeSize(int w, int h)
{
	GLfloat fAspect;
	Wwidth = w;
	Wheight = h;
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	fAspect = (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(55.0f, fAspect, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.00, 0.00, 0.01,//eye
		0.00, 0.00, 0.00,//centre
		0.00, 1.00, 0.00);//up
}

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	//drawTexturedQuad();
	glTranslatef(-compare + offset, 0.0, moveForwardBack - 102);
	glRotatef(90.0, -1.0, 0.0, 0.0);
	glRotatef(turnUpDown, 1.0, 0.0, 0.0);
	glRotatef(turnLeftRight, 0.0, 0.0, 1.0);
	drawPlanet();
	drawPlanetOverlay();
	glPopMatrix();
	
	glTranslatef(compare + offset, 0.0, moveForwardBack - 102);
	glRotatef(90.0, -1.0, 0.0, 0.0);
	glRotatef(turnUpDown2, 1.0, 0.0, 0.0);
	glRotatef(turnLeftRight2, 0.0, 0.0, 1.0);
	if (compare > 0) {
		drawPlanet2();
		drawPlanetOverlay2();
	}
	glPopMatrix();
	
	glLoadIdentity();
	setOrthographicProjection();
	
	//up
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[AU]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(60.0, 30.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(60.0, 10.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(40.0, 10.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(40.0, 30.0);
	glEnd();

	//left
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[AL]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(30.0, 60.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(30.0, 40.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(10.0, 40.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(10.0, 60.0);
	glEnd();

	//reset
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[R]); 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(60.0, 60.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(60.0, 40.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(40.0, 40.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(40.0, 60.0);
	glEnd();
	
	//right
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[AR]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(90.0, 60.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(90.0, 40.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(70.0, 40.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(70.0, 60.0);
	glEnd();

	//3D
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[B3D]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(30.0, 90.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(30.0, 70.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(10.0, 70.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(10.0, 90.0);
	glEnd();

	//down
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[AD]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(60.0, 90.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(60.0, 70.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(40.0, 70.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(40.0, 90.0);
	glEnd();

	//2D
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[B2D]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(90.0, 90.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(90.0, 70.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(70.0, 70.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(70.0, 90.0);
	glEnd();

	//overlay off
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[OBD]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(30.0, 120.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(30.0, 100.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(10.0, 100.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(10.0, 120.0);
	glEnd();

	//overlay black
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[OBB]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(60.0, 120.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(60.0, 100.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(40.0, 100.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(40.0, 120.0);
	glEnd();

	//overlay white
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[OBW]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(90.0, 120.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(90.0, 100.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(70.0, 100.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(70.0, 120.0);
	glEnd();

	// Zoom slider background
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(24.0, 260.0);
	glVertex2f(24.0, 130.0);
	glVertex2f(16.0, 130.0);
	glVertex2f(16.0, 260.0);
	glEnd();

	// Date slider background
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(84.0, 250.0);
	glVertex2f(84.0, 130.0);
	glVertex2f(76.0, 130.0);
	glVertex2f(76.0, 250.0);
	glEnd();

	//Zoom slider
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(30.0, zoomSliderPosition + 5);
	glVertex2f(30.0, zoomSliderPosition - 5);
	glVertex2f(10.0, zoomSliderPosition - 5);
	glVertex2f(10.0, zoomSliderPosition + 5);
	glEnd();

	//Date slider
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(90.0, DateSliderPosition + 5);
	glVertex2f(90.0, DateSliderPosition - 5);
	glVertex2f(70.0, DateSliderPosition - 5);
	glVertex2f(70.0, DateSliderPosition + 5);
	glEnd();

	// compare on
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[C]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 35, glutGet(GLUT_WINDOW_HEIGHT) - 40.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 35, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 55, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 55, glutGet(GLUT_WINDOW_HEIGHT) - 40.0);
	glEnd();

	// compare left
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[AL]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 5, glutGet(GLUT_WINDOW_HEIGHT) - 40.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 5, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 25, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 25, glutGet(GLUT_WINDOW_HEIGHT) - 40.0);
	glEnd();

	// compare center
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[R]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 25, glutGet(GLUT_WINDOW_HEIGHT) - 40.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 25, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 5, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 5, glutGet(GLUT_WINDOW_HEIGHT) - 40.0);
	glEnd();

	// compare right
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[AR]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 55, glutGet(GLUT_WINDOW_HEIGHT) - 40.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 55, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 35, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 35, glutGet(GLUT_WINDOW_HEIGHT) - 40.0);
	glEnd();
	
	// compare off
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[CO]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH)/2 - 35, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH)/2 - 35, glutGet(GLUT_WINDOW_HEIGHT) - 30.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH)/2 - 55, glutGet(GLUT_WINDOW_HEIGHT) - 30.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH)/2 - 55, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glEnd();

	// compare seperate
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[S]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 5, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 5, glutGet(GLUT_WINDOW_HEIGHT) - 30.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 25, glutGet(GLUT_WINDOW_HEIGHT) - 30.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 - 25, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glEnd();

	// compare match changes
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[L]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 25, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 25, glutGet(GLUT_WINDOW_HEIGHT) - 30.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 5, glutGet(GLUT_WINDOW_HEIGHT) - 30.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 5, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glEnd();

	// compare  same
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[E]);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 55, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 55, glutGet(GLUT_WINDOW_HEIGHT) - 30.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 35, glutGet(GLUT_WINDOW_HEIGHT) - 30.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) / 2 + 35, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	if (datatype == 1) {
		glBindTexture(GL_TEXTURE_2D, textures[AOTG]);
	}
	else if (datatype == 2) {
		glBindTexture(GL_TEXTURE_2D, textures[APRG]);
	}
	else if (datatype == 3) {
		glBindTexture(GL_TEXTURE_2D, textures[CMG]);
	}
	else if (datatype == 4) {
		glBindTexture(GL_TEXTURE_2D, textures[CFG]);
	}
	else if (datatype == 5) {
		glBindTexture(GL_TEXTURE_2D, textures[COTG]);
	}
	else if (datatype == 6) {
		glBindTexture(GL_TEXTURE_2D, textures[CPRG]);
	}
	else if (datatype == 7) {
		glBindTexture(GL_TEXTURE_2D, textures[BMG]);
	}
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(160, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(160, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(10, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(10, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glEnd();

	if (compare > 0) {
		//up
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[AU]);
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(1.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 40.0, 30.0);
		glTexCoord2f(1.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 40.0, 10.0);
		glTexCoord2f(0.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 60.0, 10.0);
		glTexCoord2f(0.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 60.0, 30.0);
		glEnd();

		//left
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[AL]);
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(1.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 70.0, 60.0);
		glTexCoord2f(1.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 70.0, 40.0);
		glTexCoord2f(0.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 90.0, 40.0);
		glTexCoord2f(0.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 90.0, 60.0);
		glEnd();

		//reset
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[R]);
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(1.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 40.0, 60.0);
		glTexCoord2f(1.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 40.0, 40.0);
		glTexCoord2f(0.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 60.0, 40.0);
		glTexCoord2f(0.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 60.0, 60.0);
		glEnd();

		//right
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[AR]);
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(1.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 10.0, 60.0);
		glTexCoord2f(1.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 10.0, 40.0);
		glTexCoord2f(0.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 30.0, 40.0);
		glTexCoord2f(0.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 30.0, 60.0);
		glEnd();

		//down
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[AD]);
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(1.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 40.0, 90.0);
		glTexCoord2f(1.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 40.0, 70.0);
		glTexCoord2f(0.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 60.0, 70.0);
		glTexCoord2f(0.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 60.0, 90.0);
		glEnd();

		//overlay off
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[OBD]);
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(1.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 70.0, 120.0);
		glTexCoord2f(1.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 70.0, 100.0);
		glTexCoord2f(0.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 90.0, 100.0);
		glTexCoord2f(0.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 90.0, 120.0);
		glEnd();

		//overlay black
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[OBB]);
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(1.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 40.0, 120.0);
		glTexCoord2f(1.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 40.0, 100.0);
		glTexCoord2f(0.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 60.0, 100.0);
		glTexCoord2f(0.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 60.0, 120.0);
		glEnd();

		//overlay white
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[OBW]);
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(1.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 10.0, 120.0);
		glTexCoord2f(1.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 10.0, 100.0);
		glTexCoord2f(0.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 30.0, 100.0);
		glTexCoord2f(0.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 30.0, 120.0);
		glEnd();

		// Date slider background
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 46.0, 250.0);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 46.0, 130.0);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 54.0, 130.0);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 54.0, 250.0);
		glEnd();

		//Date slider
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 40.0, DateSliderPosition2 + 5);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 40.0, DateSliderPosition2 - 5);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 60.0, DateSliderPosition2 - 5);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 60.0, DateSliderPosition2 + 5);
		glEnd();

		glEnable(GL_TEXTURE_2D);
	if (datatype2 == 1) {
		glBindTexture(GL_TEXTURE_2D, textures[AOTG]);
	}
	else if (datatype2 == 2) {
		glBindTexture(GL_TEXTURE_2D, textures[APRG]);
	}
	else if (datatype2 == 3) {
		glBindTexture(GL_TEXTURE_2D, textures[CMG]);
	}
	else if (datatype2 == 4) {
		glBindTexture(GL_TEXTURE_2D, textures[CFG]);
	}
	else if (datatype2 == 5) {
		glBindTexture(GL_TEXTURE_2D, textures[COTG]);
	}
	else if (datatype2 == 6) {
		glBindTexture(GL_TEXTURE_2D, textures[CPRG]);
	}
	else if (datatype2 == 7) {
		glBindTexture(GL_TEXTURE_2D, textures[BMG]);
	}
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 10, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glTexCoord2f(1.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 10, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 1.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 160, glutGet(GLUT_WINDOW_HEIGHT) - 60.0);
	glTexCoord2f(0.0F, 0.0F);
	glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 160, glutGet(GLUT_WINDOW_HEIGHT) - 10.0);
	glEnd();
	}

	if (dimentions == 2) {
		
		
		glEnable(GL_TEXTURE_2D);

		if (datatype == 1) {
			if (texture == 1) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT0118]);
			}
			else if (texture == 2) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT0218]);
			}
			else if (texture == 3) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT0318]);
			}
			else if (texture == 4) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT0418]);
			}
			else if (texture == 5) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT0518]);
			}
			else if (texture == 6) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT0618]);
			}
			else if (texture == 7) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT0718]);
			}
			else if (texture == 8) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT0818]);
			}
			else if (texture == 9) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT0918]);
			}
			else if (texture == 10) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT1018]);
			}
			else if (texture == 11) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT1118]);
			}
			else if (texture == 12) {
				glBindTexture(GL_TEXTURE_2D, textures[AOT1218]);
			}
		}
		else if (datatype == 2) {
			if (texture == 1) {
				glBindTexture(GL_TEXTURE_2D, textures[APR0115]);
			}
			else if (texture == 2) {
				glBindTexture(GL_TEXTURE_2D, textures[APR0215]);
			}
			else if (texture == 3) {
				glBindTexture(GL_TEXTURE_2D, textures[APR0315]);
			}
			else if (texture == 4) {
				glBindTexture(GL_TEXTURE_2D, textures[APR0415]);
			}
			else if (texture == 5) {
				glBindTexture(GL_TEXTURE_2D, textures[APR0515]);
			}
			else if (texture == 6) {
				glBindTexture(GL_TEXTURE_2D, textures[APR0615]);
			}
			else if (texture == 7) {
				glBindTexture(GL_TEXTURE_2D, textures[APR0715]);
			}
			else if (texture == 8) {
				glBindTexture(GL_TEXTURE_2D, textures[APR0815]);
			}
			else if (texture == 9) {
				glBindTexture(GL_TEXTURE_2D, textures[APR0915]);
			}
			else if (texture == 10) {
				glBindTexture(GL_TEXTURE_2D, textures[APR1015]);
			}
			else if (texture == 11) {
				glBindTexture(GL_TEXTURE_2D, textures[APR1115]);
			}
			else if (texture == 12) {
				glBindTexture(GL_TEXTURE_2D, textures[APR1215]);
			}
		}
		else if (datatype == 3) {
			if (texture == 1) {
				glBindTexture(GL_TEXTURE_2D, textures[CM0115]);
			}
			else if (texture == 2) {
				glBindTexture(GL_TEXTURE_2D, textures[CM0215]);
			}
			else if (texture == 3) {
				glBindTexture(GL_TEXTURE_2D, textures[CM0315]);
			}
			else if (texture == 4) {
				glBindTexture(GL_TEXTURE_2D, textures[CM0415]);
			}
			else if (texture == 5) {
				glBindTexture(GL_TEXTURE_2D, textures[CM0515]);
			}
			else if (texture == 6) {
				glBindTexture(GL_TEXTURE_2D, textures[CM0615]);
			}
			else if (texture == 7) {
				glBindTexture(GL_TEXTURE_2D, textures[CM0715]);
			}
			else if (texture == 8) {
				glBindTexture(GL_TEXTURE_2D, textures[CM0815]);
			}
			else if (texture == 9) {
				glBindTexture(GL_TEXTURE_2D, textures[CM0915]);
			}
			else if (texture == 10) {
				glBindTexture(GL_TEXTURE_2D, textures[CM1015]);
			}
			else if (texture == 11) {
				glBindTexture(GL_TEXTURE_2D, textures[CM1115]);
			}
			else if (texture == 12) {
				glBindTexture(GL_TEXTURE_2D, textures[CM1215]);
			}
		}
		else if (datatype == 4) {
			if (texture == 1) {
				glBindTexture(GL_TEXTURE_2D, textures[CF0118]);
			}
			else if (texture == 2) {
				glBindTexture(GL_TEXTURE_2D, textures[CF0218]);
			}
			else if (texture == 3) {
				glBindTexture(GL_TEXTURE_2D, textures[CF0318]);
			}
			else if (texture == 4) {
				glBindTexture(GL_TEXTURE_2D, textures[CF0418]);
			}
			else if (texture == 5) {
				glBindTexture(GL_TEXTURE_2D, textures[CF0518]);
			}
			else if (texture == 6) {
				glBindTexture(GL_TEXTURE_2D, textures[CF0618]);
			}
			else if (texture == 7) {
				glBindTexture(GL_TEXTURE_2D, textures[CF0718]);
			}
			else if (texture == 8) {
				glBindTexture(GL_TEXTURE_2D, textures[CF0818]);
			}
			else if (texture == 9) {
				glBindTexture(GL_TEXTURE_2D, textures[CF0918]);
			}
			else if (texture == 10) {
				glBindTexture(GL_TEXTURE_2D, textures[CF1018]);
			}
			else if (texture == 11) {
				glBindTexture(GL_TEXTURE_2D, textures[CF1118]);
			}
			else if (texture == 12) {
				glBindTexture(GL_TEXTURE_2D, textures[CF1218]);
			}
		}
		else if (datatype == 5) {
			if (texture == 1) {
				glBindTexture(GL_TEXTURE_2D, textures[COT0118]);
			}
			else if (texture == 2) {
				glBindTexture(GL_TEXTURE_2D, textures[COT0218]);
			}
			else if (texture == 3) {
				glBindTexture(GL_TEXTURE_2D, textures[COT0318]);
			}
			else if (texture == 4) {
				glBindTexture(GL_TEXTURE_2D, textures[COT0418]);
			}
			else if (texture == 5) {
				glBindTexture(GL_TEXTURE_2D, textures[COT0518]);
			}
			else if (texture == 6) {
				glBindTexture(GL_TEXTURE_2D, textures[COT0618]);
			}
			else if (texture == 7) {
				glBindTexture(GL_TEXTURE_2D, textures[COT0718]);
			}
			else if (texture == 8) {
				glBindTexture(GL_TEXTURE_2D, textures[COT0818]);
			}
			else if (texture == 9) {
				glBindTexture(GL_TEXTURE_2D, textures[COT0918]);
			}
			else if (texture == 10) {
				glBindTexture(GL_TEXTURE_2D, textures[COT1018]);
			}
			else if (texture == 11) {
				glBindTexture(GL_TEXTURE_2D, textures[COT1118]);
			}
			else if (texture == 12) {
				glBindTexture(GL_TEXTURE_2D, textures[COT1218]);
			}
		}
		else if (datatype == 6) {
			if (texture == 1) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR0118]);
			}
			else if (texture == 2) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR0218]);
			}
			else if (texture == 3) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR0318]);
			}
			else if (texture == 4) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR0418]);
			}
			else if (texture == 5) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR0518]);
			}
			else if (texture == 6) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR0618]);
			}
			else if (texture == 7) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR0718]);
			}
			else if (texture == 8) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR0818]);
			}
			else if (texture == 9) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR0918]);
			}
			else if (texture == 10) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR1018]);
			}
			else if (texture == 11) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR1118]);
			}
			else if (texture == 12) {
				glBindTexture(GL_TEXTURE_2D, textures[CPR1218]);
			}
		}
		else if (datatype == 7) {
			if (texture == 1) {
				glBindTexture(GL_TEXTURE_2D, textures[BM0104]);
			}
			else if (texture == 2) {
				glBindTexture(GL_TEXTURE_2D, textures[BM0204]);
			}
			else if (texture == 3) {
				glBindTexture(GL_TEXTURE_2D, textures[BM0304]);
			}
			else if (texture == 4) {
				glBindTexture(GL_TEXTURE_2D, textures[BM0404]);
			}
			else if (texture == 5) {
				glBindTexture(GL_TEXTURE_2D, textures[BM0504]);
			}
			else if (texture == 6) {
				glBindTexture(GL_TEXTURE_2D, textures[BM0604]);
			}
			else if (texture == 7) {
				glBindTexture(GL_TEXTURE_2D, textures[BM0704]);
			}
			else if (texture == 8) {
				glBindTexture(GL_TEXTURE_2D, textures[BM0804]);
			}
			else if (texture == 9) {
				glBindTexture(GL_TEXTURE_2D, textures[BM0904]);
			}
			else if (texture == 10) {
				glBindTexture(GL_TEXTURE_2D, textures[BM1004]);
			}
			else if (texture == 11) {
				glBindTexture(GL_TEXTURE_2D, textures[BM1104]);
			}
			else if (texture == 12) {
				glBindTexture(GL_TEXTURE_2D, textures[BM1204]);
			}
		}

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glTexCoord2f(0.0F, 1.0F);
		glVertex2f(0.0, 0.0);
		glTexCoord2f(0.0F, 0.0F);
		glVertex2f(0.0, glutGet(GLUT_WINDOW_HEIGHT));
		glTexCoord2f(1.0F, 0.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glTexCoord2f(1.0F, 1.0F);
		glVertex2f(glutGet(GLUT_WINDOW_WIDTH), 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	
	resetPerspectiveProjection();

	glutSwapBuffers();
}

void keyInput(unsigned char key, int Shipx, int Shipy)
{
	switch (key)
	{
	case 'v':
		turnLeftRight = 0;
		texture = 1;
		run = 1;
		break;
	case 'b':
		run = 0;
		break;
	}
	glutPostRedisplay();
}

#pragma mark - timer function

void TimerFunc(int value)
{
	if (run == 1) {
		turnLeftRight = turnLeftRight + 1;
		if (turnLeftRight > 360) {
			turnLeftRight = 0;
			if (texture < 12) {
				texture = texture + 1;
			}
			else {
				run = 0;
			}
		}
	}

	//buttons
	if (upButton == 1) {
		turnUpDown = turnUpDown + 1;
		if (match == 1) {
			turnUpDown2 = turnUpDown2 + 1;
		}
	} else if (downButton == 1) {
		turnUpDown = turnUpDown - 1;
		if (match == 1) {
			turnUpDown2 = turnUpDown2 - 1;
		}
	} else if (leftButton == 1) {
		turnLeftRight = turnLeftRight + 1;
		if (match == 1) {
			turnLeftRight2 = turnLeftRight2 + 1;
		}
	} else if (rightButton == 1) {
		turnLeftRight = turnLeftRight - 1;
		if (match == 1) {
			turnLeftRight2 = turnLeftRight2 - 1;
		}
	} else if (upButton2 == 1) {
		turnUpDown2 = turnUpDown2 + 1;
		if (match == 1) {
			turnUpDown = turnUpDown + 1;
		}
	}
	else if (downButton2 == 1) {
		turnUpDown2 = turnUpDown2 - 1;
		if (match == 1) {
			turnUpDown = turnUpDown - 1;
		}
	}
	else if (leftButton2 == 1) {
		turnLeftRight2 = turnLeftRight2 + 1;
		if (match == 1) {
			turnLeftRight = turnLeftRight + 1;
		}
	}
	else if (rightButton2 == 1) {
		turnLeftRight2 = turnLeftRight2 - 1;
		if (match == 1) {
			turnLeftRight = turnLeftRight - 1;
		}
	}

	

	glutTimerFunc(25, TimerFunc, 1);
	glutPostRedisplay();

}

void myMouse(GLint button, GLint state, GLint x, GLint y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		 points.push_back(x);
		 points.push_back(y);
		 if (x > 10 && x < 30) {   // rotate left
			if (y > 40 && y < 60) {
				leftButton = 1;
			}
			else if (y > 100 && y < 120) {	// overlay off
				overlay = 0;
			}
			else if (y > 70 && y < 90) {   // 3D
				dimentions = 3;
			} else if (y > 130 && y < 260) {   //zoom slider
				zoomSliderPosition = y;
				if (y < 135) {
					zoomSliderPosition = 135;
				}
				else if (zoomSliderPosition > 255) {
					zoomSliderPosition = 255;
				}
				moveForwardBack = 60 - (zoomSliderPosition - 135) / 2;
			}
		 } else if (x > 40 && x < 60) {  //rotate Y and reset
			 if (y > 10 && y < 30) {   //rotate up
				 upButton = 1;
			 }
			 else if (y > 40 && y < 60) {   //reset
				 turnLeftRight = 0;
				 turnUpDown = 0;
				 moveForwardBack = 0;
				 texture = 1;
				 zoomSliderPosition = 255;
				 DateSliderPosition = 245;
			 }
			 else if (y > 70 && y < 90) {   //rotate down
				 downButton = 1;
			 }
			 else if (y > 100 && y < 120) {	// overlay black
				 overlay = 1;
			 }
		 } else if (x > 70 && x < 90) {   // rotate right
			if (y > 40 && y < 60) {
				rightButton = 1;
			} else if (y > 100 && y < 120) {	// overlay white
				overlay = 2;
			} else if (y > 70 && y < 90) {   // 2D
				dimentions = 2;
			} else if (y > 130 && y < 250) {   //date slider
				DateSliderPosition = y;
				if (y < 135) {
					DateSliderPosition = 135;
				}else if (y > 245) {
					DateSliderPosition = 245;
				} 
				if (DateSliderPosition >= 240) {
					texture = 1;
				} else if (DateSliderPosition < 240 && DateSliderPosition >= 230) {
					texture = 2;
				} else if (DateSliderPosition < 230 && DateSliderPosition >= 220) {
					texture = 3;
				} else if (DateSliderPosition < 220 && DateSliderPosition >= 210) {
					texture = 4;
				} else if (DateSliderPosition < 210 && DateSliderPosition >= 200) {
					texture = 5;
				} else if (DateSliderPosition < 200 && DateSliderPosition >= 190) {
					texture = 6;
				} else if (DateSliderPosition < 190 && DateSliderPosition >= 180) {
					texture = 7;
				} else if (DateSliderPosition < 180 && DateSliderPosition >= 170) {
					texture = 8;
				} else if (DateSliderPosition < 170 && DateSliderPosition >= 160) {
					texture = 9;
				} else if (DateSliderPosition < 160 && DateSliderPosition >= 150) {
					texture = 10;
				} else if (DateSliderPosition < 150 && DateSliderPosition >= 140) {
					texture = 11;
				} else if (DateSliderPosition < 140) {
					texture = 12;
				}
			}
		 } else if (x > glutGet(GLUT_WINDOW_WIDTH) / 2 - 55 && x < glutGet(GLUT_WINDOW_WIDTH) / 2 - 35) {
			if (y > glutGet(GLUT_WINDOW_HEIGHT) - 60.0 && y < glutGet(GLUT_WINDOW_HEIGHT) - 40.0) {		// compare on
				compare = 42;
			} else if (y > glutGet(GLUT_WINDOW_HEIGHT) - 30.0 && y < glutGet(GLUT_WINDOW_HEIGHT) - 10.0) {	// compare off
				compare = 0;
				offset = 0;
			}
		} else if (x > glutGet(GLUT_WINDOW_WIDTH) / 2 - 25 && x < glutGet(GLUT_WINDOW_WIDTH) / 2 - 5) {
			if (y > glutGet(GLUT_WINDOW_HEIGHT) - 60.0 && y < glutGet(GLUT_WINDOW_HEIGHT) - 40.0 && compare == 42) {	// compare left
				offset = 42;
			} else if (y > glutGet(GLUT_WINDOW_HEIGHT) - 30.0 && y < glutGet(GLUT_WINDOW_HEIGHT) - 10.0) {	// compare seperate
				match = 0;
				same = 0;
			}
		} else if (x > glutGet(GLUT_WINDOW_WIDTH) / 2 + 5 && x < glutGet(GLUT_WINDOW_WIDTH) / 2 + 25) {
			if (y > glutGet(GLUT_WINDOW_HEIGHT) - 60.0 && y < glutGet(GLUT_WINDOW_HEIGHT) - 40.0) {		// compare center
				offset = 0;
			} else if (y > glutGet(GLUT_WINDOW_HEIGHT) - 30.0 && y < glutGet(GLUT_WINDOW_HEIGHT) - 10.0) {	// compare match changes
				match = 1;
			}
		}
		else if (x > glutGet(GLUT_WINDOW_WIDTH) / 2 + 35 && x < glutGet(GLUT_WINDOW_WIDTH) / 2 + 55) {
			if (y > glutGet(GLUT_WINDOW_HEIGHT) - 60.0 && y < glutGet(GLUT_WINDOW_HEIGHT) - 40.0 && compare == 42) {	// compare right
				offset = -42;
			} else if (y > glutGet(GLUT_WINDOW_HEIGHT) - 30.0 && y < glutGet(GLUT_WINDOW_HEIGHT) - 10.0) {	// compare make same
				turnLeftRight2 = turnLeftRight;
				turnUpDown2 = turnUpDown;
				match = 1;
			}
		} else if (compare > 0) {
			if (x > glutGet(GLUT_WINDOW_WIDTH) - 90 && x < glutGet(GLUT_WINDOW_WIDTH) - 70) {   // rotate left
				if (y > 40 && y < 60) {
					leftButton2 = 1;
				}
				else if (y > 100 && y < 120) {	// overlay off
					overlay2 = 0;
				}
			} else if (x > glutGet(GLUT_WINDOW_WIDTH) - 60 && x < glutGet(GLUT_WINDOW_WIDTH) - 40) {  //rotate Y and reset
				if (y > 10 && y < 30) {   //rotate up
					upButton2 = 1;
				} else if (y > 40 && y < 60) {   //reset
					turnLeftRight2 = 0;
					turnUpDown2 = 0;
					moveForwardBack = 0;
					texture2 = 1;
					DateSliderPosition2 = 245;
				} else if (y > 70 && y < 90) {   //rotate down
					downButton2 = 1;
				} else if (y > 100 && y < 120) {	// overlay black
					overlay2 = 1;
				} else if (y > 130 && y < 250) {   //date slider
					DateSliderPosition2 = y;
					if (y < 135) {
						DateSliderPosition2 = 135;
					} else if (y > 245) {
						DateSliderPosition2 = 245;
					}
					if (DateSliderPosition2 >= 240) {
						texture2 = 1;
					} else if (DateSliderPosition2 < 240 && DateSliderPosition2 >= 230) {
						texture2 = 2;
					} else if (DateSliderPosition2 < 230 && DateSliderPosition2 >= 220) {
						texture2 = 3;
					} else if (DateSliderPosition2 < 220 && DateSliderPosition2 >= 210) {
						texture2 = 4;
					} else if (DateSliderPosition2 < 210 && DateSliderPosition2 >= 200) {
						texture2 = 5;
					} else if (DateSliderPosition2 < 200 && DateSliderPosition2 >= 190) {
						texture2 = 6;
					} else if (DateSliderPosition2 < 190 && DateSliderPosition2 >= 180) {
						texture2 = 7;
					} else if (DateSliderPosition2 < 180 && DateSliderPosition2 >= 170) {
						texture2 = 8;
					} else if (DateSliderPosition2 < 170 && DateSliderPosition2 >= 160) {
						texture2 = 9;
					} else if (DateSliderPosition2 < 160 && DateSliderPosition2 >= 150) {
						texture2 = 10;
					} else if (DateSliderPosition2 < 150 && DateSliderPosition2 >= 140) {
						texture2 = 11;
					} else if (DateSliderPosition2 < 140) {
						texture2 = 12;
					}
				}
			} else if (x > glutGet(GLUT_WINDOW_WIDTH) - 30 && x < glutGet(GLUT_WINDOW_WIDTH) - 10) {   // rotate right
				if (y > 40 && y < 60) {
					rightButton2 = 1;
				} else if (y > 100 && y < 120) {	// overlay white
					overlay2 = 2;
				} 
			}
		}
	}  else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		upButton = 0;
		downButton = 0;
		leftButton = 0;
		rightButton = 0;
		upButton2 = 0;
		downButton2 = 0;
		leftButton2 = 0;
		rightButton2 = 0;
	}
	
	glutPostRedisplay();
}

void init() {
	GLbyte *pBytes0;
	GLuint texture;
	glGenTextures(1, &texture);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(TEXTURE_COUNT, textures);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	for (int iLoop = 0; iLoop < TEXTURE_COUNT; iLoop++)
	{
		glBindTexture(GL_TEXTURE_2D, textures[iLoop]);

		pBytes0 = gltLoadTGA(textureFiles[iLoop], &iWidth, &iHeight,
			&iComponents, &eFormat);

		glTexImage2D(GL_TEXTURE_2D, 0, iComponents, iWidth, iHeight, 0, eFormat, GL_UNSIGNED_BYTE, pBytes0);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		free(pBytes0);
	}


	glEnable(GL_TEXTURE_2D);					//Enable 2D texturing
	glEnable(GL_DEPTH_TEST);					//Hidden surface removal
	glFrontFace(GL_CCW);						//Counter clock-wise polygons face out
	glCullFace(GL_BACK);						//Cull inside faces
	glEnable(GL_CULL_FACE);						//Do not calculate inside

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);		//Black background
}

#pragma mark - main function

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(900, 900);// a 16:9 ratio
	glutCreateWindow("1");
	glutKeyboardFunc(keyInput);
	glutReshapeFunc(ChangeSize);

	int AerosolOpticalThickness2018 = glutCreateMenu(GoMenu);
	glutAddMenuEntry("1", 1);
	glutAddMenuEntry("2", 2);
	int AerosolOpticalThickness = glutCreateMenu(GoMenu);
	glutAddSubMenu("2018", AerosolOpticalThickness2018);

	int AerosolParticleRadius2015 = glutCreateMenu(GoMenu);
	glutAddMenuEntry("1", 3);
	glutAddMenuEntry("2", 4);
	int AerosolParticleRadius = glutCreateMenu(GoMenu);
	glutAddSubMenu("2015", AerosolParticleRadius2015);

	int CarbonMonoxide2016 = glutCreateMenu(GoMenu);
	glutAddMenuEntry("1", 5);
	glutAddMenuEntry("2", 6);
	int CarbonMonoxide = glutCreateMenu(GoMenu);
	glutAddSubMenu("2016", CarbonMonoxide2016);

	int CloudFraction2018 = glutCreateMenu(GoMenu);
	glutAddMenuEntry("1", 7);
	glutAddMenuEntry("2", 8);
	int CloudFraction = glutCreateMenu(GoMenu);
	glutAddSubMenu("2018", CloudFraction2018);

	int CloudOpticalThickness2018 = glutCreateMenu(GoMenu);
	glutAddMenuEntry("1", 9);
	glutAddMenuEntry("2", 10);
	int CloudOpticalThickness = glutCreateMenu(GoMenu);
	glutAddSubMenu("2018", CloudOpticalThickness2018);

	int CloudParticleRadius2018 = glutCreateMenu(GoMenu);
	glutAddMenuEntry("1", 11);
	glutAddMenuEntry("2", 12);
	int CloudParticleRadius = glutCreateMenu(GoMenu);
	glutAddSubMenu("2018", CloudParticleRadius2018);
	
	int Atmosphere = glutCreateMenu(GoMenu);
	glutAddSubMenu("Aerosol Optical Thickness", AerosolOpticalThickness);
	glutAddSubMenu("Aerosol Particle Radius", AerosolParticleRadius);
	glutAddSubMenu("Carbon Monoxide", CarbonMonoxide);
	glutAddSubMenu("Cloud Fraction", CloudFraction);
	glutAddSubMenu("Cloud Optical Thickness", CloudOpticalThickness);
	glutAddSubMenu("Cloud Particle Radius", CloudParticleRadius);
	
	int BlueMarble2004 = glutCreateMenu(GoMenu);
	glutAddMenuEntry("1", 13);
	glutAddMenuEntry("2", 14);
	int BlueMarble = glutCreateMenu(GoMenu);
	glutAddSubMenu("2004", BlueMarble2004);
	
	int other = glutCreateMenu(GoMenu);
	glutAddSubMenu("Blue Marble", BlueMarble);
	
	int mainMenu = glutCreateMenu(GoMenu);
	glutAddSubMenu("Atmosphere", Atmosphere);
	glutAddSubMenu("Other", other);
	
	//glutAddSubMenu("Other", sub1);
	

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(RenderScene);
	glutTimerFunc(25, TimerFunc, 1);

	init();

	//Mouse interaction
	glutMouseFunc(myMouse);

	glutMainLoop();
	return 0;
}

void GoMenu(int menuValue) {
	switch (menuValue) {
	case 1:
		datatype = 1;
		break;
	case 2:
		datatype2 = 1;
		break;
	case 3:
		datatype = 2;
		break;
	case 4:
		datatype2 = 2;
		break;
	case 5:
		datatype = 3;
		break;
	case 6:
		datatype2 = 3;
		break;
	case 7:
		datatype = 4;
		break;
	case 8:
		datatype2 = 4;
		break;
	case 9:
		datatype = 5;
		break;
	case 10:
		datatype2 = 5;
		break;
	case 11:
		datatype = 6;
		break;
	case 12:
		datatype2 = 6;
		break;
	case 13:
		datatype = 7;
		break;
	case 14:
		datatype2 = 7;
		break;

	}
	glutPostRedisplay();
}
