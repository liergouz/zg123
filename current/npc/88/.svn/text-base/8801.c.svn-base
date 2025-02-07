#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <skill.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 0954; }
void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("小精怪");
        set_city_name("周国");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));  
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	object me = this_object();
	int id=getoid(me);
	string cTmp;
	
	cTmp = who->get_2("changping.country");
	if ( cTmp == get_city_name() )
		send_user(who,"%c%s",':',sprintf( "%s：\n    我是张果老遣派来的小精怪，你要回到周国吗？我可以送你回去。\n"
			ESC"离开长平之战\ntalk %x# welcome.3\n"
			ESC"离开", get_name(),id ) 
				);
	else
		send_user(who,"%c%s",':',sprintf( "%s：\n    我只负责送%s的战士回去，其他的我不管。\n"
			ESC"离开", get_name(),get_city_name()) 
				);
	
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p,z,level,x,y;
        object who,item,obj;  
        string cmd1;
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 3:
        	if( p = get_valid_xy(80, 243, 157, IS_CHAR_BLOCK) )
	        {
	                x = p/1000, y = p % 1000;
	                who->add_to_scene(80, x, y, 3);
	                CHAR_CHAR_D->init_loop_perform(who);
	                if ( who->get_2("changping.country") == "秦国" )
				send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9005, 1, OVER_BODY, PF_STOP );
			else
				send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9006, 1, OVER_BODY, PF_STOP );

	        }
        	break;

        }
}