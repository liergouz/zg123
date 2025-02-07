#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>

inherit OFFICER;
// 函数：获取人物造型
int get_char_picid() { return 2113; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
        set_name("");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
}

void do_look(object who)
{
	int id = getoid(this_object());
	int iTime=time();

	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("一片杂草丛中隐藏着一只怪异的石头狮子。石头狮子的基座处隐隐透出阵阵阴风，似乎下面隐藏着一条神秘的通道。你确定要移开狮子，进入下面的通道吗？\n"ESC"进入通道\ntalk %x# welcome.1\n"ESC"离开",id));
	
}


void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag, p,iTime,i,size;
       	object who, item;
       	string name,*nTmp,tmp;
	mixed *mxTime;  
	  

        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
   		who->add_to_scene(804,32,44,get_d(who), 40971, 0, 40971, 0 );
        	break;

	}

}

