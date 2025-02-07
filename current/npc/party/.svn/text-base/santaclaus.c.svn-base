#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#define CHRISTMAS "sys/party/christmas"

inherit OFFICER;
int iStart,iFinish;

// 函数：获取人物造型
int get_char_picid() { return 9972; }
void do_welcome(string arg);
// 函数：构造处理
void create()
{
        set_name("圣诞老人");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );

        setup();
	iStart = mktime(2007,1,4,0,0,0);	
	iFinish = mktime(2007,2,8,0,0,0);	

}

void do_look(object who)
{
        object me = this_object();
        
        if ( time() > iFinish )
        {
        	me->remove_from_scene();	
        	destruct(me);
        	return ;
        }
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    呵～呵～呵～呵～，虽然圣诞节已经过去了，但身为专业的圣诞老人我可不能就这样闲着。为了感谢大家对大话战国测试工作的支持，只要你的等级达到50级以上，从本月4日到7日这段时间内到我这里便可以领取丰厚的礼物。\n"ESC"那我就不客气收下拉～\ntalk %x# welcome.4\n"ESC"我还是下次再领取吧。",me->get_name(),getoid(me)));
//	CHRISTMAS->do_look(this_object(),who);
}


void do_welcome( string arg )
{
        object me = this_object();
        CHRISTMAS->do_welcome(me, arg);
}
