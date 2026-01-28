#include <psp2/kernel/processmgr.h>
#include <controllers/TestController.h>
#include <controllers/IoCreationController.h>

#include <vitaGL.h>
#include <rendering/Triangle.h>
#include <rendering/Renderer.h>
#include <rendering/Color.h>

int main ()
{ 
    IoCreationController::createDirectory(DATA_FOLDER);

    #ifdef DEVELOPER_MODE
        TestController* tests = new TestController();
        tests -> runAllTests();
        delete tests;
    #endif



    vglInit(0x800000);

	Triangle triangle(Color(0, 255, 0));
	Renderer renderer;

	renderer.setClearColor(Color(0,0,0));
	
	Transform* transform = &triangle.getTransform();//.setScale(glm::vec3(500, 500, 500));
	transform -> setRotationY(45);
	//transform -> setScale(glm::vec3(5, 5, 0.1));
	//transform -> setPosition(glm::vec3(0, 0, 0));
	

	for (;;){
		renderer.clear();
		renderer.draw(triangle);
		renderer.swap();
	}
	
	vglEnd();

    sceKernelExitProcess(0);
}