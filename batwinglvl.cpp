// Standard includes
#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>

// Graphics includes
#include "GLee.h" // No need to link to GL/gl.h
#include "glu.h"
//#include <GL/glew.h>
#include "sdl/SDL.h"
using namespace std;

// Define constants for our screen width, height, and colour depth
const GLint SCREEN_WIDTH    = 800;
const GLint SCREEN_HEIGHT   = 600;
const GLint SCREEN_BPP      = 24;

const GLfloat PI = 3.14159;

class Star; // Forward declaration for our Stars class

const GLuint NUMSTARS = 1000; // Our star count

// Create a vector of Stars
vector<Star> stars;

// Create an SDL surface
SDL_Surface* surface;

// Set initial frustrum co-ordinate system (400 across, 400 vertically, 800 deep --- i.e. -200 to 200 on each of the X, Y axis', and 1 (far) to 800 (near) on the Z axis'
GLfloat windowWidth  = 200.0f;
GLfloat windowHeight = 200.0f;
GLfloat windowDepth  = 800.0f;

// Flag to control whether we should clear the screen each frame or not (leaves trails when not)
GLboolean clearScreen = true;

// Function to get a random integer within a specified range
GLint randRange(GLint min, GLint max)
{
	GLint randomNum = min + ((int)rand() % (max-min));
	return randomNum;
}

// Class to define a Star
class Star
{
	private:
		GLfloat x;
		GLfloat y;
		GLfloat z;
		GLfloat zSpeed;
		GLfloat starSize;

		GLfloat redComponent;
		GLfloat greenComponent;
		GLfloat blueComponent;

        static const GLfloat MIN_STAR_SIZE;
		static const GLfloat MAX_STAR_SIZE;

		static const GLfloat MIN_STAR_SPEED;
		static const GLfloat MAX_STAR_SPEED;

	public:
        static GLfloat rotationAmount;
        static const GLfloat ROTATION_SPEED;

		// Getter functions
		GLfloat getX();
		GLfloat getY();
		GLfloat getZ();
		GLfloat getStarSize();

		GLfloat getRedComponent();
		GLfloat getGreenComponent();
		GLfloat getBlueComponent();

		GLvoid randomiseColour();
		GLvoid moveStar();
		GLvoid resetStar(); // Function to reset (re-randomise) star location and speed

		Star();  // Constructor declaration
};

GLfloat Star::rotationAmount = 0.0f;
const GLfloat Star::ROTATION_SPEED = 0.1f;

const GLfloat Star::MIN_STAR_SIZE = 1.0f;
const GLfloat Star::MAX_STAR_SIZE = 3.0f;

const GLfloat Star::MIN_STAR_SPEED = 1.0f;
const GLfloat Star::MAX_STAR_SPEED = 2.0f;


// Constructor implementation
Star::Star()
{
	resetStar();
}


// Getter functions...
GLfloat Star::getX()
{
	return x;
}

GLfloat Star::getY()
{
	return y;
}


GLfloat Star::getZ()
{
	return z;
}


GLfloat Star::getStarSize()
{
	return starSize;
}


GLfloat Star::getRedComponent()
{
	return redComponent;
}


GLfloat Star::getGreenComponent()
{
	return greenComponent;
}


GLfloat Star::getBlueComponent()
{
	return blueComponent;
}


// Function to assign random floating point values for the RGB components in the range 0.0f to 1.0f
GLvoid Star::randomiseColour()
{
	redComponent   = (float)rand() / (float)RAND_MAX;
	greenComponent = (float)rand() / (float)RAND_MAX;
	blueComponent  = (float)rand() / (float)RAND_MAX;
}


// Function to move the star closer and reset to far away once it gets really close
GLvoid Star::moveStar()
{
	if (z < windowDepth)
	{
		z += zSpeed;
	}
	else
	{
		z = 1.0f;
	}
}


// Function to reset a star - called either on initialisation or when the star gets to the front of our viewing frustrum
GLvoid Star::resetStar()
{
	// Set our initial locations for stars within the left/right, bottom/top and near/far of the defined frustrum
	x = (GLfloat)randRange(-windowHeight, windowWidth);
	y = (GLfloat)randRange(-windowHeight, windowHeight);
	z = (GLfloat)randRange(1, windowDepth);

        // Pick a random size between given limits. The largest size is actually (MIN_STAR_SIZE + MAX_STAR_SIZE)
        starSize = MIN_STAR_SIZE + ( (GLfloat)rand() / (GLfloat)RAND_MAX ) * MAX_STAR_SIZE;

        // Pick a random speed between given limits
	zSpeed = (GLfloat)randRange(MIN_STAR_SPEED, MAX_STAR_SPEED);

        // Pick a random colour
	randomiseColour();
}


float deg2rad(float deg)
{
    return (PI / 180.0f) * deg;
}


// Function to release/destroy our resources and restore the desktop
void quit(int returnCode)
{
    // Clean up the window...
    SDL_Quit( );

    // ...and exit appropriately
    exit(returnCode);
}


// Function to reset our viewport after a window resize
GLvoid resizeWindow(GLint width, GLint height)
{
    // Protect against a divide by zero
    if (height == 0)
    {
        height = 1;
    }

    // Height / width ratio
    GLfloat ratio = (GLfloat)width / (GLfloat)height;

    // Setup our viewport
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    // Change to the projection matrix and set our viewing volume
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* Set our perspective (POV angle, window ratio, start of viewport z, depth of items to display [if too shallow, "deep" items will not be displayed] */
    // NOTE: Both near and far values MUST be positive or it'll throw a GL_ERROR
    gluPerspective(45.0f, ratio, 1.0f, windowDepth);

    // Make sure we're changing the model view and not the projection then reset the matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Function to handle key press events
/*GLvoid handleKeyPress(SDL_keysym *keysym)
{
    switch (keysym->sym)
    {
        // Quit when Esc hit
        case SDLK_ESCAPE:
            quit(0);
            break;

        // Toggle fullscreen when F1 hit
        case SDLK_F1:
            // Hide the mouse cursor when going into full screen mode, restore it when windowed mode again
            if (SDL_ShowCursor(SDL_QUERY) == SDL_ENABLE)
            {
                SDL_ShowCursor(SDL_DISABLE);
            }
            else
            {
                SDL_ShowCursor(SDL_ENABLE);
            }

            // Toggle fullscreen
            SDL_WM_ToggleFullScreen(surface);

            break;

        default:
            break;

	} // End of switch statement

} // End of handleKeyPress function
*/

// Function to initialise some variables
GLvoid initVars()
{
    // Initialize random number seed
    srand(time(NULL));

    // Create a star, reset it, and push it onto the stars vector
    Star tempStar;
	for (uint loop = 0; loop < NUMSTARS; loop++)
	{
		tempStar.resetStar();
		stars.push_back(tempStar);
	}
}


// Function to enable and initialise some OpenGL state-machine values
void initGL()
{
    // Set the draw buffer clearing colour to black without modifying the alpha
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Actually clear the draw buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the accumulation buffer clearing colour to black without modifying the alpha
    glClearAccum(0.0f, 0.0f, 0.0f, 0.0f);

    // Actually clear the accumulation buffer
    glClear(GL_DEPTH_BUFFER_BIT);

    // Setup some black fog
    GLfloat fogColour[] = { 0.0f, 0.0f, 0.0f };
    glFogfv(GL_FOG_COLOR, fogColour);
    glFogf(GL_FOG_START, windowDepth * 0.5f); // Fog starts half-way into the full depth of the frustrum
    glFogf(GL_FOG_END, windowDepth); // Fully ends (i.e. fully fogged out) at the full window depth
    glFogi(GL_FOG_MODE, GL_LINEAR); // Simple, linear fog
    glEnable(GL_FOG);

    // Enable depth testing and specify the depth comparison function
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // Depth buffer setup - this is a value clamped between 0.0f and 1.0f and that value is used as to how far back we should clear the depth in terms
    // of the frustrum depth, so if the frustrum depth was 400, and you we're clearing to 0.5, it would clear to a depth of 200... I think!
    glClearDepth(1.0f);

    // Use best quality perspective calculations
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

} // End of initGL function

// Function to draw our scene
void drawGLScene()
{
    // These are to calculate our fps... (remember: static vars only get assigned once!)
    static GLint t0     = 0;
    static GLint frames = 0;

    // Clear the draw and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Take the contents of the current accumulation buffer and copy it to the colour buffer with each pixel multiplied by a factor
    // i.e. we clear the screen, draw the last frame again (which we saved in the accumulation buffer), then draw our stuff at its new location on top of that
    glAccum(GL_RETURN, 0.95f);

    // Clear the accumulation buffer (don't worry, we re-grab the screen into the accumulation buffer after drawing our current frame!)
    glClear(GL_ACCUM_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Translate everything into the screen (z-axis) by -windowDepth
    glTranslatef(0.0f, 0.0f, -windowDepth);

    // Apply oscillating rotation to the matrix around the Z-axis.
    // Multiplying by 100 is just a fudge factor to increase the total rotation amount
    glRotatef(cos(deg2rad(Star::rotationAmount)) * 100, 0.0f, 0.0f, 1.0f);

    vector<Star>::iterator starIter; // This needs to be a standard iterator not a constant iterator so we can modify what's being pointed to!!

    // Do the actual drawing...
    for (starIter = stars.begin(); starIter != stars.end(); starIter++)
    {
        // Change the point size to the stars size property
        glPointSize(starIter->getStarSize());

        glBegin(GL_POINTS); // This needs to be inside the loop so the PointSize change (above) takes effect

            // Set the colour
            glColor3f(starIter->getRedComponent(), starIter->getGreenComponent(), starIter->getBlueComponent());

            // Draw the point
            glVertex3f(starIter->getX(), starIter->getY(), starIter->getZ());

        glEnd();

        // Move the star closer (or reset it if it's too close) ready for the next frame
        starIter->moveStar();
    }

    // Swap the buffers so we can see what we've drawn without -watching- it being drawn
    SDL_GL_SwapBuffers();

    // Take the contents of the current draw buffer and copy it to the accumulation buffer with each pixel modified by a factor
    // The closer the factor is to 1.0f, the longer the trails... Don't exceed 1.0f - you get garbage.
    glAccum(GL_ACCUM, 0.9f);

    // Calcualate our FPS and display it in the console every five seconds
    frames++;
    {
		GLint t = SDL_GetTicks();
		if (t - t0 >= 5000)
		{
			GLfloat seconds = (t - t0) / 1000.0;
			GLfloat fps = frames / seconds;
			printf("%d frames in %g seconds = %g FPS\n", frames, seconds, fps);
			t0 = t;
			frames = 0;
		}
    }

    // Add to the star rotation for the next frame
    if (Star::rotationAmount < 360.0f)
    {
         // How quickly this value goes up will controll how quickly it rotates...
         // i.e. higher values == faster rotation
    	Star::rotationAmount += Star::ROTATION_SPEED;
    }
    else
    {
    	Star::rotationAmount = 0.0f;
    }

}

// Mainline function
int main(int argc, char **argv)
{
    // Flags to pass to SDL_SetVideoMode
    int videoFlags;

    // Main loop variable
    bool done = 0;

    // Variable to collect events
    SDL_Event event;

    // Hold some info about our display
    const SDL_VideoInfo *videoInfo;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
	    cerr << "Video initialization failed: " << SDL_GetError() << endl;
	    quit(1);
    }

    // Fetch the video info
    videoInfo = SDL_GetVideoInfo();

    if (!videoInfo)
    {
	    cerr << "Video query failed: " << SDL_GetError() << endl;
            quit(1);
    }

    // The flags to pass to SDL_SetVideoMode
    videoFlags  = SDL_OPENGL;          // Enable OpenGL in SDL
    videoFlags |= SDL_GL_DOUBLEBUFFER; // Enable double buffering
    videoFlags |= SDL_HWPALETTE;       // Store the palette in hardware
    videoFlags |= SDL_RESIZABLE;       // Enable window resizing

    // Check to see if surfaces can be stored in memory, if so then add the flag
    if (videoInfo->hw_available)
    {
        videoFlags |= SDL_HWSURFACE;
    }
    else
    {
        videoFlags |= SDL_SWSURFACE;
    }

    // Check if hardware blits can be done
    if (videoInfo->blit_hw)
    {
        videoFlags |= SDL_HWACCEL;
    }

    // Set up OpenGL double buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // Try to enable 4x antialiasing - can't really tell if it's working, so I guess it doesn't matter too much =P
    glEnable(GL_MULTISAMPLE);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1) ;
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4) ;

    // Specify accumulation buffer bits per pixel
    // Note: This must be done BEFORE the surface is initialised!
    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,   16);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,  16);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 16);

    // Get a SDL surface
    surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, videoFlags);

    // Verify there is a surface
    if (!surface)
    {
	    cerr < < "Video mode set failed: " << SDL_GetError() << endl;
	    quit(1);
    }

    // Set the window and tray caption
    SDL_WM_SetCaption("OpenGL Accumulation Buffer Trails by r3dux 21/10/2010", "OpenGL Acc. Buffer");

    // Initialise variables
    initVars();

    // Initialise OpenGL
    initGL();

    // Resize the initial window
    resizeWindow(SCREEN_WIDTH, SCREEN_HEIGHT);

    // Wait for events
    while (!done)
    {
	    // Handle the events in the queue
	    while (SDL_PollEvent(&event))
	    {
                switch(event.type)
		{

                    // Handle resize event
                    case SDL_VIDEORESIZE:
                        surface = SDL_SetVideoMode(event.resize.w, event.resize.h, SCREEN_BPP, videoFlags);
                        if (!surface)
                        {
                            cerr << "Could not get a surface after resize: " << SDL_GetError() << endl;
                            quit(1);
                        }
                        resizeWindow(event.resize.w, event.resize.h);
                        break;

                    // Handle keypress
                    /*case SDL_KEYDOWN:
                        handleKeyPress(&event.key.keysym);
                        break;*/

                    // Handle quit requests
                        case SDL_QUIT:
                        done = true;
                        break;

                    default:
                        // Nothing to see here. Move along...
                        break;

		} // End of switch statement

	} // End of while SDL_PollEvent(&event)

        // Draw the scene
        drawGLScene();

	// Cheap-as-chips delay of 16ms to put our framerate in the region of 60fps
	SDL_Delay(16);

    } // End of while !done loop

    // Clean up and exit
    quit(0);

    // Should never get here, but included for completeness...
    return(0);
}
