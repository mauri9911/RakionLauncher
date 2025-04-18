#include "LaunchFrm.h"

using namespace GameLaunch;
using namespace System::Windows::Forms;



void main()
{

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew LaunchFrm);

}