
#include "precomp.h"
#include "program.h"
#include <ClanLib/application.h>

using namespace clan;

Application clanapp(&Program::main);

bool Program::exit = false;

void Program::exit_func()
{
	exit = true;
}

int Program::main(const std::vector<std::string> &args)
{
	SetupCore setup_core;
	SetupDisplay setup_display;
	SetupGL setup_gl;

	try
	{
		DisplayWindow window("Hello ShaderEffect", 800, 600, false, true);
		Slot slot = window.sig_window_close().connect(&Program::exit_func);

		GraphicContext gc = window.get_gc();
		InputContext ic = window.get_ic();

		while (!exit)
		{
			gc.clear();

			window.flip(0);
			KeepAlive::process();
		}
	}
	catch (Exception &e)
	{
		Console::write_line("Unhandled exception: %1", e.get_message_and_stack_trace());
		return -1;
	}

	return 0;
}