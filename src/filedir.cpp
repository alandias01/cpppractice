#include "filedir.h"

filedir::filedir()
{
}

filedir::~filedir()
{
}

void filedir::showFilesInDir()
{
	DIR * pdir = NULL;
	pdir = opendir(".");

	struct dirent *pent = NULL;


	if (pdir == NULL)
	{
		cout << "/nERROR! pdir couldn't be initialized correctly" << endl;
		exit(1);
	}

	while (pent = readdir(pdir))//while there is still something in the directory to list
	{
		if (pent == NULL)
		{
			cout << "\nERROR, pent couln't be initialized correctly" << endl;
			exit(3);
		}
		printf("%s\n", pent->d_name);
		//cout << pent->d_name << endl;
	}
	closedir(pdir);
}

