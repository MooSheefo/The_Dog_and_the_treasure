#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <glut.h>
#include <cstdlib>
#include <ctime>


float dogposx ;
float dogposz ;
float dogx  ;
float dogz ;
float swingrot = 0;
float fencecolor1r = 0.6;
float fencecolor1g = 0.6; 
float fencecolor1b = 0.5;
float fencecolor2r = 0.4;
float fencecolor2g = 0.4;
float fencecolor2b = 0.4;
float flowerrot = 0;
float benchtra = 0;
float treesca = 1;
bool lpressed = false;
float eyex = 0.0;
float eyey = 0.1;
bool flowerarr;
bool swingarr;
bool bencharr;
bool treearr;
double dogangle = 0;
float* goalx = new float[2];
float* goalz = new float[2];
float goalposx;
float goalposz;
bool entered = false;
float goalxu;
float goalzu;
bool gameend = false;
float legrotright = 0;
float legrotleft = 0;
bool rightlegreached;
bool leftlegreached;
float armrotright = 0;
float armrotleft = 0;
bool rightarmreached;
bool leftarmreached;
float armwinrot = 0;
float bodywinrot = 0;
bool bodywinreached;
float ballrot;
int gametime = 100;
bool timerup;
float dogshakeheadrot;
bool dogshakeheadarr;



void cylinder(GLfloat base, GLfloat top, GLfloat h, float r, float g, float b) {

	glColor3f(r, g, b);
	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluCylinder(qobj, base, top, h, 25, 25);

}




void doghead() {

	

	glPushMatrix();
	glColor3f(0.4f, 0.2f, 0.0f);
	glutSolidSphere(1.5, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -0.3, 1);
	glColor3f(0.9f, 0.7f, 0.5f);
	glutSolidSphere(0.8, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -0.3, 1.8);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutSolidSphere(0.2, 25, 25);
	glPopMatrix();


	glPushMatrix();
	glScaled(1, 2, 1);
	glTranslated(-0.6, 0.3, 1.2);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidSphere(0.2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScaled(1, 2, 1);
	glTranslated(0.6, 0.3, 1.2);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidSphere(0.2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScaled(1, 2, 1);
	glTranslated(0.6, 0.3, 1.4);
	glColor3f(0.5f, 0.7f, 0.9f);
	glutSolidSphere(0.1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScaled(1, 2, 1);
	glTranslated(-0.6, 0.3, 1.4);
	glColor3f(0.5f, 0.7f, 0.9f);
	glutSolidSphere(0.1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScaled(1, 2, 1);
	glTranslated(-0.6, 0.3, 1.5);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutSolidSphere(0.05, 25, 25);
	glPopMatrix();


	glPushMatrix();
	glScaled(1, 2, 1);
	glTranslated(0.6, 0.3, 1.5);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutSolidSphere(0.05, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScaled(3, 1, 1);
	glTranslated(0, -1.2, 0.85);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutSolidSphere(0.1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScaled(1.5, 3, 1);
	glTranslated(0, -0.5, 0.75);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(0.1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScaled(2, 1, 1);
	glTranslated(0.3, 1.1, 0.7);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutSolidSphere(0.1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScaled(2, 1, 1);
	glTranslated(-0.3, 1.1, 0.7);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutSolidSphere(0.1, 25, 25);
	glPopMatrix();


	glPushMatrix();
	glTranslated(1.1, 0.4, 0.2);
	glRotated(90, 0, 1, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutSolidCone(0.5, 1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.1, 0.4, 0.2);
	glRotated(-90, 0, 1, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutSolidCone(0.5, 1, 25, 25);
	glPopMatrix();


}







void dog(float scx,float scy,float scz,float x,float z) {

	glPushMatrix();
	glTranslatef(x,125, z);
	glRotatef(bodywinrot, 0, 1, 0);
	glScalef(scx, scy, scz);
	glRotated(dogangle, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0, -2, 0);
	glRotated(-90, 1, 0, 0);
	cylinder(0.5, 0.5, 1, 0.4, 0.2, 0.0);
	glPopMatrix();


	glPushMatrix();
	glRotatef(dogshakeheadrot, 0, 1, 0);
	doghead();
	glPopMatrix();



	glPushMatrix();
	glTranslated(0, -2.4, 0.6);
	glColor3f(0.9f, 0.9f, 0.0f);
	glutSolidSphere(0.15, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScaled(1.5, 2.2, 1);
	glTranslated(0, -2.4, 0);
	glColor3f(0.4f, 0.2f, 0.0f);
	glutSolidSphere(1.5, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScaled(1.5, 2.2, 1);
	glTranslated(0, -2.4, 0.6);
	glColor3f(0.9f, 0.7f, 0.5f);
	glutSolidSphere(1.1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -4, 0);
	if (gameend == true) {
		glRotatef(-90, 1,0 , 0);
	}
	glRotatef(armrotright, 0, 1, 0);
	glTranslatef(0, 4, 0);

	glPushMatrix();
	glTranslatef(2.8, -4, 0.5);
	glRotated(-25, 0, 0, 1);
	glRotated(-90, 0, 1, 0);
	cylinder(0.3, 0.3, 1.5, 0.4, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();

	//if (gameend == true) {
	//	glTranslatef(0.65, -7.95, 2.5);
	//	glRotatef(-90, 0, 0, 1);
	//	glTranslatef(-2.65, 5.7, -0.5);
	//}

	glPushMatrix();
	glTranslatef(2.65, -5.7, 0.5);
	glRotated(-90, 1, 0, 0);
	cylinder(0.3, 0.3, 2, 0.4, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.7, -6, 0.6);
	glColor3f(0.9f, 0.7f, 0.5f);
	glutSolidSphere(0.5, 25, 25);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -3.5, 0);
	if (gameend == true) {
		glRotatef(180, 1, 0, 0);
	}
	glRotatef(armrotleft, 0, 1, 0);
	glTranslatef(0, 3.5, 0);

	glPushMatrix();
	glTranslatef(-1.5, -3.5, 0.5);
	glRotated(25, 0, 0, 1);
	glRotated(-90, 0, 1, 0);
	cylinder(0.3, 0.3, 1.5, 0.4, 0.2, 0.1);
	glPopMatrix();


	glPushMatrix();
	if (gameend == true) {
		glTranslatef(-2.65,-3.8 , 0.5);
		glRotatef(armwinrot, 0, 1, 0);
		glRotatef(20, 0, 0, 1);
		glTranslatef(2.65, 3.8, -0.5);
	}

	glPushMatrix();
	glTranslatef(-2.65, -5.8, 0.5);
	glRotated(-90, 1, 0, 0);
	cylinder(0.3, 0.3, 2, 0.4, 0.2, 0.1);
	glPopMatrix();



	glPushMatrix();
	glTranslated(-2.7, -6, 0.6);
	glColor3f(0.9f, 0.7f, 0.5f);
	glutSolidSphere(0.5, 25, 25);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -9.5, 0);
	glRotatef(legrotleft, 1, 0, 0);
	glTranslatef(0, 9.5, 0);


	glPushMatrix();
	glTranslatef(-1, -9.5, 0.3);
	glRotated(-90, 1, 0, 0);
	cylinder(0.3, 0.3, 2, 0.4, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, -11.5, 0.3);
	glRotated(-90, 1, 0, 0);
	cylinder(0.3, 0.3, 2, 0.4, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, -11.8, 0.8);
	glColor3f(0.9f, 0.7f, 0.5f);
	glScaled(1, 1, 2);
	glutSolidCube(0.8);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -9.5, 0);
	glRotatef(legrotright, 1, 0, 0);
	glTranslatef(0, 9.5, 0);


	glPushMatrix();
	glTranslatef(1, -9.5, 0.3);
	glRotated(-90, 1, 0, 0);
	cylinder(0.3, 0.3, 2, 0.4, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -11.5, 0.3);
	glRotated(-90, 1, 0, 0);
	cylinder(0.3, 0.3, 2, 0.4, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -11.8, 0.8);
	glColor3f(0.9f, 0.7f, 0.5f);
	glScaled(1, 1, 2);
	glutSolidCube(0.8);
	glPopMatrix();

	glPopMatrix();



	glPopMatrix();

}

void flower() {
	glPushMatrix();
	glTranslated(0, -2, 0);
	glRotated(-90, 1, 0, 0);
	cylinder(0.1, 0.1, 8, 0.4, 0.4, 0.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 5.2, 0);
	glColor3f(0.9f, 0.9f, 0.0f);
	glutSolidSphere(1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5, 5, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.5, 5, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 5, 0.5);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 5, -0.5);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2, 0);
	glRotated(90, 0, 1, 0);
	glColor3f(0.4f, 0.4f, 0.0f);
	glutSolidCone(0.5, 3, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2, 0);
	glRotated(-90, 0, 1, 0);
	glColor3f(0.4f, 0.4f, 0.0f);
	glutSolidCone(0.5, 3, 25, 25);
	glPopMatrix();


}

void swing() {
	glPushMatrix();
	glTranslated(6, 1.1, 3.5);
	glRotated(-20, 1, 0, 0);
	glRotated(-90, 1, 0, 0);
	cylinder(0.4, 0.4, 10, 0, 0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6, 1.1, -3.5);
	glRotated(20, 1, 0, 0);
	glRotated(-90, 1, 0, 0);
	cylinder(0.4, 0.4, 10, 0, 0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-6, 1.1, 3.5);
	glRotated(-20, 1, 0, 0);
	glRotated(-90, 1, 0, 0);
	cylinder(0.4, 0.4, 10, 0, 0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-6, 1.1, -3.5);
	glRotated(20, 1, 0, 0);
	glRotated(-90, 1, 0, 0);
	cylinder(0.4, 0.4, 10, 0, 0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6.4, 10.4, 0);
	glRotated(-90, 0, 1, 0);
	cylinder(0.4, 0.4, 12.8, 0, 1, 0);
	glPopMatrix();


	glPushMatrix();
	glTranslated(6.2, 5.4, -1.7);
	cylinder(0.4, 0.4, 3.4, 0, 1, 0.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-6.2, 5.4, -1.7);
	cylinder(0.4, 0.4, 3.4, 0, 1, 0.0);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, 10.4, 0);
	glRotatef(swingrot, 1, 0, 0);
	glTranslatef(0, -10.4, 0);

	glPushMatrix();
	glTranslated(-2, 10.4, 0);
	glRotated(90, 1, 0, 0);
	cylinder(0.1, 0.1, 6, 0.9, 0.5, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, 10.4, 0);
	glRotated(90, 1, 0, 0);
	cylinder(0.1, 0.1, 6, 0.9, 0.5, 0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.9, 0.5, 0);
	glTranslated(0, 4.5, 0);
	glScaled(4.5, 0.1, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

void bench() {
	glPushMatrix();
	glColor3f(0.9, 0.5, 0);
	glTranslated(0, 4.5, 0);
	glScaled(12, 0.5, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.9, 0.5, 0);
	glTranslated(0, 4.5, 3.5);
	glScaled(12, 0.5, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.9, 0.5, 0);
	glTranslated(0, 5.25, -2.5);
	glRotated(-90, 1, 0, 0);
	glScaled(12, 0.5, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.9, 0.5, 0);
	glTranslated(0, 8.25, -2.5);
	glRotated(-90, 1, 0, 0);
	glScaled(12, 0.5, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6.2, 9.2, -2.4);
	glRotatef(90, 1, 0, 0);
	cylinder(0.3, 0.3, 10, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-6.2, 9.2, -2.4);
	glRotatef(90, 1, 0, 0);
	cylinder(0.3, 0.3, 10, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6.2, 4.4, -2.3);
	cylinder(0.3, 0.3, 7, 0, 0, 0);
	glPopMatrix();


	glPushMatrix();
	glTranslated(-6.2, 4.4, -2.3);
	cylinder(0.3, 0.3, 7, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6.2, 4.4, 4.4);
	glRotatef(90, 1, 0, 0);
	cylinder(0.3, 0.3, 5, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-6.2, 4.4, 4.4);
	glRotatef(90, 1, 0, 0);
	cylinder(0.3, 0.3, 5, 0, 0, 0);
	glPopMatrix();
}

void tree() {

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	cylinder(1, 1, 8, 0.5, 0.3, 0.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1.8, 0);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1.8, 1);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1.8, -1);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();


	glPushMatrix();
	glTranslated(1, 1.8, 0);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, 1.8, 0);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0, 1.8, 2);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1.8, -2);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();


	glPushMatrix();
	glTranslated(2, 1.8, 0);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2, 1.8, 0);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0, 1.8, 0);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2.8, 1);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 2.8, -1);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();


	glPushMatrix();
	glTranslated(1, 2.8, 0);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, 2.8, 0);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 3.8, 0);
	glColor3f(0.3f, 0.5f, 0.2f);
	glutSolidSphere(2, 25, 25);
	glPopMatrix();
}

void buildgrass() {
	float x = -274.5;
	while (x <= 274.5) {
		float z = -224.5;
		while (z <= 224.5) {
			glPushMatrix();
			glColor3f(0.1, 0.2, 0.1);
			glTranslatef(x, 5, z);
			glRotatef(90, 1, 0, 0);
			glutWireCone(20, 2, 25, 25);
			glPopMatrix();
			z = z + 21;
		}
		x = x + 21;
	}
}

void buildfence() {
	glPushMatrix();
	glTranslatef(0, 105, -230);
	glRotatef(90, 1, 0, 0);
	cylinder(5, 5, 100, fencecolor1r, fencecolor1g, fencecolor1b);
	glPopMatrix();

	glPushMatrix();
	glColor3f(fencecolor2r, fencecolor2g, fencecolor2b);
	glTranslatef(0, 110, -230);
	glutSolidSphere(7, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-137.5, 105, -230);
	glRotatef(90, 1, 0, 0);
	cylinder(5, 5, 100, fencecolor1r, fencecolor1g, fencecolor1b);
	glPopMatrix();

	glPushMatrix();
	glColor3f(fencecolor2r, fencecolor2g, fencecolor2b);
	glTranslatef(-137.5, 110, -230);
	glutSolidSphere(7, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(137.5, 105, -230);
	glRotatef(90, 1, 0, 0);
	cylinder(5, 5, 100, fencecolor1r, fencecolor1g, fencecolor1b);
	glPopMatrix();

	glPushMatrix();
	glColor3f(fencecolor2r, fencecolor2g, fencecolor2b);
	glTranslatef(137.5, 110, -230);
	glutSolidSphere(7, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-275, 72, -230);
	glRotatef(90, 0, 1, 0);
	cylinder(3, 3, 550, fencecolor2r, fencecolor2g, fencecolor2b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-275, 39, -230);
	glRotatef(90, 0, 1, 0);
	cylinder(3, 3, 550, fencecolor2r, fencecolor2g, fencecolor2b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-279, 105, 70);
	glRotatef(90, 1, 0, 0);
	cylinder(5, 5, 100, fencecolor1r, fencecolor1g, fencecolor1b);
	glPopMatrix();

	glPushMatrix();
	glColor3f(fencecolor2r, fencecolor2g, fencecolor2b);
	glTranslatef(-279, 110, 70);
	glutSolidSphere(7, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-279, 105, -80);
	glRotatef(90, 1, 0, 0);
	cylinder(5, 5, 100, fencecolor1r, fencecolor1g, fencecolor1b);
	glPopMatrix();

	glPushMatrix();
	glColor3f(fencecolor2r, fencecolor2g, fencecolor2b);
	glTranslatef(-279, 110, -80);
	glutSolidSphere(7, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-279, 72, -225);
	cylinder(3, 3, 450, fencecolor2r, fencecolor2g, fencecolor2b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-279, 39, -225);
	cylinder(3, 3, 450, fencecolor2r, fencecolor2g, fencecolor2b);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(279, 105, 70);
	glRotatef(90, 1, 0, 0);
	cylinder(5, 5, 100, fencecolor1r, fencecolor1g, fencecolor1b);
	glPopMatrix();

	glPushMatrix();
	glColor3f(fencecolor2r, fencecolor2g, fencecolor2b);
	glTranslatef(279, 110, 70);
	glutSolidSphere(7, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(279, 105, -80);
	glRotatef(90, 1, 0, 0);
	cylinder(5, 5, 100, fencecolor1r, fencecolor1g, fencecolor1b);
	glPopMatrix();

	glPushMatrix();
	glColor3f(fencecolor2r, fencecolor2g, fencecolor2b);
	glTranslatef(279, 110, -80);
	glutSolidSphere(7, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(279, 72, -225);
	cylinder(3, 3, 450, fencecolor2r, fencecolor2g, fencecolor2b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(279, 39, -225);
	cylinder(3, 3, 450, fencecolor2r, fencecolor2g, fencecolor2b);
	glPopMatrix();
}

void generategoal() {
	if (entered == false) {
		srand(time(0));
		goalx[0] = (rand() % 265) - 265;
		goalx[1] = (rand() % 265);
		goalz[0] = (rand() % 220) - 220;
		goalz[1] = (rand() % 220);

		goalxu = goalx[rand() % 2];
		goalzu = goalz[rand() % 2];

		if (dogposx < goalxu + 30 && dogposx > goalxu - 30 && dogposz < goalzu + 30 && dogposz > goalzu - 30) {
			while (dogposx < goalxu + 30 && dogposx > goalxu - 30 && dogposz < goalzu + 30 && dogposz > goalzu - 30) {
				srand(time(0));
				goalx[0] = (rand() % 265) - 265;
				goalx[1] = (rand() % 265);
				goalz[0] = (rand() % 220) - 220;
				goalz[1] = (rand() % 220);

				goalxu = goalx[rand() % 2];
				goalzu = goalz[rand() % 2];
			}
		}
		entered = true;
	}
}

void spe(int key, int x, int y) {
	if (gameend == false && timerup == false) {
		if (key == GLUT_KEY_RIGHT) {
			if (dogposx < 240) {
				dogx += 2;
				dogangle = 90;
				if (legrotright >= 10) {
					rightlegreached = true;
				}
				if (legrotright <= -10) {
					rightlegreached = false;
				}
				if (rightlegreached == false) {
					legrotright += 1;
				}
				else {
					legrotright -= 1;
				}
				if (legrotleft >= 10) {
					leftlegreached = false;
				}
				if (legrotleft <= -10) {
					leftlegreached = true;
				}
				if (leftlegreached == false) {
					legrotleft -= 1;
				}
				else {
					legrotleft += 1;
				}



				if (armrotleft >= 10) {
					leftarmreached = false;
				}
				if (armrotleft <= -10) {
					leftarmreached = true;
				}
				if (leftarmreached == false) {
					armrotleft -= 1;
				}
				else {
					armrotleft += 1;
				}
				if (armrotright >= 10) {
					rightarmreached = true;
				}
				if (armrotright <= -10) {
					rightarmreached = false;
				}
				if (rightarmreached == false) {
					armrotright += 1;
				}
				else {
					armrotright -= 1;
				}


			}
			else {
				PlaySound(TEXT("sounds/bruh.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
		}
		if (key == GLUT_KEY_LEFT) {
			if (dogposx > -240) {
				dogx -= 2;
				dogangle = -90;
				if (legrotright >= 10) {
					rightlegreached = true;
				}
				if (legrotright <= -10) {
					rightlegreached = false;
				}
				if (rightlegreached == false) {
					legrotright += 1;
				}
				else {
					legrotright -= 1;
				}
				if (legrotleft >= 10) {
					leftlegreached = false;
				}
				if (legrotleft <= -10) {
					leftlegreached = true;
				}
				if (leftlegreached == false) {
					legrotleft -= 1;
				}
				else {
					legrotleft += 1;
				}


				if (armrotleft >= 10) {
					leftarmreached = false;
				}
				if (armrotleft <= -10) {
					leftarmreached = true;
				}
				if (leftarmreached == false) {
					armrotleft -= 1;
				}
				else {
					armrotleft += 1;
				}
				if (armrotright >= 10) {
					rightarmreached = false;
				}
				if (armrotright <= -10) {
					rightarmreached = true;
				}
				if (rightarmreached == false) {
					armrotright -= 1;
				}
				else {
					armrotright += 1;
				}
			}
			else {
				PlaySound(TEXT("sounds/bruh.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
		}
		if (key == GLUT_KEY_UP) {
			if (dogposz > -205) {
				dogz -= 2;
				dogangle = 180;
				if (legrotright >= 15) {
					rightlegreached = true;
				}
				if (legrotright <= -15) {
					rightlegreached = false;
				}
				if (rightlegreached == false) {
					legrotright += 1;
				}
				else {
					legrotright -= 1;
				}
				if (legrotleft >= 15) {
					leftlegreached = false;
				}
				if (legrotleft <= -15) {
					leftlegreached = true;
				}
				if (leftlegreached == false) {
					legrotleft -= 1;
				}
				else {
					legrotleft += 1;
				}


				if (armrotleft >= 10) {
					leftarmreached = false;
				}
				if (armrotleft <= -10) {
					leftarmreached = true;
				}
				if (leftarmreached == false) {
					armrotleft -= 1;
				}
				else {
					armrotleft += 1;
				}
				if (armrotright >= 10) {
					rightarmreached = false;
				}
				if (armrotright <= -10) {
					rightarmreached = true;
				}
				if (rightarmreached == false) {
					armrotright -= 1;
				}
				else {
					armrotright += 1;
				}
			}
			else {
				PlaySound(TEXT("sounds/bruh.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
		}
		if (key == GLUT_KEY_DOWN) {
			if (dogposz < 205) {
				dogz += 2;
				dogangle = 0;
				if (legrotright >= 15) {
					rightlegreached = true;
				}
				if (legrotright <= -15) {
					rightlegreached = false;
				}
				if (rightlegreached == false) {
					legrotright += 1;
				}
				else {
					legrotright -= 1;
				}
				if (legrotleft >= 15) {
					leftlegreached = false;
				}
				if (legrotleft <= -15) {
					leftlegreached = true;
				}
				if (leftlegreached == false) {
					legrotleft -= 1;
				}
				else {
					legrotleft += 1;
				}


				if (armrotleft >= 10) {
					leftarmreached = false;
				}
				if (armrotleft <= -10) {
					leftarmreached = true;
				}
				if (leftarmreached == false) {
					armrotleft -= 1;
				}
				else {
					armrotleft += 1;
				}
				if (armrotright >= 10) {
					rightarmreached = false;
				}
				if (armrotright <= -10) {
					rightarmreached = true;
				}
				if (rightarmreached == false) {
					armrotright -= 1;
				}
				else {
					armrotright += 1;
				}
			}
			else {
				PlaySound(TEXT("sounds/bruh.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
		}
		glutPostRedisplay();
	}
}

void key(unsigned char key, int x, int y) {
	if (key == 'l') {
		if (flowerrot  >= 100) {
			flowerarr = true;
		}
		if (flowerrot <= 0) {
			flowerarr = false;
		}
		if (flowerarr == false) {
			flowerrot += 10;
		}
		else {
			flowerrot -= 10;
		}
		PlaySound(TEXT("sounds/swoosh.wav"), NULL, SND_FILENAME | SND_ASYNC);
		glutPostRedisplay();
	}
	if (key == 'r') {
		if (treesca >= 2) {
			treearr = true;
		}
		if (treesca <= 0.1) {
			treearr = false;
		}
		if (treearr == false) {
			treesca += 0.1;
		}
		else {
			treesca -= 0.1;
		}
		PlaySound(TEXT("sounds/shrink.wav"), NULL, SND_FILENAME | SND_ASYNC);
		glutPostRedisplay();
	}
	if (key == 'b') {
		if (benchtra >= 4) {
			bencharr = true;
		}
		if (benchtra <= -4) {
			bencharr = false;
		}
		if (bencharr == false) {
			benchtra += 0.5;
		}
		else {
			benchtra -= 0.5;
		}
		PlaySound(TEXT("sounds/bench.wav"), NULL, SND_FILENAME | SND_ASYNC);
		glutPostRedisplay();
	}
	if (key == 'w') {
		if (swingrot >= 50) {
			swingarr = false;
		}
		if (swingrot <= -50) {
			swingarr = true;
		}
		if (swingarr == false) {
			swingrot -= 5;
		}
		else {
			swingrot += 5;
		}
		PlaySound(TEXT("sounds/swing.wav"), NULL, SND_FILENAME | SND_ASYNC);
		glutPostRedisplay();
	}
	if (key == 't') {
		eyex = 0.0;
		eyey = 359.0;
		glutPostRedisplay();
	}
	if (key == 'f') {
		eyex = 0.0;
		eyey = 0.0;
		glutPostRedisplay();
	}
	if (key == 's') {
		eyex = 100.0;
		eyey = 0.0;
		glutPostRedisplay();
	}
	if (key == 'o') {
		eyex = 0.0;
		eyey = 0.1;
		glutPostRedisplay();
	}
}

void keyup(unsigned char key, int x, int y) {
	swingrot = 0;
	flowerrot = 0;
	benchtra = 0;
	treesca = 1;
	dogangle = 0;
	 flowerarr = false;
	 swingarr = false;
	 bencharr = false;
	 treearr = false;
}


void keyupmove(int key, int x, int y) {
	if (gameend == false) {
		dogangle = 0;
		legrotleft = 0;
		legrotright = 0;
		rightlegreached = false;
		leftlegreached = false;
		armrotleft = 0;
		armrotright = 0;
		rightarmreached = false;
		leftarmreached = false;
	}

}

void fencetimer(int value) {
	fencecolor1r = rand() / double(RAND_MAX);
	fencecolor1g = rand() / double(RAND_MAX);
	fencecolor1b = rand() / double(RAND_MAX);
	fencecolor2r = rand() / double(RAND_MAX);
	fencecolor2g = rand() / double(RAND_MAX);
	fencecolor2b = rand() / double(RAND_MAX);

	glutTimerFunc(2000, fencetimer, 0);

}

void print(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void endgame() {
	exit(0);
}

void gamewin(int val) {
	endgame();
}

void print2(int x,int y,int z, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos3f(x, y, z);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void gametimer(int val) {
	if (gameend == false) {
		timerup = true;
	}
	glutPostRedisplay();
}


void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (gameend == false && !timerup) {

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eyex, eyey, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

		glPushMatrix();
		glTranslatef(0, 0, -100);
		dogposx = 0;
		dogposz = 180;

		glPushMatrix();
		glColor3f(1, 1, 0);
		glScaled(550, 5, 450);
		glutSolidCube(1);
		glPopMatrix();



		buildgrass();

		buildfence();




		glPushMatrix();
		glTranslated(dogx, 0, dogz);
		dog(10, 10, 10, dogposx, 180);
		dogposx = dogposx + dogx;
		dogposz = dogposz + dogz;
		glPopMatrix();

		generategoal();
		glPushMatrix();
		glTranslatef(goalxu, 15, goalzu);
		glColor3f(1, 0, 0);
		glutSolidSphere(10, 25, 25);
		if (dogposx < goalxu + 30 && dogposx > goalxu - 30 && dogposz < goalzu + 30 && dogposz > goalzu - 30) {
			gameend = true;
			glutPostRedisplay();
		}
		glPopMatrix();



		glPushMatrix();
		glScalef(9, 9, 9);
		glTranslatef(23, -1, -10);
		glRotatef(-45, 0, 1, 0);
		swing();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(benchtra, 0, 0);
		glTranslatef(-200, 3, -150);
		glRotatef(45, 0, 1, 0);
		glScalef(9, 7, 9);
		bench();
		glPopMatrix();

		glPushMatrix();
		glScalef(7, 4, 7);
		glRotatef(45, 0, 1, 0);
		glTranslatef(10, 3, -20);
		glRotatef(flowerrot, 0, 1, 0);
		flower();
		glPopMatrix();

		glPushMatrix();
		glScalef(1, treesca, 1);
		glScalef(15, 10, 15);
		glTranslatef(5, 8, -10);
		tree();
		glPopMatrix();

		glPushMatrix();
		glScalef(7, 4, 7);
		glRotatef(45, 0, 1, 0);
		glTranslatef(10, 3, 40);
		glRotatef(flowerrot, 0, 1, 0);
		flower();
		glPopMatrix();

		glPushMatrix();
		glScalef(1, treesca, 1);
		glScalef(15, 10, 15);
		glTranslatef(-13, 8, 10);
		tree();
		glPopMatrix();

		glPopMatrix();


		glPushMatrix();
		glColor3f(0, 0, 0);
		char* pos[20];
		sprintf((char*)pos, "Time: %d", gametime);
		print2(160, 345, 150, (char*)pos);
		glPopMatrix();


		glutSpecialFunc(spe);

		glFlush();
	}
	else if (gameend && !timerup ) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 0.1, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		dogangle = 0;
		glPushMatrix();
		dog(20, 20, 20, -230, 0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(230, 15, 0);
		glTranslatef(0, 0, -3);
		glRotatef(ballrot, 0, 1, 0);
		glTranslatef(0, 0, 3);
		glColor3f(1, 0, 0);
		glutSolidSphere(50, 25, 25);
		glPopMatrix();

		
		glPushMatrix();
		glColor3f(0, 0, 0);
		char* p0s[20];
		sprintf((char*)p0s, "congratulations!");
		print(-100, 100, (char*)p0s);
		glPopMatrix();
		glPushMatrix();
		glColor3f(0, 0, 0);
		char* pos[20];
		sprintf((char*)pos, "Doggo found his ball!");
		print(-100, 80, (char*)pos);
		glPopMatrix();
		glFlush();
		glutTimerFunc(5000, gamewin, 0);
		
	}
	 if (timerup ) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0, 0.1, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glPushMatrix();
		dog(20, 20, 20, -230, 0);
		glPopMatrix();


		glPushMatrix();
		glColor3f(0, 0, 0);
		char* p0s[20];
		sprintf((char*)p0s, "Doggo didn't find his ball!");
		print(-100, 100, (char*)p0s);
		glPopMatrix();
		glPushMatrix();
		glColor3f(0, 0, 0);
		char* pos[20];
		sprintf((char*)pos, "try again!");
		print(-100, 80, (char*)pos);
		glPopMatrix();


		glFlush();
		glutTimerFunc(5000, gamewin, 0);
	}



}

void Anim() {
	if (gameend == true) {
		armwinrot += 1;
		if (bodywinrot >= 25) {
			bodywinreached = true;
		}
		if (bodywinrot <= -25) {
			bodywinreached = false;
		}
		if (bodywinreached == false) {
			bodywinrot += 0.05;
		}
		else {
			bodywinrot -= 0.05;
		}


		if (legrotright >= 15) {
			rightlegreached = true;
		}
		if (legrotright <= -15) {
			rightlegreached = false;
		}
		if (rightlegreached == false) {
			legrotright += 0.1;
		}
		else {
			legrotright -= 0.1;
		}
		if (legrotleft >= 15) {
			leftlegreached = false;
		}
		if (legrotleft <= -15) {
			leftlegreached = true;
		}
		if (leftlegreached == false) {
			legrotleft -= 0.1;
		}
		else {
			legrotleft += 0.1;
		}

		ballrot += 1;

	}
	if (timerup == true) {
		if (dogshakeheadrot >= 25) {
			dogshakeheadarr = true;
		}
		if (dogshakeheadrot <= -25) {
			dogshakeheadarr = false;
		}
		if (dogshakeheadarr == false) {
			dogshakeheadrot += 0.1;
		}
		else {
			dogshakeheadrot -= 0.1;
		}
	}
	glutPostRedisplay();
}

void countdown(int val) {
	gametime -= 1;
	glutPostRedisplay();
	glutTimerFunc(1000, countdown, 0);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(700, 700);
	glutInitWindowPosition(350, 0);

	glutCreateWindow("OpenGL - 3D Template");
	glutDisplayFunc(Display);
	glutIdleFunc(Anim);
	glutKeyboardFunc(key);
	glutKeyboardUpFunc(keyup);
	glutSpecialUpFunc(keyupmove);
	glutTimerFunc(2000, fencetimer, 0);
	glutTimerFunc(gametime * 1000, gametimer, 0);
	glutTimerFunc(1000, countdown, 0);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(50.0f, 700 / 700, -200.0f, 200.0f);
	glOrtho(-360, 360, -160, 360, -360, 360);



	glutMainLoop();
}
