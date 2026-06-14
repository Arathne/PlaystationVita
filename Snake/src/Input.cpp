#include "Input.h"

/* STATIC */

Input Input::instance;

void Input::poll (void)
{
	instance.previous_ = instance.data_;
	sceCtrlPeekBufferPositive(0, &instance.data_, 1);	
}

bool Input::began (SceCtrlButtons button)
{
	if (instance.data_.buttons == button && !(instance.previous_.buttons == button))
		return true;

	return false;
}

bool Input::ended (SceCtrlButtons button)
{
	if (!(instance.data_.buttons == button) && instance.previous_.buttons == button)
		return true;

	return false;
}

bool Input::active (SceCtrlButtons button)
{
	if (instance.data_.buttons == button)
		return true;

	return false;
}

/* INSTANCE */

Input::Input (void)
{
	sceCtrlSetSamplingMode(SCE_CTRL_MODE_DIGITAL);
}

Input::~Input (void) {}
