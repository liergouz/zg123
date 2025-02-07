
#include <npc.h>
#include <ansi.h>

inherit OFFICER;

void do_goto();
void do_recover();

// 函数：获取人物造型
int get_char_picid() { return 5109; }

// 函数：构造处理
void create()
{
        set_name("武师");
	set_real_name("凡伯");

        set_2( "talk", ([
                "go"    : (: do_goto :),
                "recover"    : (: do_recover :),
        ]));

        setup();
}

// 函数：对话处理
void do_look( object who )
{
        more_look_menu( who, get_name() + "：\n这位" + NPC_RANK_D->get_respect(who) + "想去比武场找人切磋切磋吗？\n"
                ESC "去比武场。\n" + sprintf( "talk %x# go\n", getoid( this_object() ) ) +
                ESC "请帮我恢复。\n" + sprintf( "talk %x# recover\n", getoid( this_object() ) ) +
                ESC "离开。\nCLOSE\n" );
}

// 函数：移动处理
void do_goto()
{
        object who;
        int p, z, x, y;

        who = this_player();

        if( p = get_jumpin(885, 1) )
        {
        	x = 80;  y = 60; z = 885;
        	if( p = get_valid_xy( z, x + random(40) - 20, y + random(40) - 20, IS_CHAR_BLOCK ) )
        	{
	                write_user( who, get_name() + "说道：“在比武场切磋是不会死亡的，放心试试吧！”" );
		                
	                who->add_to_scene( z, p / 1000, p % 1000, get_d(who) );
		}	               
        }
}

// 函数：补血处理
void do_recover()
{
        object who;
        int hp, mp, yuan, cash;
	string result;
        who = this_player();
	hp = who->get_max_hp() - who->get_hp();
	mp = who->get_max_mp() - who->get_mp();
	yuan = who->get_max_yuan() - who->get_yuan();
	cash = hp * 2 + mp * 2 + yuan * 2000;
	if (cash==0)
	{
		result =  "你不需要治疗！";
		send_user( who, "%c%s", '!', result ); 		
		return ;	
	}
	if (who->get_cash()<cash)
	{		
	        result =  get_name() + "：\n    你身上的钱好像不多，这样我没办法帮你恢复的。如果你真的是手头紧的话，建议去找尉迟老镖头或者王捕头帮忙。\n"
	        		ESC "关闭\nCLOSE\n";
	        send_user( who, "%c%c%w%s", ':', 3, 5109, result ); 		
	       	return ;
	}
	who->add_cash(-cash);
	who->set_hp(who->get_max_hp());
	who->set_mp(who->get_max_mp());
	who->set_yuan(who->get_max_yuan());
	result =  sprintf("你得到了治疗，花费了%d的金钱。", cash);
	send_user( who, "%c%s", '!', result ); 		
}