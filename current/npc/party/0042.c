#include <npc.h>
#include <ansi.h>
#include <cmd.h>

inherit OFFICER;

int get_char_picid()
{
	return 5205;
}
void do_welcome(string arg);

void create()
{
	set_name("场景传送人");
	set_2("talk",(["welcome":(:do_welcome:)]));
	setup();
}

void do_look(object who)
{
	string result;
	object me;
	
	me=this_object();
	result=sprintf(get_name()+":\n 你需要传送出去吗？我可以帮你送出这是非之地！\n");
	result+=sprintf(ESC "确定\ntalk %x# welcome.1\n",getoid(me));
	result+=sprintf(ESC "离开");
	send_user(who,"%c%c%w%s",':',3,get_char_picid(),result);
	
}

void do_welcome(string arg)
{
	object me=this_object();
	__FILE__->do_welcome2(me,arg);
}

void do_welcome2(object me, string arg)
{
	int flag;
	string result;
	object who;
	who=this_player();
	who->set_time("talk",0);
	flag=to_int(arg);
	
	switch(flag)
	{
		case 1:
			who->add_to_scene(80,276,163);
			who->delete("gumu");
			who->delele("map");
        		break;
	}	
}

