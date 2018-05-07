#include <stdlib.h>
#include <GL/glut.h>
void update_display(void);
void key_handler(unsigned char key, int x, int y);
int main(int argc, char **argv) {
/* glutInit() initializes the library and handles window-
* system specific initialization. It may intercept some
* command line args that glut recognizes and remove them
* from the array.
*/
glutInit(&argc, argv);
/* set the size of the window that will be created by
* the call to glutCreateWindow() further on.
*/
glutInitWindowSize(800, 600) 2;
/* specify display mode, some usefull flags are:
* GLUT_DOUBLE: use double buffering
* GLUT_DEPTH: provide a depth buffer (Z-buffer)
* GLUT_STENCIL: provide a stencil buffer
*/
glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL);
/* create the actual window with the specified title */
glutCreateWindow("GLUT test");
/* specify a function to be called when glut needs to
* redraw the window.
*/
glutDisplayFunc(update_display);
/* specify a function to handle keyboard events */
glutKeyboardFunc(key_handler);
/* specify a function to be called when idle
* (i.e. no other events are to be handled)
* */
glutIdleFunc(update_display);
/* do some usual OpenGL setup */
glEnable(GL_DEPTH_TEST);
glEnable(GL_CULL_FACE);
glFrontFace(GL_CW);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glMatrixMode(GL_PROJECTION);
gluPerspective(45.0, 1.3333, 1.0, 1000.0);
/* enter glut main event loop, this will call the
* callbacks we provided on various events and never
* return, it will exit when the window is closed by
* calling exit(), so if we want to perform any
* cleanup before the program exits, we can use
* atexit() to register a cleanup function.
*/
glutMainLoop();
return 0;
}
/* This is the function we gave to glut as display and
* idle callback it will be called whenever glut needs to
* update the display and when it has nothing else to do.
* Usual OpenGL frame drawing should go in here.
*/
void update_display(void) {
glClearColor(0.0, 0.0, 0.0, 0.0);
glClearDepth(1.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0, 0, -4);
glRotatef(35.0, 1.0, 1.0, 0.0);
/* glutSolidTeapot() draws a typical Utah Teapot */
glutSolidTeapot(1.0);
/* glutSwapBuffers() shows the back buffer */
glutSwapBuffers();
}
/* this is our keyboard callback, first argument is the
* key that was pressed, next two arguments are the current
* mouse position
*/
void key_handler(unsigned char key, int x, int y) {
if(key == 27) {
exit(0);
}
}
