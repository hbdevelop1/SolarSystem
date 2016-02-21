
#include "Root.h"
#include "Menu.h"
 
#include "hevent.h"



namespace Event
{
listType listofeventHandlers;


void Handle(int event_nbr, bool b)
{
	listType::iterator it=listofeventHandlers.find(event_nbr);
	if(it != listofeventHandlers.end())
	{
		switch (event_nbr)
		{
		case event_pause:
			Event1<void, Root, bool> * e = (Event1<void, Root, bool> *) ((*it).second);
			(*e)(b);
			break;
		}

	}
}

void Handle(int event_nbr, int b, int c)
{
	listType::iterator it=listofeventHandlers.find(event_nbr);
	if(it != listofeventHandlers.end())
	{
		switch (event_nbr)
		{
		case event_click:
			Event2<void, Menu, int> * e = (Event2<void, Menu, int> *) ((*it).second);
			(*e)(b,c);
			break;
			
		}

	}
}


void Handle(int event_nbr)
{
	listType::iterator it=listofeventHandlers.find(event_nbr);
	if(it != listofeventHandlers.end())
	{
		switch (event_nbr)
		{
		case event_quit:
			Event0 * e = (Event0 *) ((*it).second);
			(*e)();
			break;
		}

	}
}


void RegisterHandler(int num_event,void (*f)())
{
	Event0 * e= new Event0;
	e->m_o = NULL;
	e->m_f = f;


	listType::value_type p(num_event,e);
	listofeventHandlers.insert(p);


}


void UnRegisterHandler(int event_nbr)
{
	listType::iterator it=listofeventHandlers.find(event_nbr);
	if(it != listofeventHandlers.end())
	{
		switch (event_nbr)
		{
		case event_quit:
			{
			Event0 * e = (Event0 *) ((*it).second);
			delete e;
			break;
			}
		case event_pause:
			{
			Event1<void, Root, bool> * e = (Event1<void, Root, bool> *) ((*it).second);
			delete e;
			break;
			}
		case event_click:
			{
			Event2<void, Menu, int> * e = (Event2<void, Menu, int> *) ((*it).second);
			delete e;
			break;
			}

		}

	}

}


}