#include "ctdl.h"
#include "dohoa.h"
#include "xuli.h"
#include "data.h"
#include "xulimenudong.h"
#include "menudong.h"


using namespace std;

int main()
{
	DSDauSach dsds;
	DSDocGia dsdg;
	Init(dsds, dsdg);

	while (true)
	{
		Run(dsdg, dsds);
	}
	
	getch();
}
