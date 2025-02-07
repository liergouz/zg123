
#include <npc.h>
#include <ansi.h>
#include <city.h>
#include <effect.h>

inherit OFFICER;
inherit SAVE_F;
//inherit "/inh/char/group";

void do_info( string arg );

// 函数：获取人物造型
int get_char_picid() { return 0701; }

// 函数：构造处理
void create()
{
        object me = this_object();
        int time;        
        
        set_name( "传送石虎" );

        set_2( "talk", ([
                "info"          : (: do_info :),
        ]) );

        setup();
}

void do_look( object me ) 
{ 
	object who = this_object();
	string result;
	result = sprintf("%s：\n    你确定要离开%s的帮派院落吗？\n", who->get_name(), who->get_org_name());
	result += sprintf(ESC"确定\ntalk %x# info\n", getoid(who));
	result += sprintf(ESC"取消\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

void do_info( string arg ) 
{ 
	object me = this_player();
	object who = this_object();
	object npc, orgnpc;
	string city;
	int z, x, y, p;
	orgnpc = who->get("orgnpc");
	if (!orgnpc) return;
	city = orgnpc->get_city_name();
	switch(city)
	{
	case "齐国":
		z = 10; x = 95; y = 153;
		break;
	case "韩国":
		z = 20; x = 183, y = 89;
		break;
	case "赵国":
		z = 30, x = 191, y = 85;
		break;
	case "魏国":
		z = 40, x = 325, y = 151;
		break;
	case "秦国":
		z = 50, x = 91, y = 181;
		break;
	case "楚国":
		z = 60, x = 185, y = 228;
		break;
	default:
		z = 70, x = 212, y = 243;
		break;
	}
        if(   ( npc = me->get_2("orgtask2.npc") )    // 运镖人物
        &&      npc->get_owner() == me
        &&      inside_screen_2(me, npc) )
                npc->add_to_scene(z, x, y, 3);	
	me->add_to_scene(z, x, y, 3);
	me->set_2("jiguan.z", 0);
	me->set_2("jiguan.x", 0);
	me->set_2("jiguan.y", 0);		
}