#include <rendering/Renderer.h>

#include <glm/glm.hpp>// for testing the camera
#include <glm/gtc/matrix_transform.hpp>

Renderer::Renderer (void) 
{
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, 960.f/544.0f, 0.01f, 100.0f);
}

Renderer::~Renderer (void) {}

void Renderer::setClearColor (Color color)
{
    glm::vec4 normalizedColors = color.normalize();
    glClearColor(normalizedColors.r, normalizedColors.g, normalizedColors.b, normalizedColors.a);
}

void Renderer::clear (void)
{   
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::swap (void)
{
    vglSwapBuffers(GL_FALSE);
}

void Renderer::draw (RenderObject & object)
{
    glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

    glm::mat4 viewMatrix = glm::lookAt( glm::vec3(0.0f, 0.0f, -1.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f) );
    glm::mat4 modelMatrix = object.getModelMatrix();
    glm::mat4 modelViewMatrix = viewMatrix * modelMatrix;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glLoadMatrixf(&modelViewMatrix[0][0]);

    glVertexPointer(object.getVertexStride(), GL_FLOAT, 0, object.getLocalVertices());
	glColorPointer(object.getColorStride(), GL_FLOAT, 0, object.getVertexColors());
	glDrawArrays(GL_TRIANGLES, 0, object.getTotalVertices());
	
    glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}