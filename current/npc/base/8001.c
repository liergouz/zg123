
// 自动生成：/make/npc/make0001
#include <ansi.h>
#include <npc.h>
#include <cmd.h>

inherit OFFICER;

// 函数：当铺老板
int is_banker() { return 1; }
void do_welcome(string arg);
// 函数：获取人物造型
int get_char_picid() { return 5301; }

// 函数：构造处理
void create()
{
        set_name("当铺老板");
        set_real_name("仓库管理员");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	string tmp= "";
	tmp += sprintf(ESC "领取《战国宝典》\ntalk %x# welcome.12\n",getoid(this_object()));
        send_user( who, "%c%c%w%s", ':', 3, get_char_picid(), 
                sprintf("%s：\n    "+"/quest/word"->get_normal_word(this_object())+"\n"
                        ESC "我想使用当铺\npawn %x# 1\n"
			ESC "我要扩充我的当铺\npawn expand %x# 0\n"
                        + tmp +
                        ESC "我只是随便看看\nCLOSE\n",get_name(), getoid(this_object()), getoid(this_object()) ) );	
	"/quest/help"->send_help_tips(who, 4);
}
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}
void do_welcome2( object me, string arg )
{
	int flag,i,size,p,amount;
	object who,*inv,item;
	
	who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag) {
        	case 12:
			if(objectp(item = "/quest/zg_dict"->want_an_zgdict(me,who))) {
				p = item->move(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%s",'!',"您获得了战国宝典。");
			}
        		break;
        }
}