
// 自动生成：/make/npc/make8010

#include <npc.h>
#include <city.h>
#include <task.h>
#include <ansi.h>

#define GUARDER_D       "/inh/city/guarder"

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 5209; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
        set_name("魏国守卫");
        set_city_name("魏国");
        set_2( "talk", ([
                "welcome"	: (: do_welcome :),
        ]) );
//        set("level",84);
//        set("legend",({32*28+23}));
 	set("mpLegend",([80:({32*28+23})]));
 	set("mpLegend2",([80:({32*28+25})]));
        setup();
}

string get_master() { return CITY_WEI->get_master(); }
string get_master_2() { return CITY_WEI->get_master_2(); }
string get_master_3() { return CITY_WEI->get_master_3(); }

void do_look( object who )
{ 
	string tmp="";
	object me = this_object();
	if ( (who->get_level() >= 80 && !who->get_legend(TASK_28,23)) || (who->get_legend(TASK_28,23) && !who->get_legend(TASK_28,25)))
	{
		tmp += sprintf(ESC HIY "古墓里的玉\ntalk %x# welcome.1\n",getoid(me));
	}
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s：\n    "+"/quest/word"->get_country_word(me) + "\n"ESC"对话\ntalk %x# welcome.99\n",get_name(),getoid(me)) +
		tmp +
		ESC"离开");
	else
		GUARDER_D->do_look_3( who, me ); 
	
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who,item,obj;  
        string cmd1;
       	string *nTmp,tmp;     
           
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
 	case 1:
        	if ( who->get_level() >=80 && !who->get_legend(TASK_28,23) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    嘿嘿，你知道我是干什么的吗，知道吗，不知道吧，你真的觉得你知道吗，你知道你知道的是正确的吗？你说正确就是正确，正确的怎么还有人不相信呢，不相信的怎么说是正确的呢，哈哈哈，实话告诉你吧，我祖传三代是一个伟大的风水宝物收藏者，这个风水的意思呢，就是偶们的幌子就是风水先生，宝物收藏呢，就是把别人放到地里面没用什么用的宝物收藏起来，使它能够得到更好的保管和体现更大的经济价值，这个职业伟大吧，可别啧啧，盗墓者只不过是那些不知道内情的无知人们一个通俗的叫法，类似于我小时候狗狗的小名……啊，我说什么来者，对了，我最近得到一个可靠消息，将军古墓中又有人不知珍惜地将一块玉质绝佳的古玉遗忘在哪里了，真是暴殓天物 ，我作为风水宝物收藏者绝对不能任由这种破坏发生，你能够帮我前去取来它吗，真是多谢你了……听我说了这么多。\n"ESC"接受任务\ntalk %x# welcome.2\n"ESC"离开", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_28,23) && !who->get_legend(TASK_28,24) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    唉，看来你还不是一个专业的盗墓者，要多多训练才是！\n"ESC"离开", me->get_name()));
		else if ( who->get_legend(TASK_28,24) && !who->get_legend(TASK_28,25) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    太好了，我决定高价收购你的这块玉！\n"ESC"完成任务\ntalk %x# welcome.3\n"ESC"离开", me->get_name(),getoid(me)));
        	break;
	case 2:
        	if( who->get_level() >=80 && !who->get_legend(TASK_28,23) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_28,23);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"魏国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,30,"古墓里的玉" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"古墓里的玉");
        	}
        	break;       
        case 3:
        	if ( who->get_legend(TASK_28,24) && !who->get_legend(TASK_28,25) )
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"古玉",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_28,25);
			who->add_exp(47000);
			who->add_potential(690);
			who->add_cash(47000);
			send_user(who,"%c%s",';',"古墓里的玉 经验 47000 潜能 690 金钱 47000");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,30,"" );
        	}
        	break;  
        case 99:
        	GUARDER_D->do_look_3( who, me ); 
        	break;     
        }
}