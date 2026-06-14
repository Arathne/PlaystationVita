#include <psp2/kernel/processmgr.h>

#include "src/States/StateManager.h"
#include "src/GameRenderer.h"
#include "src/Input.h"

int main()
{
	while (true)
	{
		Input::poll();
		StateManager::process();
	}

	sceKernelExitProcess(0);
}
