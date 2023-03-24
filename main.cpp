#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

const GLint WIDTH = 650;
const GLint HEIGHT = 650;

const GLint message1X = 225;
const GLint message1Y = 100;

const GLint nameX = 225;
const GLint nameY = 200;

const GLint message2X = 235;
const GLint message2Y = 400;

const GLint ageX = 225;
const GLint ageY = 450;

const GLint validMessageX = 225;
const GLint validMessageY = 500;


const char* message1 = "¿Cual es tu nombre?";
const char* message2 = "¿Cual es tu edad?";
const char* validMessage;


std::string name;
std::string age;

bool inputName = true;
bool inputAge = false;
bool drawHappyFace;
bool drawMadFace;


void DrawEyes(){
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 30; i++){
        float theta = 2.0f * M_PI * float(i) / 30.0f;
        float x = 10.0f * cosf(theta);
        float y = 10.0f * sinf(theta);
        glVertex2f(100 + x, 500 + y);
    }
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 30; i++){
        float theta = 2.0f * M_PI * float(i) / 30.0f;
        float x = 10.0f * cosf(theta);
        float y = 10.0f * sinf(theta);
        glVertex2f(50 + x, 500 + y);
    }
    glEnd();
}

void DrawHappyFace(){

    DrawEyes();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(50.0f, 550.0f);
    glVertex2f(100.0f, 550.0f);
    glVertex2f(75.0f, 600.0f);
    glEnd();

}

void DrawMadFace(){

    DrawEyes();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(50.0f, 455.0f);
    glVertex2f(75.0f, 470.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(100.0f, 455.0f);
    glVertex2f(75.0f, 470.0f);
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(50.0f, 550.0f);
    glVertex2f(100.0f, 550.0f);
    glEnd();

}


void display() {
    glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(message1X, message1Y);

    for(const char* c = message1; *c != '\0'; ++c){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(nameX, nameY);

    const char* name_c = name.c_str();

    for(const char* c = name_c; *c != '\0'; ++c){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(message2X, message2Y);

    for(const char* c = message2; *c != '\0'; ++c){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(ageX, ageY);

    const char* age_c = age.c_str();

    for(const char* c = age_c; *c != '\0'; ++c){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }


    if(validMessage){
        glColor3f(1.0f, 1.0f, 1.0f);
        glRasterPos2i(validMessageX, validMessageY);
        for(const char* c = validMessage; *c != '\0'; ++c){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
        }

        if(drawHappyFace)
            DrawHappyFace();

        if(drawMadFace)
            DrawMadFace();

    }


    glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y){


    if(key == 13 && inputAge){
        int age_int = std::stoi(age);

        if(age_int >= 18){
            validMessage = "Felicidades! Puedes pasar.";
            drawHappyFace = true;
        } else{
            validMessage = "No puedes pasar!";
            drawMadFace = true;
        }

    }

    if(key == 13){
        inputName = false;
        inputAge = true;
    }

    if (inputName){
        name.push_back(key);
    }

    if(inputAge){
        age.push_back(key);
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("OpenGL Window");
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
