
#include <map>

/*
class EventsTable
{
#define max_nbr_of_events	5
	static Event s_e;
	void * eventstable[max_nbr_of_events];
	Event()	
	{
		for(int i=0; i<max_nbr_of_events;i++)
			eventstable[i]=NULL;
	}
	Event(const Event & );
	Event & operator=(Event &);
public:
	static Event & GetInstance()
	{
		return s_e;
	}
	void *GetNewEvent()
	{
		eventstable[];
	}
};
*/

namespace Event
{

enum events
{
	event_pause=1,
	event_cameraslide=2,
	event_click,
	event_quit,
};

class Event0
{
public:
	void *m_o; //todo:remove this dummy member from Event0
	void (*m_f)();

	void operator()()
	{
		(*m_f)();
	}
};

template<class Ret, class Cls, class P1> class Event1
{
public:
	Cls *m_o;
	Ret (Cls::*m_f)(P1);

	void operator()(P1 b)
	{
		(m_o->*m_f)(b);
	}
};

template<class Ret, class Cls, class P1> class Event2
{
public:
	Cls *m_o;
	Ret (Cls::*m_f)(P1,P1);

	void operator()(P1 b, P1 c)
	{
		(m_o->*m_f)(b,c);
	}
};


typedef std::map<int,void*>	listType;

extern listType listofeventHandlers;
template <class Ret,class Cls, class P1> void RegisterHandler(int num_event,Cls *o,Ret (Cls::*f)(P1, P1))
{
	Event2<Ret,Cls, P1>* e= new Event2<Ret,Cls, P1>;
	e->m_o = o;
	e->m_f = f;


	listType::value_type p(num_event,e);
	listofeventHandlers.insert(p);


//	listOfevents.insert(listOfeventsType::value_type(event_nbr,&e));

}


template <class Ret,class Cls, class P1> void RegisterHandler(int num_event,Cls *o,Ret (Cls::*f)(P1))
{
	Event1<Ret,Cls, P1>* e= new Event1<Ret,Cls, P1>;
	e->m_o = o;
	e->m_f = f;


	listType::value_type p(num_event,e);
	listofeventHandlers.insert(p);


//	listOfevents.insert(listOfeventsType::value_type(event_nbr,&e));

}


void RegisterHandler(int num_event,void (*f)());
void UnRegisterHandler(int num_event);

void Handle(int event_nbr, bool b);
void Handle(int event_nbr, int b, int c);
void Handle(int event_nbr);

/*
Event1<void, Root, bool> e;

#define template_argument_list_pause	<void, Root, bool>
#define template_argument_list_camera	<void, Camera, int*>

typedef std::map<events,void*> MapOfEventsType;

void *of = (*it).second;
Event1<void, Root, bool> e = *(Event1*) of;
Event1<void, Camera, int*> e = *(Event1*) of;

*/





} //namespace Event



